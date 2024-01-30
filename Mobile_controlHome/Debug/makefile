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
smart_home_test.lss \

EEPROM_IMAGE += \
smart_home_test.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: smart_home_test.elf secondary-outputs

# Tool invocations
smart_home_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smart_home_test.map -mmcu=atmega32 -o "smart_home_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smart_home_test.lss: smart_home_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smart_home_test.elf  >"smart_home_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

smart_home_test.eep: smart_home_test.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex smart_home_test.elf  "smart_home_test.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smart_home_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 smart_home_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) smart_home_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
