################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/hp/Desktop/pfa/STAB_project/littlefs-2.10.2/littlefs-2.10.2/lfs.c \
C:/Users/hp/Desktop/pfa/STAB_project/littlefs-2.10.2/littlefs-2.10.2/lfs_util.c 

OBJS += \
./Application/littlefs/lfs.o \
./Application/littlefs/lfs_util.o 

C_DEPS += \
./Application/littlefs/lfs.d \
./Application/littlefs/lfs_util.d 


# Each subdirectory must supply rules for building sources it contributes
Application/littlefs/lfs.o: C:/Users/hp/Desktop/pfa/STAB_project/littlefs-2.10.2/littlefs-2.10.2/lfs.c Application/littlefs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/littlefs/lfs_util.o: C:/Users/hp/Desktop/pfa/STAB_project/littlefs-2.10.2/littlefs-2.10.2/lfs_util.c Application/littlefs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2/littlefs-2.10.2 -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/hp/Desktop/pfa/STAB_project/Drivers/STM32H5xx_HAL_Driver/Src" -I"C:/Users/hp/Desktop/pfa/STAB_project/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-littlefs

clean-Application-2f-littlefs:
	-$(RM) ./Application/littlefs/lfs.cyclo ./Application/littlefs/lfs.d ./Application/littlefs/lfs.o ./Application/littlefs/lfs.su ./Application/littlefs/lfs_util.cyclo ./Application/littlefs/lfs_util.d ./Application/littlefs/lfs_util.o ./Application/littlefs/lfs_util.su

.PHONY: clean-Application-2f-littlefs

