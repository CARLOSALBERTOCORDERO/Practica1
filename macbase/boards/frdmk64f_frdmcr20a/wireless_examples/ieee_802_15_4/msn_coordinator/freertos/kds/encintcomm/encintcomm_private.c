/*============================================================================*/
/*                        Aurora Carlos Jose Group                            */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %encintcomm_private.c%
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
#include "encintcomm_private.h"
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
static uint8_t zerosExtendedArray[68] = {0};

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/
/* close variable declaration sections                  */
/*======================================================*/

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */


/* Exported functions */
/* ------------------ */
/*FUNCTION*********************************************************************
 *
 * Function Name :  encrintcomm_simetricEncription
 * Description   :  Apply encrypting to a frame of characters.
 *
 * Params: ctx(AES_ctx*) - Encryption context.
 *         buf(uint8_t) - Data
 *         length(uint8_t) - Data length
 *
 * Return: uint8_t: 0 - success.
 *
 *END************************************************************************/
extern uint8_t encintcomm_simetricEncription(struct AES_ctx* ctx, uint8_t* buf, uint8_t length)
{
    AES_CTR_xcrypt_buffer(ctx, buf, (uint32_t)length);
}

/*FUNCTION*********************************************************************
 *
 * Function Name :  encrintcomm_CRC32
 * Description   :  Apply CRC32 algorith to an array and provide another array
 *                  with the result.
 *
 * Params: inputArray(uint8_t*) - Input Array.
 *         arrayLength(uint8_t) - Input Array Length.
 *         result(uint32_t*) - Result Array.
 *         resultLength(uint8_t) - Result Array Length. Maximum value is 4
 *
 * Return: uint8_t: 0 - success.
 *
 *END************************************************************************/
extern uint16_t encintcomm_CRC32(const uint8_t * inputArray,const uint8_t arrayLength, uint32_t * result,const uint8_t resultLength)
{
    const uint32_t gCRCPolym_u8 = ENCINTCOMM_CRC_32_POLYNOM;
    uint8_t index = 0;
    uint8_t auxIndex = 0;
    uint8_t charStartIndex = 0u;
    uint8_t shiftCounter = 0;
    uint8_t crcByteShifting = 0;
    uint8_t zerosIndex = ENCINTCOMM_OFFSET_INDEX;
    bool_t algorithEnd = FALSE;
    int16_t shiftLeftAux = 0u;
    uint16_t bitFindDataShifted = 0u;
    uint16_t shiftCounterLimit = 0;
    uint32_t resultCRC = 0;
    uint32_t crcResultAux = 0u;
    uint32_t crcByteAux = 0u;

    /* Add zeros to the message */
    for(index = 0; index < arrayLength; index++)
    {
        zerosExtendedArray[zerosIndex] = inputArray[index];
        zerosIndex++;
    }
    /*Start at the extended array end value*/
    /* Construct M& r'zeros*/
    index = sizeof(zerosExtendedArray)/sizeof(uint8_t);
    index--;
    charStartIndex = index;
    /*Find first byte with data */
    while((index > 0) && (0 == zerosExtendedArray[index]))
    {
        index--;
        charStartIndex = index;
    }
    /*Get the maximum number of shiftings*/
    shiftCounterLimit = charStartIndex * ENCINTCOMM_BYTE_TO_BIT;
    shiftCounterLimit -= ENCINTCOMM_SHIFTING_LIMIT;
    /*Apply CRC algorithm*/
    shiftLeftAux = zerosExtendedArray[charStartIndex];
    while(shiftCounterLimit > shiftCounter)
    {
        bitFindDataShifted = 0;
        /*Find first bit in 1*/
        while((0u == bitFindDataShifted) && (shiftCounterLimit > shiftCounter))
        {
            shiftLeftAux = zerosExtendedArray[charStartIndex] << 1;
            bitFindDataShifted = shiftLeftAux & 0x100u;
            shiftCounter++;
            if(shiftCounterLimit <= shiftCounter)
            {
                algorithEnd = TRUE;
            }
            /*shift left all the array */
            for(index = charStartIndex; index > 0; index --)
            {
                zerosExtendedArray[index] <<= 1;
                auxIndex = index - 1;
                shiftLeftAux = zerosExtendedArray[auxIndex] << 1;
                shiftLeftAux &= ENCINTCOMM_OVERFLOW_MASK;
                if(0 != shiftLeftAux)
                {
                    zerosExtendedArray[index] |= 0x1;
                }
            }
        }
        if((FALSE == algorithEnd) || ((TRUE == algorithEnd) && (0 != bitFindDataShifted)))
        {
            /*Apply CRC to Most significan 32b*/
            crcResultAux = 0u;
            /* Construct 32b with the array */
            for(index = 0; index < ENCINTCOMM_OFFSET_INDEX; index++)
            {
                auxIndex = charStartIndex - index;
                crcByteShifting = ENCINTCOMM_THREE_BYTE_SHIFTING - index;
                crcByteShifting <<= ENCINTCOMM_THREE_BYTE_SHIFTING;
                crcByteAux = zerosExtendedArray[auxIndex];
                crcByteAux <<= crcByteShifting;
                crcResultAux |= crcByteAux;
            }
            resultCRC = crcResultAux ^ gCRCPolym_u8;
            for(index = 0; index < ENCINTCOMM_OFFSET_INDEX; index++)
            {
                auxIndex = charStartIndex - index;
                crcByteShifting = ENCINTCOMM_THREE_BYTE_SHIFTING - index;
                crcByteShifting <<= ENCINTCOMM_THREE_BYTE_SHIFTING;
                crcByteAux = resultCRC;
                crcByteAux >>= crcByteShifting;
                zerosExtendedArray[auxIndex] = (uint8_t)(crcByteAux & ENCINTCOMM_LESS_SIGNIFICANT_BYTE);
            }
        }
    }
    crcResultAux = 0u;
    /* Construct 32b with the array */
    for(index = 0; index < resultLength; index++)
    {
        zerosIndex = charStartIndex - index;
        auxIndex = resultLength - index;
        result[auxIndex] = zerosExtendedArray[zerosIndex];
    }
    return 0u;
}


