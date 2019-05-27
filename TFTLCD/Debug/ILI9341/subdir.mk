################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ILI9341/ILI9341_Driver.c 

OBJS += \
./ILI9341/ILI9341_Driver.o 

C_DEPS += \
./ILI9341/ILI9341_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
ILI9341/%.o: ../ILI9341/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Inc" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Drivers/CMSIS/Include" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Icons" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Images" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/ILI9341" -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Touch" -I../UART -I"E:/Projects/TFTLCD/TFTLCD/TFTLCD/Display"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


