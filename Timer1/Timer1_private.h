/*
 *  Name        : Timer1_private.h
 *  Description : This file contains functions implementation
 *  Created on  : Jan 25, 2023
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_


/************************************************************************************************/
/*                                     Timer1 registers                                         */
/************************************************************************************************/

#define TCCR1A                        *( (volatile uint8*) (0x4F) )
#define TCCR1B                        *( (volatile uint8*) (0x4E) )


#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
