################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bst.c \
../src/int_data.c \
../src/main.c \
../src/tests.c \
../src/utility_library.c 

OBJS += \
./src/bst.o \
./src/int_data.o \
./src/main.o \
./src/tests.o \
./src/utility_library.o 

C_DEPS += \
./src/bst.d \
./src/int_data.d \
./src/main.d \
./src/tests.d \
./src/utility_library.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


