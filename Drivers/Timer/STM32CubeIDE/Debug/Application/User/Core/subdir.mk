################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/gpio.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/main.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/stm32f1xx_hal_msp.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/stm32f1xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/tim.c 

OBJS += \
./Application/User/Core/gpio.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32f1xx_hal_msp.o \
./Application/User/Core/stm32f1xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/tim.o 

C_DEPS += \
./Application/User/Core/gpio.d \
./Application/User/Core/main.d \
./Application/User/Core/stm32f1xx_hal_msp.d \
./Application/User/Core/stm32f1xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/gpio.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/gpio.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/main.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/stm32f1xx_hal_msp.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/stm32f1xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f1xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/stm32f1xx_it.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/stm32f1xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f1xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/%.o: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/tim.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220306_Timer_Test_1/Core/Src/tim.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/gpio.d ./Application/User/Core/gpio.o ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/stm32f1xx_hal_msp.d ./Application/User/Core/stm32f1xx_hal_msp.o ./Application/User/Core/stm32f1xx_it.d ./Application/User/Core/stm32f1xx_it.o ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/tim.d ./Application/User/Core/tim.o

.PHONY: clean-Application-2f-User-2f-Core

