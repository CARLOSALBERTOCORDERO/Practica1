/*!

 */

/*! *********************************************************************************
 *************************************************************************************
 * Include
 *************************************************************************************
 ********************************************************************************** */
#include "ieee802p15p4_wrapper.h"

/* Drv */
#include "LED.h"
#include "Keyboard.h"

/* Fwk */
#include "SerialManager.h"
#include "TimersManager.h"
#include "FunctionLib.h"
#include "MemManager.h"
#include "SecLib.h"

/* KSDK */
#include "board.h"
#include "fsl_os_abstraction.h"

#include "C:\SandBoxes\macwrapper_ACJ\macbase\boards\frdmk64f_frdmcr20a\wireless_examples\ieee_802_15_4\msn_coordinator\freertos\kds\encintcomm\encintcomm.h"

/************************************************************************************
 *************************************************************************************
 * Private macros
 *************************************************************************************
 ************************************************************************************/
enum
{
	stateInit,
	waitConnectionResponse,
	stateConnected
};

#define mDefaultValueOfDataLen_c               20
#define gMessageMarkCR_c   0x0D

/* Events */
#define gAppEvtDummyEvent_c             (1 << 0)
#define gAppEvtRxFromComm_c             (1 << 1)
#define gAppEvtMacManagement_c			(1 << 2)
#define gAppEvtMacData_c				(1 << 3)
#define gAppEvtButton_c					(1 << 4)

enum
{
  errorNoError,
  errorWrongConfirm,
  errorNotSuccessful,
  errorNoMessage,
  errorAllocFailed,
  errorInvalidParameter,
  errorNoScanResults
};

/************************************************************************************
 *************************************************************************************
 * Private prototypes
 *************************************************************************************
 ************************************************************************************/
static void    App_CommRxCallBack(void*);
static void    App_HandleKeys(key_event_t events);
static uint16_t App_CRC(uint8_t * inputArray, uint8_t arrayLength, uint32_t * result);

void App_init( void );
void AppThread (uint32_t argument);

/************************************************************************************
 *************************************************************************************
 * Private memory declarations
 *************************************************************************************
 ************************************************************************************/

static uint16_t mShortAddress = 0xFFFF;
static uint16_t mPanId = 0xFFFF;
static uint16_t mDestinationAddress = 0xFFFF;
static uint8_t  mChannel = 0xFF;
static osaEventId_t mAppEvent;
static bool_t node_connected = FALSE;
static bool_t node_is_coordinator = FALSE;
static uint8_t mInterfaceId;

/* The current state of the applications state machine */
static uint8_t gState;

static int mlme_event = 0;
static int mcps_event = 0;

static char received_data[128] = {0};
static uint16_t received_data_src = 0xFFFF;
static uint8_t received_data_len = 0;
static uint8_t button_event = 0;

uint8_t mac_address[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01};

static uint8_t maCommDataBuffer[64] = {0};

/************************************************************************************
 *************************************************************************************
 * Public functions
 *************************************************************************************
 ************************************************************************************/

/*! *********************************************************************************
 * \brief  This is the first task created by the OS. This task will initialize
 *         the system
 *
 * \param[in]  argument
 *
 * \return  None.
 *
 * \pre
 *
 * \post
 *
 * \remarks
 *
 ********************************************************************************** */
void main_task(uint32_t param)
{
	static uint8_t initialized = FALSE;

	if( !initialized )
	{
		initialized = TRUE;
		hardware_init();

		MEM_Init();
		TMR_Init();
		LED_Init();
		SecLib_Init();
		SerialManager_Init();
		App_init();
	}

	/* Call application task */
	AppThread( param );
}

/*****************************************************************************
 * Initialization function for the App Task. This is called during
 * initialization and should contain any application specific initialization
 * (ie. hardware initialization/setup, table initialization, power up
 * notification.
 *
 * Interface assumptions: None
 *
 * Return value: None
 *
 *****************************************************************************/
void App_init(void)
{

	mAppEvent = OSA_EventCreate(TRUE);
	/* The initial application state */
	gState = stateInit;

	/* Register keyboard callback function */
	KBD_Init(App_HandleKeys);

	/* Initialize the serial terminal interface so that we can print out status messages */
	Serial_InitInterface(&mInterfaceId, APP_SERIAL_INTERFACE_TYPE, APP_SERIAL_INTERFACE_INSTANCE);
	Serial_SetBaudRate(mInterfaceId, gUARTBaudRate57600_c);
	Serial_SetRxCallBack(mInterfaceId, App_CommRxCallBack, NULL);

	/*signal app ready*/
	LED_StartSerialFlash(LED1);

	Serial_Print(mInterfaceId,"\n\rPress SW2 on the CR20 board to change the MAC address, SW1 to start the node initialization and connection\n\r", gAllowToBlock_d);
}

