/*
 *  Name        : DIO_REG.h
 *  Description : This file contains register addresses of DIO
 *  Created on  : Dec 10, 2022
 *  Author      : Heba Ashraf
 *  Version     : v0.0
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Port A IO Registers */
#define DDRA_REG		*((volatile uint8 *)0x3A)
#define PORTA_REG		*((volatile uint8 *)0x3B)
#define PINA_REG		*((volatile uint8 *)0x39)

/* Port B IO Registers */
#define DDRB_REG		*((volatile uint8 *)0x37)
#define PORTB_REG		*((volatile uint8 *)0x38)
#define PINB_REG		*((volatile uint8 *)0x36)

/* Port C IO Registers */
#define DDRC_REG		*((volatile uint8 *)0x34)
#define PORTC_REG		*((volatile uint8 *)0x35)
#define PINC_REG		*((volatile uint8 *)0x33)

/* Port D IO Registers */
#define DDRD_REG		*((volatile uint8 *)0x31)
#define PORTD_REG		*((volatile uint8 *)0x32)
#define PIND_REG		*((volatile uint8 *)0x30)


#endif /* DIO_REG_H_ */
