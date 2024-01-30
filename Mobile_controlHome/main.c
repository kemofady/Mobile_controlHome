#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "Mobile_control.h"
#include <string.h>
#define F_CPU 8000000UL
#include "avr/delay.h"

#include "DIO_driver/Dio_Interface.h"
#include "GIE_driver/Gie_interface.h"
#include "ADC_driver/Adc_interface.h"
#include "Timer_driver/Timer_interface.h"
#include "UART_driver/UART_interface.h"
#include "LCD_driver/LCD_interface.h"



void main()
{
	/*initialize*/
    LCD_voidinit();
    UART_init();
    Adc_voidInit();
	PWM_voidInitTimer1();
	Timer_voidInitTimer0();
	Setup_Pins();

	PWM_voidSetDutyCycle1(500);
    u8 check_login=1;   /*Check what return from login func if 1 or 0 */
    check_login = loginFunc();
    /*set Timer for automatic system to measure temp and take action if it more than 40 */
    Timer_voidSetCtc0Isr(Home_AutomaticSys);
    while (1)
    {
    	if(check_login)
    	{
    		Home_ManualSys();
    	}

    }
}