/*****************************************************************************
 * Handler for events from the MAC wrapper -- THIS IS A CALLBACK FUNCTION --
 *****************************************************************************/
void mac_events_handler(void* evt_par)
{
	mac_event_data_t* mac_evt_data = (mac_event_data_t* ) evt_par;

	switch(mac_evt_data->mac_event_type) {
	case mac_management_event_c:
		switch(mac_evt_data->evt_data.management_event_data->msgType){
		case gMlmeAssociateCnf_c:
			/* Network found, started as End Device */
			mShortAddress = mac_evt_data->evt_data.management_event_data->msgData.associateCnf.assocShortAddress;
			node_connected = TRUE;
			break;
		case gMlmeStartCnf_c:
			/* No network found started a new network as Coordinator */
			mShortAddress = 0;
			node_connected = TRUE;
			node_is_coordinator = TRUE;
			break;
		default:
			mlme_event = mac_evt_data->evt_data.management_event_data->msgType;
			break;
		}
		OSA_EventSet(mAppEvent, gAppEvtMacManagement_c);
		break;
	case mac_data_event_c:
		switch(mac_evt_data->evt_data.data_event_data->msgType){
		case gMcpsDataInd_c:
			FLib_MemSet(received_data, 0, sizeof(received_data));
			FLib_MemCpy( received_data, mac_evt_data->evt_data.data_event_data->msgData.dataInd.pMsdu, mac_evt_data->evt_data.data_event_data->msgData.dataInd.msduLength);
			received_data_len =  mac_evt_data->evt_data.data_event_data->msgData.dataInd.msduLength;
			FLib_MemCpy(&received_data_src, &(mac_evt_data->evt_data.data_event_data->msgData.dataInd.srcAddr), 2);
			break;
		default:
			received_data_len = 0;
			received_data_src = 0xFFFF;
			mcps_event = mac_evt_data->evt_data.data_event_data->msgType;
			break;
		}
		OSA_EventSet(mAppEvent, gAppEvtMacData_c);
		break;

	default:
		break;
	}
}

/*****************************************************************************
 * The AppTask(event_t events) function is the applicantion main loop and
 * will process any incoming event. Events include timers, messages and any
 * other user defined events.
 *
 * Interface assumptions:
 *     None
 *
 * Return value:
 *     None
 *****************************************************************************/
