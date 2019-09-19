/*============================================================================*/
/*                        Aurora Carlos Jose Group                            */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %encintcomm_public.h%
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

#ifndef ENCINTCOMM_PUBLIC_H                      /* To avoid double inclusion */
#define ENCINTCOMM_PUBLIC_H

/* Includes */
/* -------- */
#include "EmbeddedTypes.h"


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

/* Functions prototypes */
extern uint8_t encrintcomm_init(uint8_t* encript_addr);
extern void encripCtx_init(void);
extern uint8_t encrintcomm_connect(uint8_t channel, uint16_t pan_id, void (*evt_hdlr)(void*));
extern uint8_t encrintcomm_transmit(uint16_t dest_address, uint8_t* data, uint8_t data_len);



/* Functions macros */


/* Exported defines */
#define KEY_SIZE_16 16

#endif /*ENCINTCOMM_PUBLIC_H*/
