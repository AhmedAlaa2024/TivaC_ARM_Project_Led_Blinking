/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_regs.h
 *  Module:  	  Port_regs
 *
 *  Description:  Header file for Port Module's registers map
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef PORT_REGS_H_
#define PORT_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint32 GPIOA		:1;
	uint32 GPIOB		:1;
	uint32 GPIOC		:1;
	uint32 GPIOD		:1;
	uint32 GPIOE		:1;
	uint32 GPIOF		:1;
	uint32				:7;
	uint32 UDMA			:1;
	uint32				:2;
	uint32 USB0			:1;
	uint32 				:15;
} SYSCTL_RCGCGPIO_BF;

typedef union
{
	uint32 R;
	SYSCTL_RCGCGPIO_BF BF;
} SYSCTL_RCGCGPIO_Tag;

typedef struct
{
	uint32 LBYTE		:8;
	uint32				:24;
} GPIO_ONE_BYTE_BF;
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           					0x40004000
#define GPIO_PORTB_BASE_ADDRESS           					0x40005000
#define GPIO_PORTC_BASE_ADDRESS           					0x40006000
#define GPIO_PORTD_BASE_ADDRESS           					0x40007000
#define GPIO_PORTE_BASE_ADDRESS           					0x40024000
#define GPIO_PORTF_BASE_ADDRESS           					0x40025000

#define GPIO_GPIODATA_OFFSET								0x3FC
#define GPIO_GPIODIR_OFFSET									0x400
#define GPIO_GPIOAFSEL_OFFSET								0x420
#define GPIO_GPIODR2R_OFFSET								0x500
#define GPIO_GPIODR4R_OFFSET								0x504
#define GPIO_GPIODR8R_OFFSET								0x508
#define GPIO_GPIOODR_OFFSET									0x50C
#define GPIO_GPIOPUR_OFFSET									0x510
#define GPIO_GPIOPDR_OFFSET									0x514
#define GPIO_GPIOSLR_OFFSET									0x518
#define GPIO_GPIODEN_OFFSET									0x51C
#define GPIO_GPIOLOCK_OFFSET								0x520
#define GPIO_GPIOCR_OFFSET									0x524
#define GPIO_GPIOAMSEL_OFFSET								0x528
#define GPIO_GPIOPCTL_OFFSET								0x52C


#define SYSCTL_BASE_ADDRESS									0x400FE000

#define SYSCTL_RCGCGPIO										(*((volatile SYSCTL_RCGCGPIO_Tag*)(SYSCTL_BASE_ADDRESS+0x608)))
 
#endif  /* PORT_REGS_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port_regs.h
 *********************************************************************************************************************/