void AppThread(uint32_t argument)
{ 
	osaEventFlags_t ev;
	/* Stores the error/success code returned by some functions. */
    static uint8_t mCounter = 0;

	while(1)
	{
		OSA_EventWait(mAppEvent, osaEventFlagsAll_c, FALSE, osaWaitForever_c, &ev);

		switch(gState)
		{
		case stateInit:
			if(ev & gAppEvtButton_c){
				if(button_event == gKBD_EventSW3_c) {
					Serial_Print(mInterfaceId,"MAC address: ", gAllowToBlock_d);
					for(int i = 0; i<8; i++) {
						mac_address[i]++;
						Serial_PrintHex(mInterfaceId,(uint8_t*)&mac_address[i], 1, 0);
					}
					Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
				}
				if(button_event == gKBD_EventSW4_c) {
					/*Initialize the MAC Wrapper*/
					LED_StopFlashingAllLeds();
					Serial_Print(mInterfaceId,"Initializing MAC.\n\r", gAllowToBlock_d);
					Serial_Print(mInterfaceId,"Initializing ENCINT_COMM.\n\r", gAllowToBlock_d);
					encrintcomm_init(mac_address);
					Serial_Print(mInterfaceId,"Node is initialized and ready.\n\r", gAllowToBlock_d);
					/* Goto Energy Detection state. */
					mPanId = 0xC0C0;
					mChannel = gLogicalChannel11_c;
					Serial_Print(mInterfaceId,"Starting connection, this can take several seconds.\n\r", gAllowToBlock_d);
					Serial_Print(mInterfaceId,"The communication will be encripted.\n\r", gAllowToBlock_d);
					encrintcomm_connect(mChannel, mPanId, mac_events_handler);
					gState = waitConnectionResponse;
				}
			}


			break;

		case waitConnectionResponse:
			/* Handle connection response */
			if(node_connected){
				Serial_Print(mInterfaceId," Node Connected as ", gAllowToBlock_d);
				if(node_is_coordinator){
					Serial_Print(mInterfaceId,"Coordinator with short address: ", gAllowToBlock_d);
				}
				else {
					Serial_Print(mInterfaceId,"End device with short address: ", gAllowToBlock_d);
				}
				Serial_PrintHex(mInterfaceId,(uint8_t*)&mShortAddress, 2, 0);
				Serial_Print(mInterfaceId," Pan Id: ", gAllowToBlock_d);
				Serial_PrintHex(mInterfaceId,(uint8_t*)&mPanId, 2, 0);
				Serial_Print(mInterfaceId," Channel: ", gAllowToBlock_d);
				Serial_PrintHex(mInterfaceId,(uint8_t*)&mChannel, 1, 0);
				Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);

				gState = stateConnected;
				OSA_EventSet(mAppEvent, gAppEvtDummyEvent_c);
			}

			break;

		case stateConnected:
			/* Handle events from the UART */
			if (ev & gAppEvtRxFromComm_c)
			{
				uint16_t count;
				unsigned char received_byte = 0;
				(void)Serial_GetByteFromRxBuffer(mInterfaceId, &received_byte, &count);
				if((received_byte >= ' ') && (received_byte <= '~')) {
					maCommDataBuffer[mCounter++] = received_byte;
				}

				if((mCounter >= 64) || (received_byte == '\r')){
				    uint32_t result = 0;
				    App_CRC(&maCommDataBuffer[0], 64, &result);
					mac_transmit(mDestinationAddress, maCommDataBuffer, mCounter);
					FLib_MemSet(maCommDataBuffer, 0, 64);
					mCounter = 0;
				}
			}

			/* Handle MAC management events */
			if(ev & gAppEvtMacManagement_c){
				Serial_Print(mInterfaceId,"Network management event: ", gAllowToBlock_d);
				Serial_PrintHex(mInterfaceId,(uint8_t*)&mlme_event, 4, 0);
				Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
			}

			/* Handle MAC data events */
			if(ev & gAppEvtMacData_c){
				if(received_data_len){
					Serial_Print(mInterfaceId,"Message from ", gAllowToBlock_d);
					Serial_PrintHex(mInterfaceId,(uint8_t*)&received_data_src, 2, 0);
					Serial_Print(mInterfaceId," : ", gAllowToBlock_d);
					Serial_Print(mInterfaceId, received_data, gAllowToBlock_d);
					Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
				}
				else {
					Serial_Print(mInterfaceId,"Network data event: ", gAllowToBlock_d);
					Serial_PrintHex(mInterfaceId,(uint8_t*)&mcps_event, 4, 0);
					Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
				}

			}

			/* Handle button events */
			if(ev & gAppEvtButton_c){
				if(button_event == gKBD_EventSW3_c) {
					Serial_Print(mInterfaceId,"Destination address: ", gAllowToBlock_d);
					mDestinationAddress++;
					Serial_PrintHex(mInterfaceId,(uint8_t*)&mDestinationAddress, 2, 0);
					Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
				}
				if(button_event == gKBD_EventSW4_c) {
					Serial_Print(mInterfaceId,"Destination address: ", gAllowToBlock_d);
					mDestinationAddress--;
					Serial_PrintHex(mInterfaceId,(uint8_t*)&mDestinationAddress, 2, 0);
					Serial_Print(mInterfaceId,"\r\n", gAllowToBlock_d);
				}
			}
			break;
		} /* end switch*/

	}
}

