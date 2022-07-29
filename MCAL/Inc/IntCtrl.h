/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.h
 *  Module:  	  IntCtrl
 *
 *  Description:  Header file for TM4C123GH6PM MCU - NVIC Module
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef INTCTRL_H_
#define INTCTRL_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: IntCrtl_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Initialize NVIC/SCB Module by parsing the configuration 
*			   into NVIC/SCB registers
*******************************************************************************/
void IntCrtl_Init(void);

/*******************************************************************************
* Service Name: IntCtrl_EnableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): IntCtrl_InterruptTypeType InterruptId, IntCtrl_PriorityLevel Priority
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Enable the passing interrupt and assign priority to it
*******************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptType InterruptId, IntCtrl_PriorityLevel Priority);

/*******************************************************************************
* Service Name: IntCtrl_DisableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): IntCtrl_InterruptTypeType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Disable the passing interrupt 
*******************************************************************************/
void IntCtrl_DisableInterrupt(IntCtrl_InterruptType InterruptId);
 
#endif  /* INTCTRL_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
