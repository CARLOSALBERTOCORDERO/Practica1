/*
 * encintcomm_private.h
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */

#ifndef ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#define ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#include "fsl_os_abstraction.h"
#include "aes.h"



extern uint8_t encrintcomm_simetricEncription(struct AES_ctx* ctx, uint8_t* buf, uint32_t length);

#endif /* ENCINTCOMM_ENCINTCOMM_PRIVATE_H_ */
