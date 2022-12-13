################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlockMergeBase.cpp \
../src/entorno.cpp \
../src/pruebatadCasilla.cpp \
../src/pruebatadTablero.cpp \
../src/tadCasilla.cpp \
../src/tadJuego.cpp \
../src/tadTablero.cpp 

OBJS += \
./src/BlockMergeBase.o \
./src/entorno.o \
./src/pruebatadCasilla.o \
./src/pruebatadTablero.o \
./src/tadCasilla.o \
./src/tadJuego.o \
./src/tadTablero.o 

CPP_DEPS += \
./src/BlockMergeBase.d \
./src/entorno.d \
./src/pruebatadCasilla.d \
./src/pruebatadTablero.d \
./src/tadCasilla.d \
./src/tadJuego.d \
./src/tadTablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