static uint16_t App_CRC(uint8_t * inputArray, uint8_t arrayLength, uint32_t * result)
{
    const uint32_t gCRCPolym_u8 = 0x04C11DB7u;
    uint8_t index = 0;
    uint8_t auxIndex = 0;
    uint8_t charStartIndex = 0u;
    uint8_t shiftCounter = 0;

    uint8_t crcByteShifting = 0;
    uint8_t zerosIndex = 4;
    bool_t algorithEnd = FALSE;
    uint8_t zerosExtendedArray[68] = {0};
    int16_t shiftLeftAux = 0u;
    uint16_t bitFindDataShifted = 0u;
    uint16_t shiftCounterLimit = 0;
    uint32_t resultCRC = 0;
    uint32_t crcResultAux = 0u;
    uint32_t crcByteAux = 0u;

    /* Add zeros to the message */
    for(index = 0; index < arrayLength; index++)
    {
        zerosExtendedArray[zerosIndex] = inputArray[index];
        zerosIndex++;
    }
    /*Start at the extended array end value*/
    /* Construct M& r'zeros*/
    index = sizeof(zerosExtendedArray)/sizeof(uint8_t);
    index--;
    charStartIndex = index;
    /*Find first byte with data */
    while((index > 0) && (0 == zerosExtendedArray[index]))
    {
        index--;
        charStartIndex = index;
    }
    /*Get the maximum number of shiftings*/
    shiftCounterLimit = charStartIndex * 8;
    shiftCounterLimit -= 24;
    /*Apply CRC algorithm*/
    shiftLeftAux = zerosExtendedArray[charStartIndex];
    while(shiftCounterLimit > shiftCounter)
    {
        bitFindDataShifted = 0;
        /*Find first bit in 1*/
        while((0u == bitFindDataShifted) && (shiftCounterLimit > shiftCounter))
        {
            shiftLeftAux = zerosExtendedArray[charStartIndex] << 1;
            bitFindDataShifted = shiftLeftAux & 0x100u;
            shiftCounter++;
            if(shiftCounterLimit <= shiftCounter)
            {
                algorithEnd = TRUE;
            }
            /*shift left all the array */
            for(index = charStartIndex; index > 0; index --)
            {
                zerosExtendedArray[index] <<= 1;
                auxIndex = index - 1;
                shiftLeftAux = zerosExtendedArray[auxIndex] << 1;
                shiftLeftAux &= 0x100;
                if(0 != shiftLeftAux)
                {
                    zerosExtendedArray[index] |= 0x1;
                }
            }
        }
        if((FALSE == algorithEnd) || ((TRUE == algorithEnd) && (0 != bitFindDataShifted)))
        {
            /*Apply CRC to Most significan 32b*/
            crcResultAux = 0u;
            /* Construct 32b with the array */
            for(index = 0; index < 4; index++)
            {
                auxIndex = charStartIndex - index;
                crcByteShifting = 3 - index;
                crcByteShifting *= 8;
                crcByteAux = zerosExtendedArray[auxIndex];
                crcByteAux <<= crcByteShifting;
                crcResultAux |= crcByteAux;
            }
            resultCRC = crcResultAux ^ gCRCPolym_u8;
            for(index = 0; index < 4; index++)
            {
                auxIndex = charStartIndex - index;
                crcByteShifting = 3 - index;
                crcByteShifting *= 8;
                crcByteAux = resultCRC;
                crcByteAux >>= crcByteShifting;
                zerosExtendedArray[auxIndex] = (uint8_t)(crcByteAux & 0xFF);
            }
        }
    }
    crcResultAux = 0u;
    /* Construct 32b with the array */
    for(index = 0; index < 4; index++)
    {
        auxIndex = charStartIndex - index;
        crcByteShifting = 3 - index;
        crcByteShifting *= 8;
        crcByteAux = zerosExtendedArray[auxIndex];
        crcByteAux <<= crcByteShifting;
        crcResultAux |= crcByteAux;
    }
    *result = crcResultAux;
}

/************************************************************************************
 *************************************************************************************
 * Private functions
 *************************************************************************************
 ************************************************************************************/

/*****************************************************************************
 * App_CommRxCallBack
 *
 * This callback is triggered when a new byte is received over the serial terminal interface
 *
 *****************************************************************************/
static void App_CommRxCallBack(void *pData) 
{
	uint8_t pressedKey;
	uint16_t count;

	(void)pData;
	if(stateConnected == gState)
	{
		OSA_EventSet(mAppEvent, gAppEvtRxFromComm_c);
	}
	else
	{
		do{
			(void)Serial_GetByteFromRxBuffer(mInterfaceId, &pressedKey, &count);
		}while(count);
	}
}


/*****************************************************************************
 * The App_HandleKeys(key_event_t events) function can handle different
 * key events. It waits for user to push a button in order to start
 * the application.
 *
 * Interface assumptions:
 *     None
 *
 * Return value:
 *     None
 *****************************************************************************/
static void App_HandleKeys( key_event_t events )
{
	button_event = events;
	OSA_EventSet(mAppEvent, gAppEvtButton_c);
	switch ( button_event )
	{
	case gKBD_EventSW1_c:
	case gKBD_EventSW2_c:
	case gKBD_EventSW3_c:
	case gKBD_EventSW4_c:
	case gKBD_EventLongSW1_c:
	case gKBD_EventLongSW2_c:
	case gKBD_EventLongSW3_c:
	case gKBD_EventLongSW4_c:
	default:
		break;
	}
}
