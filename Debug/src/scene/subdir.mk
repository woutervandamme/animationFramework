################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/scene/Scene.cpp \
../src/scene/SceneFactory.cpp \
../src/scene/WorldWindow.cpp 

OBJS += \
./src/scene/Scene.o \
./src/scene/SceneFactory.o \
./src/scene/WorldWindow.o 

CPP_DEPS += \
./src/scene/Scene.d \
./src/scene/SceneFactory.d \
./src/scene/WorldWindow.d 


# Each subdirectory must supply rules for building sources it contributes
src/scene/%.o: ../src/scene/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/wouter/workspace/Pvm_AnimationFramework/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


