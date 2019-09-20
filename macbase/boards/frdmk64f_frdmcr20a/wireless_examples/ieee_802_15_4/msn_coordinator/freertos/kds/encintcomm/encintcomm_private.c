/*
 * encintcomm_private.c
 *
 *  Created on: 11/09/2019
 *      Author: CARLOS_CORDERO
 */


#include "encintcomm_private.h"
#include "aes.h"


static osaEventId_t mEncintcommEvent = NULL;




extern uint8_t encrintcomm_simetricEncription(struct AES_ctx* ctx, uint8_t* buf, uint32_t length)
{
    AES_CTR_xcrypt_buffer(ctx, buf, length);
}
