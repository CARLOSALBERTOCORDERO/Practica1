/*============================================================================*/
/*                        Aurora Carlos Jose Group                            */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %encintcomm_public.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      CCORDERO %
* %date_created:    Wed Sep 11 03:47:00 2019 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 11/09/2019  | Sw Developer                  | Carlos Cordero   */
/* Integration under Continuous CM                                            */
/*============================================================================*/

/* Includes */
/* -------- */
#include "encintcomm_public.h"
#include "encintcomm_private.h"
#include "ieee802p15p4_wrapper.h"
#include "fsl_os_abstraction.h"
#include "aes.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/
/* Definition of constants                          */
/*==================================================*/
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/
/* Definition of RAM variables                          */
/*======================================================*/
/* BYTE RAM variables */


/* WORD RAM variables */
static struct AES_ctx aes_ctx;
static const uint8_t aes_key_default[KEY_SIZE_16] = {0x1, 0x2,0x3, 0x4,0x5, 0x6,0x7, 0x8,0x9, 0xA,0x1, 0x2,0x3, 0x4,0x5, 0x6};

/* LONG and STRUCTURE RAM variables */
static encintcommStates_en_T encintcommStates_en = encintcommStateUndef;

/*======================================================*/
/* close variable declaration sections                  */
/*======================================================*/

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Private functions */
/* ----------------- */

/* Exported functions */
/* ------------------ */
/*FUNCTION*********************************************************************
 *
 * Function Name :  encript_init
 * Description   :  Initilizes the communication and lower drivers.
 *                  This is a blocking function.
 *
 * Params: encript_addr - Pointer to 4 bytes array that contains the MAC
 *                        address.
 *
 * Return: uint8_t: 0 - success.
 *
 *END************************************************************************/
extern uint8_t encintcomm_init(uint8_t* encript_addr)
{
    uint8_t returnVal = 1u;
    if(encintcommStateInitCtx == encintcommStates_en)
    {
        encintcommStates_en = encintcommStateReady;
        returnVal = (uint8_t)mac_init(encript_addr);
    }
    return returnVal;
}

/*FUNCTION*********************************************************************
 *
 * Function Name :  encripCtx_init
 * Description   :  Initilize encryption context with default key.
 *
 * Params: void
 *
 * Return: void.
 *
 *END************************************************************************/
extern void encipCtx_init(void)
{
    encintcommStates_en = encintcommStateInitCtx;
    AES_init_ctx(&aes_ctx, &aes_key_default[0]);
}

/*FUNCTION*********************************************************************
 *
 * Function Name :  encripCtx_init
 * Description   :  Initilize encryption context with user key.
 *
 * Params: encript_addr - Pointer to 4 bytes array that contains the MAC
 *                        address.
 *
 * Return: uint8_t: 0 - success.
 *
 *END************************************************************************/
extern void encipCtxUsr_init(encintcommkey_st_T* encintcommkey_st)
{
    encintcommStates_en = encintcommStateInitCtx;
    AES_init_ctx(&aes_ctx, &(encintcommkey_st->key[0]));
}



/*FUNCTION*********************************************************************
 *
 * Function Name :  encrintcomm_connect
 * Description   :  Connects the MAC layer.
 *
 * Params: channel  - Channel to start the network (11-26).
 *         pan_id   - Id of the network
 *         evt_hdlr - Pointer to a callback function that will be called by the
 *                    mac wrapper to signal events on the MAC layer to the
 *                    calling layer. The events received by this callback are:
 *                    * Data reception.
 *                    * Data Transmission confirm.
 *                    * Network Connection.
 *                    * Network Disconnections
 *
 * Return: int: 0 - success.
 *END************************************************************************/
