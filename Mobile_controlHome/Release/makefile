################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART_driver/subdir.mk
-include Timer_driver/subdir.mk
-include LCD_driver/subdir.mk
-include GIE_driver/subdir.mk
-include DIO_driver/Debug/subdir.mk
-include DIO_driver/subdir.mk
-include ADC_driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Mobile_controlHome.lss \

FLASH_IMAGE += \
Mobile_controlHome.hex \

EEPROM_IMAGE += \
Mobile_controlHome.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mobile_controlHome.elf secondary-outputs

# Tool invocations
Mobile_controlHome.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mobile_controlHome.map -mmcu=atmega32 -o "Mobile_controlHome.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mobile_controlHome.lss: Mobile_controlHome.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mobile_controlHome.elf  >"Mobile_controlHome.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mobile_controlHome.hex: Mobile_controlHome.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mobile_controlHome.elf  "Mobile_controlHome.hex"
	@echo 'Finished building: $@'
	@echo ' '

Mobile_controlHome.eep: Mobile_controlHome.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Mobile_controlHome.elf  "Mobile_controlHome.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mobile_controlHome.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Mobile_controlHome.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mobile_controlHome.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
