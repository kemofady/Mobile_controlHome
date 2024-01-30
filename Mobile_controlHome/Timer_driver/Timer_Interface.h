/*
 * Timer_Interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Ali Othman
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer_voidInitTimer0(void);
void Timer_voidSetCtc0Isr(void (*func)(void));
void PWM_voidInit0(void);
void PWM_voidSetDutyCycle(u8 Cpy_u8Duty);
void PWM_voidInitTimer1(void);
void PWM_voidSetDutyCycle1(u16 Cpy_u16Duty);
void ICU_voidDisableInterrupt(void);
void ICU_voidSetCallBack(void (*func)(void));
u16 ICU_u16ReadValue(void);
void ICU_voidSetSenseControl(u8 state);
void ICU_voidInit(void);
s32 map(s32 cpy_inputmini,s32 cpy_inputmax,s32 cpy_outmini,s32 cpy_outmax,s32 cpy_val);



#endif /* TIMER_INTERFACE_H_ */
