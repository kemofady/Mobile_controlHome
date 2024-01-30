/*
 * Timer_Reg.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Ali Othman
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_



#define TIMSK (*((volatile u8 *)0x59)) //enable interrupt
#define TIFR  (*((volatile u8 *)0x58)) //interrupt flag
#define OCR0  (*((volatile u8 *)0x5C)) // compare match
#define TCCR0 (*((volatile u8 *)0x53))//Control
#define TCNT0 (*((volatile u8 *)0x52)) // Timer counter
#define SREG  (*((volatile u8 *)0x5F))

/* Timer 1 */
#define TCCR1A	(*((volatile u8 *) 0x4F))
#define TCCR1B	(*((volatile u8 *) 0x4E))
#define TCNT1	(*((volatile u16 *)0x4C))
#define OCR1A	(*((volatile u16 *)0x4A))
#define OCR1B	(*((volatile u16 *)0x48))
#define ICR1	(*((volatile u16 *)0x46))



#endif /* TIMER_REG_H_ */
