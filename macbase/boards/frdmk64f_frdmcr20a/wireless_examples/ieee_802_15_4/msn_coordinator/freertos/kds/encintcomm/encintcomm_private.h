/*
 * encintcomm_private.h
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */

#ifndef ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#define ENCINTCOMM_ENCINTCOMM_PRIVATE_H_

typedef enum
{
    encintcommStateInit = 0,
    encintcommStateReady
}encintcommStates_en_T;

extern void encintcomm_task(void* argument);
extern void encintcomm_setState(const encintcommStates_en_T inencintcommStates);


#endif /* ENCINTCOMM_ENCINTCOMM_PRIVATE_H_ */
