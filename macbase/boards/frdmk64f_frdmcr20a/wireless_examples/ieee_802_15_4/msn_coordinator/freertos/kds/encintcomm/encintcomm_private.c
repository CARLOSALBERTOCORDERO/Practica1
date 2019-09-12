/*
 * encintcomm_private.c
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */


#include "encintcomm_private.h"


#define gencintcommEvtDummyEvent_c             (1 << 0)

static osaEventId_t mEncintcommEvent = NULL;

static encintcommStates_en_T encintcommStates_en = encintcommStateInit;

/**************************************************************
 *  Name                 : encintcomm_tast
 *  Description          : state machine of the encripting and
 *                         integrity communication
 *  Parameters           : [Output] argument(void*) callback arguments
 *  Return               : void
 *  Critical/explanation : [yes]
 **************************************************************/
extern void encintcomm_task(void* argument)
{
    osaEventFlags_t ev;
    while(1)
    {
        OSA_EventWait(mEncintcommEvent, osaEventFlagsAll_c, FALSE, osaWaitForever_c, &ev);

        switch(encintcommStates_en)
        {
            case encintcommStateInit:
                encintcommStates_en = encintcommStateReady;
                OSA_EventSet(mEncintcommEvent, gencintcommEvtDummyEvent_c);
                break;
            case encintcommStateReady:
                encintcommStates_en = encintcommStateReady;
                break;
            default:
                break;
        }
    }
}

extern void encintcomm_setState(const encintcommStates_en_T inencintcommStates)
{
    encintcommStates_en = inencintcommStates;
}

extern void encrintcomm_getEvent(osaEventId_t encintcommEvent)
{
    encintcommEvent = mEncintcommEvent;
}
