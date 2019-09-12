/*
 * encintcomm_private.c
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */

#include "fsl_os_abstraction.h"
#include "encintcomm_private.h"


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
    while(1)
    {
        switch(encintcommStates_en)
        {
            case encintcommStateInit:
                break;
            case encintcommStateReady:
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
