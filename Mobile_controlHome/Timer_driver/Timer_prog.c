/*
 * Timer_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Ali Othman
 */

/*library*/
#include "STD_TYPES.h"
#include "Bit_Math.h"

/* Mcal */
#include "Timer_Interface.h"
#include "Timer_Reg.h"

void (* callback_OCR) (void);
void (* callback_ICU)(void);
void Timer_voidInitTimer0(void)
{
	/* Choose CTC mode */

	SET_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);

	OCR0 = 250;

	/* Enable interrupt ocr */

	SET_BIT(TIMSK , 1); //SIE
	SET_BIT(SREG , 7); //GIE

	/* Choose pre scaller */
	SET_BIT(TCCR0 , 0);
	SET_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);

}

void Timer_voidSetCtc0Isr(void (*func)(void))
{
	callback_OCR = func;
}

/* ISR => CTC0 */
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (callback_OCR != '\0'){
		callback_OCR();
	}

}

void PWM_voidInit0(void)
{
	/* Activate timer mode fast PWM */
	SET_BIT(TCCR0 , 6);
	CLR_BIT(TCCR0 , 3);

	/* Non inverting mode */
	SET_BIT(TCCR0, 5);
	CLR_BIT(TCCR0, 4);

	/* Select ps to be 8 */
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}

void PWM_voidSetDutyCycle(u8 Cpy_u8Duty)
{
	OCR0 = Cpy_u8Duty;
}
void PWM_voidInitTimer1(void)
{
	/* select the mode FAST PWM*/
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	/* Non inverting */
	SET_BIT(TCCR1A, 7);
	CLR_BIT(TCCR1A, 6);

	/* PS = 8 */
	CLR_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);

	/* determine the max*/
	ICR1 = 20000;


}

void PWM_voidSetDutyCycle1(u16 Cpy_u16Duty)
{
	OCR1A = Cpy_u16Duty;
}
s32 map(s32 cpy_inputmini,s32 cpy_inputmax,s32 cpy_outmini,s32 cpy_outmax,s32 cpy_val)
{
	s32 local_holder = cpy_val - cpy_inputmax;
	local_holder *=(cpy_outmini-cpy_outmax);
	local_holder /=(cpy_inputmini-cpy_inputmax);
	local_holder += cpy_outmax;
	return local_holder;
}
/******************** ICU ********************/


void ICU_voidInit(void)
{
	/* Set event rising */
	SET_BIT(TCCR1B , 6);
	/* enable interrupt */
	SET_BIT(TIMSK , 5); // SIE
	/* P.S = 8 */
	CLR_BIT(TCCR1B , 0);
	SET_BIT(TCCR1B , 1);
	CLR_BIT(TCCR1B , 2);

}

void ICU_voidSetSenseControl(u8 state)
{
	if (state == 0)
	{
		CLR_BIT(TCCR1B , 6); //falling
	}
	else
	{
		SET_BIT(TCCR1B , 6); // rising

	}
}

u16 ICU_u16ReadValue(void)
{
	return ICR1;
}

void ICU_voidSetCallBack(void (*func)(void))
{
	callback_ICU = func;
}

void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK , 5); // SIE

}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{

	if (callback_ICU != '\0'){
		callback_ICU();
	}

}





