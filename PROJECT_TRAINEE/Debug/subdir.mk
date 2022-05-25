################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../I2C.c \
../KPD_prog.c \
../LCD.c \
../SECURITY.c \
../eeprom.c \
../main.c 

OBJS += \
./DIO_program.o \
./I2C.o \
./KPD_prog.o \
./LCD.o \
./SECURITY.o \
./eeprom.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./I2C.d \
./KPD_prog.d \
./LCD.d \
./SECURITY.d \
./eeprom.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


