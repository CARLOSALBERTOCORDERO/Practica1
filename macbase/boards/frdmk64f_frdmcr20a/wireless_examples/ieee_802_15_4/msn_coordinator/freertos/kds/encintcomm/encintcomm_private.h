/*
 * encintcomm_private.h
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */

#ifndef ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#define ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#include "fsl_os_abstraction.h"

typedef enum
{
    encintcommStateInit = 0,
    encintcommStateReady
}encintcommStates_en_T;

extern void encintcomm_task(void* argument);
extern void encintcomm_setState(const encintcommStates_en_T inencintcommStates);
extern void encrintcomm_getEvent(osaEventId_t encintcommEvent);


#endif /* ENCINTCOMM_ENCINTCOMM_PRIVATE_H_ */
