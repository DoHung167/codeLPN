################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../proj/mcu/putchar.c 

OBJS += \
./proj/mcu/putchar.o 


# Each subdirectory must supply rules for building sources it contributes
proj/mcu/%.o: ../proj/mcu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"G:\BLE\telink_sig_mesh_sdk_v3.2.2\firmware" -I"G:\BLE\telink_sig_mesh_sdk_v3.2.2\firmware\vendor\common\mi_api\mijia_ble_api" -I"G:\BLE\telink_sig_mesh_sdk_v3.2.2\firmware\vendor\common\mi_api\libs" -D__PROJECT_MESH_LPN__=1 -DCHIP_TYPE=CHIP_TYPE_8258 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

