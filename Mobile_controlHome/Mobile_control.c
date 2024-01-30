#include "STD_TYPES.h"
#include <string.h>
#include "Bit_Math.h"
#define F_CPU 8000000UL
#include "avr/delay.h"
#include "Mobile_controlConfig.h"

#include "DIO_driver/Dio_Interface.h"
#include "GIE_driver/Gie_interface.h"
#include "ADC_driver/Adc_interface.h"
#include "Timer_driver/Timer_interface.h"
#include "UART_driver/UART_interface.h"
#include "LCD_driver/LCD_interface.h"
#include "Mobile_control.h"

u8 choose;
u8 key;

u8 loginUsers[Number_Of_Users][USER_SIZE] = {
    {"karim"},
    {"fady"},
    {"ali"},
    {"joo"},
    {"koky"},
    {"jod"},
    {"messi"},
    {"shady"},
    {"salah"},
    {"noor"}};

u8 loginPass[Number_Of_Users][PASS_SIZE] = {
    {"111"},
    {"222"},
    {"333"},
    {"444"},
    {"555"},
    {"666"},
    {"777"},
    {"888"},
    {"999"},
    {"000"}};
//**********************************************************
u8 loginFunc()
{
    u8 local_u8_counter; // number of wrong entries
    u8 local_u8_id = 0;   // username index
    u8 local_u8_userCorrect = FALSE; // username flag
    u8 local_u8_passwordCorrect = FALSE;// password flag
    u8 local_u8_receiveUART[USER_SIZE]; // Initialize array to receive from UART
    LCD_voidsendstring("WELCOME...");
    _delay_ms(500);

    /**************************************************************/
    // The number of errors in the entry
   for (local_u8_counter = 1; local_u8_counter < 4; local_u8_counter++)
    {
        LCD_voidclearscrean();
        LCD_voidsendstring("Enter username: ");
        UART_ReceiveString(local_u8_receiveUART);
        local_u8_userCorrect = FALSE;		 // Reset user correctness flag
        for (local_u8_id = 0; local_u8_id < Number_Of_Users; local_u8_id++)
        {
            if (strcmp(local_u8_receiveUART, loginUsers[local_u8_id]) == 0)
            {
                LCD_voidclearscrean();
                local_u8_userCorrect = TRUE;
                _delay_ms(1000);
                break;
            }
        }


        if (local_u8_userCorrect)
        {
            break; // Exit the loop if the username is correct
        }
        else if (local_u8_counter < 3)
        {
            LCD_voidclearscrean();
            LCD_voidsendstring("WRONG USER NAME");
    		Buzzer(1);

            LCD_gotoxy(1, 0);
            LCD_voidsendstring("Still have");
            LCD_gotoxy(1, 11);
            LCD_voidWriteNumber((3 - local_u8_counter));
            LCD_voidsendstring("tries");
            _delay_ms(1000);
            // Make receive UART array NULL for the username
            for (u8 i = 0; i < USER_SIZE; i++)
            {
                local_u8_receiveUART[i] = NULL;
            }
        }
        else if (local_u8_counter == 3 && local_u8_userCorrect == FALSE)
        {
            LCD_voidclearscrean();
            LCD_voidsendstring("NO TRIES LEFT");
            LCD_gotoxy(1, 0);
            LCD_voidsendstring("SHUTDOWN SYSTEM");
    		Buzzer(3);

            _delay_ms(1000);
            break;
        }
    }
    // ******************************************************************************
    if (local_u8_userCorrect)
    {
        for (local_u8_counter = 1; local_u8_counter < 4; local_u8_counter++)
        {
            u8 local_u8_receiveUARTpass[PASS_SIZE];
            LCD_voidclearscrean();
            LCD_voidsendstring("Enter password : ");
            UART_ReceiveString(local_u8_receiveUARTpass);
            _delay_ms(1000);
            local_u8_passwordCorrect = FALSE; // Reset password correctness flag

            for (local_u8_id = 0; local_u8_id < Number_Of_Users; local_u8_id++)
            {
                if (strcmp(local_u8_receiveUARTpass, loginPass[local_u8_id]) == 0)
                {
                    LCD_voidclearscrean();
                    local_u8_passwordCorrect = TRUE;
                    break;
                }
            }

            if (local_u8_passwordCorrect)
            {
                LCD_voidclearscrean();
                LCD_voidsendstring("WELCOME HOME ....");
        		Buzzer(2);
                break;
            }
            else if (local_u8_counter < 3 && local_u8_passwordCorrect == FALSE)
            {
                LCD_voidclearscrean();
                LCD_voidsendstring("WRONG PASSWORD");
        		Buzzer(1);

                LCD_gotoxy(1, 0);
                LCD_voidsendstring("Still have");
                LCD_gotoxy(1, 10);
                LCD_voidWriteNumber((3 - local_u8_counter));
                LCD_voidsendstring("tries");
                _delay_ms(1000);

                // Make receive UART array NULL for the password
                for (u8 i = 0; i < PASS_SIZE; i++)
                {
                    local_u8_receiveUARTpass[i] = NULL;
                }
            }
            else if (local_u8_counter == 3 && local_u8_passwordCorrect == 0)
            {
                LCD_voidclearscrean();
                LCD_voidsendstring("NO TRIES LEFT");
                LCD_gotoxy(1, 0);
                LCD_voidsendstring("SHUTDOWN SYSTEM");
                _delay_ms(1000);
        		Buzzer(3);
                break;
            }
        }
    }

    return (local_u8_passwordCorrect && local_u8_userCorrect);
}

