################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
PROJECT_TRAINEE.lss \

FLASH_IMAGE += \
PROJECT_TRAINEE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PROJECT_TRAINEE.elf secondary-outputs

# Tool invocations
PROJECT_TRAINEE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PROJECT_TRAINEE.map -mmcu=atmega32 -o "PROJECT_TRAINEE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PROJECT_TRAINEE.lss: PROJECT_TRAINEE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PROJECT_TRAINEE.elf  >"PROJECT_TRAINEE.lss"
	@echo 'Finished building: $@'
	@echo ' '

PROJECT_TRAINEE.hex: PROJECT_TRAINEE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PROJECT_TRAINEE.elf  "PROJECT_TRAINEE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PROJECT_TRAINEE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PROJECT_TRAINEE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PROJECT_TRAINEE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
