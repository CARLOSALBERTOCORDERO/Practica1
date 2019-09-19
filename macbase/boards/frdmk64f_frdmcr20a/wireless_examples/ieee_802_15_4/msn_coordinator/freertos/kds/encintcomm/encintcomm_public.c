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
static struct AES_ctx aes_ctx1;
static const uint8_t aes_key[KEY_SIZE_16] = {0x1, 0x2,0x3, 0x4,0x5, 0x6,0x7, 0x8,0x9, 0xA,0x1, 0x2,0x3, 0x4,0x5, 0x6};

/* LONG and STRUCTURE RAM variables */


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
 * Description   :  Initilizes the Ecription and CRC drivers.
 *                  This is a blocking function.
 *
 * Params: encript_addr - Pointer to 4 bytes array that contains the MAC
 *                        address.
 *
 * Return: uint8_t: 0 - success.
 *
 *END************************************************************************/
extern uint8_t encrintcomm_init(uint8_t* encript_addr)
{
    (void)mac_init(encript_addr);
}

extern void encripCtx_init(void)
{
    AES_init_ctx(&aes_ctx, &aes_key[0]);
    //AES_init_ctx(&aes_ctx1, &aes_key[0]);
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
extern uint8_t encrintcomm_connect(uint8_t channel, uint16_t pan_id, void (*evt_hdlr)(void*))
{
    mac_connect(channel, pan_id, evt_hdlr);
}



extern uint8_t encrintcomm_transmit(uint16_t dest_address, uint8_t* data, uint8_t data_len)
{

    encrintcomm_simetricEncription(&aes_ctx, data, data_len);
    mac_transmit(dest_address, data, data_len);
    //encrintcomm_simetricEncription(&aes_ctx1, data, data_len);
}