void Setup_Pins()
{
    /*RX pin*/
    Dio_voidSetPinDirection(RX_TX_PORT, RX_PIN, DIO_INPUT);
    /*TX pin*/
    Dio_voidSetPinDirection(RX_TX_PORT, TX_PIN, DIO_OUTPUT);
    /*Buzzer*/
    Dio_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);
    /*Servo Motor*/
	Dio_voidSetPinDirection( SERVO_PORT , SERVO_PIN, DIO_OUTPUT);
	/*DC Motor*/
    Dio_voidSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN, DIO_OUTPUT);
    /*LM35*/
    Dio_voidSetPinDirection(LM35_PORT, LM35_PIN, DIO_INPUT);
    /*initialize led pins direction*/
    LED_init();
}

void Buzzer(u8 buz_mode)
{
	switch(buz_mode)
	{
		case 1:
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
    		_delay_ms(1000);
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
    		_delay_ms(100);
    		break;

		case 2:
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
    		_delay_ms(100);
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
    		_delay_ms(100);
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
    		_delay_ms(100);
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
    		_delay_ms(100);
    		break;

		case 3:
    		Dio_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
    		_delay_ms(100);
    		break;

	}

}

void servo(u16 Servo_Pos)
{
	PWM_voidSetDutyCycle1(Servo_Pos);
	_delay_ms(500);

}
void Manual_Temp()
{
	LCD_voidclearscrean();
 	LCD_voidsendstring("TEMP: ");
	u8 digital = ADC_u8readvalue(0);
	u16 mVolt = ((u32)5000*digital)/256;
	u8 temp = mVolt/10;
	LCD_voidWriteNumber(temp);
	_delay_ms(3000);
	LCD_voidclearscrean();
	_delay_ms(100);
}
u8 Automatic_Temp()
{
	u8 digital = ADC_u8readvalue(0);
	u16 mVolt = ((u32)5000*digital)/256;
	u8 temp = mVolt/10;
	return temp;
}
void DC_Motor()
{
    LCD_voidclearscrean();
    LCD_voidsendstring("1-(ON) 2-(OFF)");
    LCD_gotoxy(1 ,0);
    LCD_voidsendstring("3- Return");
    key= UART_u8Recive();
    switch (key)
    {
    case '1':
    	Dio_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN, DIO_HIGH);
    	break;
    case '2':
    	Dio_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN, DIO_LOW);
    	break;
    case '3':
    	break;
    default:
       	break;
    }

}

void Light()
{
    LCD_voidclearscrean();
    LCD_voidsendstring("1-(ON) 2-(OFF)");
    LCD_gotoxy(1 ,0);
    LCD_voidsendstring("3- Return");
    key= UART_u8Recive();

    switch (key)
    {
    case '1':
    	LED_ON();
    	break;
    case '2':
    	LED_OFF();
    	break;
    case '3':
    	break;
    default:
       	break;
    }

}
void DC_AutomaticMotor()
{
	Dio_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN, DIO_HIGH);
}

void LED_init()
{
    Dio_voidSetPinDirection (LEDS_PORT,LED1_PIN,DIO_OUTPUT);
 	Dio_voidSetPinDirection (LEDS_PORT,LED2_PIN,DIO_OUTPUT);
 	Dio_voidSetPinDirection (LEDS_PORT,LED3_PIN,DIO_OUTPUT);

}
void LED_ON(void)
{
    Dio_voidSetPinValue (LEDS_PORT,LED1_PIN,DIO_HIGH);
    Dio_voidSetPinValue (LEDS_PORT,LED2_PIN,DIO_HIGH);
    Dio_voidSetPinValue (LEDS_PORT,LED3_PIN,DIO_HIGH);

}

 void LED_OFF(void)
{
    Dio_voidSetPinValue (LEDS_PORT,LED1_PIN,DIO_LOW);
    Dio_voidSetPinValue (LEDS_PORT,LED2_PIN,DIO_LOW);
    Dio_voidSetPinValue (LEDS_PORT,LED3_PIN,DIO_LOW);
 }

void Home_ManualSys()
{
    LCD_voidclearscrean();
    LCD_voidsendstring("1-Open. 2-Temp.");
    LCD_gotoxy(1, 0);
    LCD_voidsendstring("3-Fan.  4-Light.");
    // Receive a character from UART
    choose=UART_u8Recive();
    LCD_voidclearscrean();
    switch (choose)
    {
    case '1':
        servo(2500);
        break;
    case '2':
    	Manual_Temp();

        break;
    case '3':
        DC_Motor();
        break;
    case '4':
    	Light();
    	break;
    default:
    	LCD_voidclearscrean();
        LCD_voidsendstring("incorrect input");
        _delay_ms(1000);
        break;
    }
}

void Home_AutomaticSys()
{
		u8 temp=Automatic_Temp();
		while(temp>40)
		{	LCD_voidclearscrean();
			LCD_gotoxy(1, 0);
			LCD_voidsendstring("TEMP: ");
			LCD_gotoxy(1, 8);
			LCD_voidWriteNumber(temp);
			DC_AutomaticMotor();
			Buzzer(3);
			temp=Automatic_Temp();
		}

}

