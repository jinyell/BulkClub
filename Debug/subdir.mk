################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Date.cpp \
../Member.cpp \
../MemberList.cpp \
../PreferredMember.cpp \
../PrintHeader.cpp \
../Purchase.cpp \
../PurchasesList.cpp \
../main.cpp 

OBJS += \
./Date.o \
./Member.o \
./MemberList.o \
./PreferredMember.o \
./PrintHeader.o \
./Purchase.o \
./PurchasesList.o \
./main.o 

CPP_DEPS += \
./Date.d \
./Member.d \
./MemberList.d \
./PreferredMember.d \
./PrintHeader.d \
./Purchase.d \
./PurchasesList.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


