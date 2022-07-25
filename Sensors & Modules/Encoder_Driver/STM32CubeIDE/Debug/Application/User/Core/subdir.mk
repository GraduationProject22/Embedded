################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/gpio.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/main.c \
../Application/User/Core/rotary.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/stm32f1xx_hal_msp.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/stm32f1xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/tim.c \
G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/usart.c 

OBJS += \
./Application/User/Core/gpio.o \
./Application/User/Core/main.o \
./Application/User/Core/rotary.o \
./Application/User/Core/stm32f1xx_hal_msp.o \
./Application/User/Core/stm32f1xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/tim.o \
./Application/User/Core/usart.o 

C_DEPS += \
./Application/User/Core/gpio.d \
./Application/User/Core/main.d \
./Application/User/Core/rotary.d \
./Application/User/Core/stm32f1xx_hal_msp.d \
./Application/User/Core/stm32f1xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/tim.d \
./Application/User/Core/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/gpio.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/gpio.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/main.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/%.o Application/User/Core/%.su: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/stm32f1xx_hal_msp.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/stm32f1xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f1xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/stm32f1xx_it.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/stm32f1xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f1xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/tim.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/tim.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/Core/usart.o: G:/Faculty\ Of\ Engineering/4th\ Communication/Graduation\ Project/OneDrive\ -\ Alexandria\ University/Team\ 7/Resources/Courses/MOOC\ -\ STM32CubeMX\ and\ STM32Cube\ HAL\ basics/Projects/20220425_Encoder_Driver_Test/Core/Src/usart.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../../Core/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/gpio.d ./Application/User/Core/gpio.o ./Application/User/Core/gpio.su ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/main.su ./Application/User/Core/rotary.d ./Application/User/Core/rotary.o ./Application/User/Core/rotary.su ./Application/User/Core/stm32f1xx_hal_msp.d ./Application/User/Core/stm32f1xx_hal_msp.o ./Application/User/Core/stm32f1xx_hal_msp.su ./Application/User/Core/stm32f1xx_it.d ./Application/User/Core/stm32f1xx_it.o ./Application/User/Core/stm32f1xx_it.su ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/syscalls.su ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/sysmem.su ./Application/User/Core/tim.d ./Application/User/Core/tim.o ./Application/User/Core/tim.su ./Application/User/Core/usart.d ./Application/User/Core/usart.o ./Application/User/Core/usart.su

.PHONY: clean-Application-2f-User-2f-Core

