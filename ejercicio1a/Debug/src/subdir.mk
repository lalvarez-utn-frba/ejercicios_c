################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/guia_ejercicios_1a.c \
../src/guia_ejercicios_1b.c 

OBJS += \
./src/guia_ejercicios_1a.o \
./src/guia_ejercicios_1b.o 

C_DEPS += \
./src/guia_ejercicios_1a.d \
./src/guia_ejercicios_1b.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


