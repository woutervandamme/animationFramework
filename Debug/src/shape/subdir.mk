################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/shape/Boid.cpp \
../src/shape/Circle.cpp \
../src/shape/DynamicCircle.cpp \
../src/shape/Flock.cpp \
../src/shape/GravityCircle.cpp \
../src/shape/Player.cpp \
../src/shape/Shape.cpp 

OBJS += \
./src/shape/Boid.o \
./src/shape/Circle.o \
./src/shape/DynamicCircle.o \
./src/shape/Flock.o \
./src/shape/GravityCircle.o \
./src/shape/Player.o \
./src/shape/Shape.o 

CPP_DEPS += \
./src/shape/Boid.d \
./src/shape/Circle.d \
./src/shape/DynamicCircle.d \
./src/shape/Flock.d \
./src/shape/GravityCircle.d \
./src/shape/Player.d \
./src/shape/Shape.d 


# Each subdirectory must supply rules for building sources it contributes
src/shape/%.o: ../src/shape/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/wouter/workspace/Pvm_AnimationFramework/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


