################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/Event_Manager/subdir.mk
-include source/App/App_Event_Manager/subdir.mk
-include source/subdir.mk
-include project/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := twrkm35z75m_meterliblp3phkwh_test
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: twrkm35z75m_meterliblp3phkwh_test.axf

# Tool invocations
twrkm35z75m_meterliblp3phkwh_test.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\meterliblp" -L"D:\Jhaveri Labs\Workspace\twrkm35z75m_meterliblp3phkwh_test\fraclib" -Xlinker -no-warn-rwx-segments -Xlinker -Map="twrkm35z75m_meterliblp3phkwh_test.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T twrkm35z75m_meterliblp3phkwh_test_Debug.ld -o "twrkm35z75m_meterliblp3phkwh_test.axf" $(OBJS) $(USER_OBJS) $(LIBS) -lmeterlp_cm0p_mmau_gcc -lfrac_cm0p_mmau_gcc
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) twrkm35z75m_meterliblp3phkwh_test.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "twrkm35z75m_meterliblp3phkwh_test.axf"; # arm-none-eabi-objcopy -v -O binary "twrkm35z75m_meterliblp3phkwh_test.axf" "twrkm35z75m_meterliblp3phkwh_test.bin" ; # checksum -p MKM35Z512xxx7 -d "twrkm35z75m_meterliblp3phkwh_test.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
