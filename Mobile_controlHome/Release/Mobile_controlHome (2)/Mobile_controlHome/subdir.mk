################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mobile_controlHome\ (2)/Mobile_controlHome/main.c 

OBJS += \
./Mobile_controlHome\ (2)/Mobile_controlHome/main.o 

C_DEPS += \
./Mobile_controlHome\ (2)/Mobile_controlHome/main.d 


# Each subdirectory must supply rules for building sources it contributes
Mobile_controlHome\ (2)/Mobile_controlHome/main.o: ../Mobile_controlHome\ (2)/Mobile_controlHome/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Mobile_controlHome (2)/Mobile_controlHome/main.d" -MT"Mobile_controlHome\ (2)/Mobile_controlHome/main.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


