# Mobile_controlHome
Using the Atmega32 as a microcontroller, I was able to communicate with it using UART, through the Bluetooth module HC-05. I was also able to monitor the user commands on an LCD screen.
 Safety door that could be opened by the mobile application by entering username and password, and light on/off that could be controlled also by the mobile phone. The system supports 10 users with different names and password. In case of entering the name of the password 3 times wrong, the system should give alarm.
Automatic control:
Using timers, you can control the system automatically by measure the temp if temp become more than 40 , buzzer and DC motor work.

⚡Hardware Components:
-> ATmega32 
-> LED 
-> LCD 
-> SERVO MOTOR 
-> DC MOTOR 
-> BLUETOOTH MODULE (HC-05) 
-> POTENTIOMETER
-> BUZZER 
-> LM 35

Software Architecture Layers:
1. App
2. LIB:
 STD_TYPES, BIT_MATH 
3. HAL:
 LED, LCD, SERVO, LM_SENSOR, LDR_SENSOR, BUZZER, DC MOTOR
4. MCAL:
DIO, ADC, GIE, TIMERS, UART 
