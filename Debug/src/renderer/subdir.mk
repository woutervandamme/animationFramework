################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/renderer/Renderer.cpp 

OBJS += \
./src/renderer/Renderer.o 

CPP_DEPS += \
./src/renderer/Renderer.d 


# Each subdirectory must supply rules for building sources it contributes
src/renderer/%.o: ../src/renderer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/wouter/workspace/Pvm_AnimationFramework/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


