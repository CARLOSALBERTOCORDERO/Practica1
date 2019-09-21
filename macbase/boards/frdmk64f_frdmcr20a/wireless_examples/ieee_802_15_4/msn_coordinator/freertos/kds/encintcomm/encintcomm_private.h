/*============================================================================*/
/*                        Aurora Carlos Jose Group                            */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %encintcomm_private.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      CCORDERO %
* %date_created:    Wed Sep 11 03:47:00 2019 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 11/09/2019  | Sw Developer                  | Carlos Cordero   */
/* Integration under Continuous CM                                            */
/*============================================================================*/


#ifndef ENCINTCOMM_ENCINTCOMM_PRIVATE_H_
#define ENCINTCOMM_ENCINTCOMM_PRIVATE_H_


/* Includes */
/* -------- */
#include "fsl_os_abstraction.h"
#include "aes.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/
/* Declaration of exported constants                */
/*==================================================*/
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/
/* Definition of RAM variables                          */
/*======================================================*/
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/
/* close variable declaration sections                  */
/*======================================================*/

/* Exported functions prototypes and macros */
/* ---------------------------------------- */
extern uint8_t encintcomm_simetricEncription(struct AES_ctx* ctx, uint8_t* buf, uint8_t length);
extern uint16_t encintcomm_CRC32(const uint8_t * inputArray,const uint8_t arrayLength, uint8_t * result,const uint8_t resultLength);

/* Functions prototypes */


/* Functions macros */


/* Exported defines */
#define ENCINTCOMM_CRC_32_POLYNOM 0x04C11DB7u
#define ENCINTCOMM_OFFSET_INDEX 4u
#define ENCINTCOMM_CRC_BYTE_SIZE 4u
#define ENCINTCOMM_OVERFLOW_MASK 0x100u
#define ENCINTCOMM_THREE_BYTE_SHIFTING 3u
#define ENCINTCOMM_LESS_SIGNIFICANT_BYTE 0xFFu
#define ENCINTCOMM_BYTE_TO_BIT 8u
#define ENCINTCOMM_SHIFTING_LIMIT 24u


#endif /* ENCINTCOMM_ENCINTCOMM_PRIVATE_H_ */