extern uint8_t encintcomm_connect(uint8_t channel, uint16_t pan_id, void (*evt_hdlr)(void*))
{
    mac_connect(channel, pan_id, evt_hdlr);
    return 0;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : mac_transmit
 * Description   : Commands the node to send data to another node over a
 *                 ieee802.15.4 network.
 *                 mac_connect() has to be called before hand.
 *                 This is a non-blocking function. The result of the
 *                 transmission request will be received in a call to the event
 *                 handler callback (evt_hdlr).
 *                 The information will be encrypted and CRC32 will be added to
 *                 the end of the message.
 *                 IMPORTAN NOTE: The maximum transmission data is 60.
 *
 *
 * Params: dest_address  - Address of the data's destination node.
 *         data   - Pointer to the data array to transmit
 *         data_len - Size in bytes of the data array.
 *
 * Return: int: 0 - success.
 *
 *END**************************************************************************/
extern uint8_t encintcomm_transmit(uint16_t dest_address, uint8_t* data, uint8_t data_len)
{
    uint8_t returnVal = 0;
    uint8_t index = 0;
    int8_t auxIndex = 0;
    uint8_t crcResult[ENCINTCOMM_CRC_BYTE_SIZE] = {0};
    /* Encrypt */
    returnVal = encintcomm_simetricEncription(&aes_ctx, data, data_len);
    /* Calculate and add CRC */
    returnVal |= encintcomm_CRC32(data, data_len, (uint8_t *)&crcResult[0], ENCINTCOMM_CRC_BYTE_SIZE);
    for(index = 0;index < ENCINTCOMM_CRC_BYTE_SIZE; index++)
    {
        auxIndex = index + data_len;
        data[auxIndex] = crcResult[index];
    }
    data_len += ENCINTCOMM_CRC_BYTE_SIZE;
    returnVal |= (uint8_t)mac_transmit(dest_address, data, data_len);
    return returnVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : mac_transmit
 * Description   : This function calculates de CRC of the message received to
 *                 check any error in the communication, then it decipher the
 *                 message using AES128. Finally, the data is loaded, the
 *                 data_len adjusted and the status reported.
 *
 *
 * Params: data - Pointer to the data received.
 *         data_len - Pointer to the length of the date received.
 *         status - Out value of the status.
 *
 * Return: int: 0 - success.
 *
 *END**************************************************************************/
extern uint8_t encintcomm_received( uint8_t* data, uint8_t * data_len, uint8_t * status)
{
    uint8_t returnVal = 0u;
    uint8_t crcResult[ENCINTCOMM_CRC_BYTE_SIZE] = {0u};
    uint8_t crcReceived[ENCINTCOMM_CRC_BYTE_SIZE] = {0u};
    uint8_t index = 0u;
    int8_t auxIndex = 0u;
    int8_t auxDataLength = 0u;
    bool_t crcCorrect = TRUE;

    /* Take CRC from received data and remove it */
    for(index = 0; index <ENCINTCOMM_CRC_BYTE_SIZE; index++)
    {
        auxIndex = *data_len - ENCINTCOMM_CRC_BYTE_SIZE + index;
        crcReceived[index] = data[auxIndex];
        data[auxIndex] = 0u;
    }
    auxDataLength = *data_len - ENCINTCOMM_CRC_BYTE_SIZE;
    /* Calculate CRC */
    returnVal |= encintcomm_CRC32(data, auxDataLength, (uint8_t *)&crcResult[0], ENCINTCOMM_CRC_BYTE_SIZE);
    /* Compare CRC */
    for(index = 0; index <ENCINTCOMM_CRC_BYTE_SIZE; index++)
    {
        if(crcReceived[index] != crcResult[index])
        {
            crcCorrect = FALSE;
        }
    }
    /* Des-encrypt */
    returnVal |= encintcomm_simetricEncription(&aes_ctx, data, auxDataLength);
    /*Load length and status */
    *data_len = auxDataLength;
    if(FALSE == crcCorrect)
    {
        *status = 0x08;
    }
    if(0 != returnVal)
    {
        *status |= 0x80;
    }
    return returnVal;
}
