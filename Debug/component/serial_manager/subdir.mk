################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c component/serial_manager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKM35Z512VLQ7 -DCPU_MKM35Z512VLQ7_cm0plus -DSDK_DEBUGCONSOLE_UART -DNDEBUG -DMCU_MKM35Z7 -DTWR_KM35Z75M -DTOWER -DMCUXPRESSO_SDK -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\meterliblp" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\fraclib" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\device" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\drivers" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\utilities" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\uart" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\serial_manager" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\lists" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\CMSIS" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\project" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\board" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source\App\App_Event_Manager" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-serial_manager

clean-component-2f-serial_manager:
	-$(RM) ./component/serial_manager/fsl_component_serial_manager.d ./component/serial_manager/fsl_component_serial_manager.o ./component/serial_manager/fsl_component_serial_port_uart.d ./component/serial_manager/fsl_component_serial_port_uart.o

.PHONY: clean-component-2f-serial_manager

