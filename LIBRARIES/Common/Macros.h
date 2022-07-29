/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Macros.h
 *  Module:  	  Macros
 *
 *  Description:  Header file for the common macros
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef Macros_H_
#define Macros_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Check if a certain bit in any register is set or cleared */
#define GET_BIT(REG,BIT) (( REG & (1<<BIT))>>BIT)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG = (REG>>num) | (REG << ((sizeof(REG) * 8)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG = (REG<<num) | (REG >> ((sizeof(REG) * 8)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/*Assembly instruction to enable interrupts "Change Processor State Interrupt Enable"*/
#define INTERRUPTS_ENABLE __asm(" CPSIE i");

/*Assembly instruction to disable interrupts "Change Processor State Interrupt Enable"*/
#define INTERRUPTS_DISABLE __asm(" CPSID i");

/* We access the register by casting ang concatinating */
#define ACCESS_REG(BASE,OFFSET) ( * ( (volatile unsigned long * )(BASE+OFFSET) ) )

/* To convert seconds into microseconds */
#define SECONDS(time)	(time*1000000)

/* To convert milliseconds into microseconds */
#define MSECONDS(time)	(time*1000)

#endif  /* Macros_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Macros.h
 *********************************************************************************************************************/
