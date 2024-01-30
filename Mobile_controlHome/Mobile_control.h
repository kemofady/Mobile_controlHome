#ifndef MONILE_CONTROL_H
#define MONILE_CONTROL_H

#include"STD_TYPES.h"

#define NULL 			'\0'
#define USER_SIZE   	 7
#define PASS_SIZE		 5
#define Number_Of_Users  10
#define FALSE   		 0
#define TRUE   		     1

//*************************************************

u8 loginFunc();
void Setup_Pins();
void Buzzer(u8 buz_mode);
void servo(u16 Servo_Pos);
void Home_ManualSys();
void Home_AutomaticSys();
void DC_Motor();
void DC_AutomaticMotor();
void Temp();
u8 Automatic_Temp();
void LED_init();
void LED_ON();
void LED_OFF();
void Light();
#endif
