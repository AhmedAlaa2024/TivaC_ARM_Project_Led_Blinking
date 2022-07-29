/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.h
 *  Module:  	  Port
 *
 *  Description:  Header file for Port Module
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Set the passed initial values for the GPIO pin
*              - Setup the mode of the GPIO pin
*              - Setup the internal resistor for i/p pin
*              - Setup the output current in case of output pin
*******************************************************************************/
void Port_Init(const Port_configType* ConfigPtr);
 
#endif  /* PORT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
