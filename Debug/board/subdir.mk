################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKM35Z512VLQ7 -DCPU_MKM35Z512VLQ7_cm0plus -DSDK_DEBUGCONSOLE_UART -DNDEBUG -DMCU_MKM35Z7 -DTWR_KM35Z75M -DTOWER -DMCUXPRESSO_SDK -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\meterliblp" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\fraclib" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\device" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\drivers" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\utilities" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\uart" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\serial_manager" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\component\lists" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\CMSIS" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\project" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\board" -I"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\source\App\App_Event_Manager" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

