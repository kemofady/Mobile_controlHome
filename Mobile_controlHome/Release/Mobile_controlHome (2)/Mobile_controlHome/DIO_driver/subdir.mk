################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.c 

OBJS += \
./Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.o 

C_DEPS += \
./Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.o: ../Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Mobile_controlHome (2)/Mobile_controlHome/DIO_driver/Dio_Prog.d" -MT"Mobile_controlHome\ (2)/Mobile_controlHome/DIO_driver/Dio_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


