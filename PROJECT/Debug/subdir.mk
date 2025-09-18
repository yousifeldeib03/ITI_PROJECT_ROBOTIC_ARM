################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PROGRAM.c \
../GIE_program.c \
../Keypad_Program.c \
../LCD_program.c \
../Servo_Program.c \
../TIM_Program.c \
../main.c \
../stepper_program.c 

OBJS += \
./DIO_PROGRAM.o \
./GIE_program.o \
./Keypad_Program.o \
./LCD_program.o \
./Servo_Program.o \
./TIM_Program.o \
./main.o \
./stepper_program.o 

C_DEPS += \
./DIO_PROGRAM.d \
./GIE_program.d \
./Keypad_Program.d \
./LCD_program.d \
./Servo_Program.d \
./TIM_Program.d \
./main.d \
./stepper_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


