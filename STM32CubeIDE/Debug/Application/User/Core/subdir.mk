################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Core/lfs_config.c \
../Application/User/Core/littlefs_port.c \
C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/main.c \
C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/stm32h5xx_hal_msp.c \
../Application/User/Core/stm32h5xx_hal_uart.c \
C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/stm32h5xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
../Application/User/Core/usart.c 

OBJS += \
./Application/User/Core/lfs_config.o \
./Application/User/Core/littlefs_port.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32h5xx_hal_msp.o \
./Application/User/Core/stm32h5xx_hal_uart.o \
./Application/User/Core/stm32h5xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/usart.o 

C_DEPS += \
./Application/User/Core/lfs_config.d \
./Application/User/Core/littlefs_port.d \
./Application/User/Core/main.d \
./Application/User/Core/stm32h5xx_hal_msp.d \
./Application/User/Core/stm32h5xx_hal_uart.d \
./Application/User/Core/stm32h5xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/%.o Application/User/Core/%.su Application/User/Core/%.cyclo: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32h5xx_hal_msp.o: C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/stm32h5xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32h5xx_it.o: C:/Users/hp/Desktop/pfa/STAB_project/Core/Src/stm32h5xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/lfs_config.cyclo ./Application/User/Core/lfs_config.d ./Application/User/Core/lfs_config.o ./Application/User/Core/lfs_config.su ./Application/User/Core/littlefs_port.cyclo ./Application/User/Core/littlefs_port.d ./Application/User/Core/littlefs_port.o ./Application/User/Core/littlefs_port.su ./Application/User/Core/main.cyclo ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/main.su ./Application/User/Core/stm32h5xx_hal_msp.cyclo ./Application/User/Core/stm32h5xx_hal_msp.d ./Application/User/Core/stm32h5xx_hal_msp.o ./Application/User/Core/stm32h5xx_hal_msp.su ./Application/User/Core/stm32h5xx_hal_uart.cyclo ./Application/User/Core/stm32h5xx_hal_uart.d ./Application/User/Core/stm32h5xx_hal_uart.o ./Application/User/Core/stm32h5xx_hal_uart.su ./Application/User/Core/stm32h5xx_it.cyclo ./Application/User/Core/stm32h5xx_it.d ./Application/User/Core/stm32h5xx_it.o ./Application/User/Core/stm32h5xx_it.su ./Application/User/Core/syscalls.cyclo ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/syscalls.su ./Application/User/Core/sysmem.cyclo ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/sysmem.su ./Application/User/Core/usart.cyclo ./Application/User/Core/usart.d ./Application/User/Core/usart.o ./Application/User/Core/usart.su

.PHONY: clean-Application-2f-User-2f-Core

