################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_irtc.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_irtc.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_irtc.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKM35Z512VLQ7 -DCPU_MKM35Z512VLQ7_cm0plus -DSDK_DEBUGCONSOLE_UART -DNDEBUG -DMCU_MKM35Z7 -DTWR_KM35Z75M -DTOWER -DMCUXPRESSO_SDK -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\meterliblp" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\fraclib" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\device" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\drivers" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\utilities" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\uart" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\serial_manager" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\lists" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\CMSIS" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\project" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\board" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source\App\App_Event_Manager" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_irtc.d ./drivers/fsl_irtc.o ./drivers/fsl_lpuart.d ./drivers/fsl_lpuart.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o

.PHONY: clean-drivers

