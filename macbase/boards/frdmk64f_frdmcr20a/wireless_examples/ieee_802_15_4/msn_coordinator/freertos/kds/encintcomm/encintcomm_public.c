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

OSA_TASK_DEFINE(encintcomm_task, gMainThreadPriority_c-1, 1, gMainThreadStackSize_c, 0);

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
    OSA_TaskCreate(OSA_TASK(encintcomm_task), NULL);
    encintcomm_setState(encintcommStateInit);
    (void)mac_init(encript_addr);
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

