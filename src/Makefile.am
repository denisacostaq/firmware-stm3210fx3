CLEANFILES = \
	~* \
	*.txt \
	$(PACKAGE_NAME).axf \
	$(PACKAGE_NAME).as \
	$(PACKAGE_NAME).hex \
	$(PACKAGE_NAME).map \
	$(PACKAGE_NAME).bin

EXTRA_DIST = \
	./common

AUTOMAKE_OPTIONS = subdir-objects

LDSCRIPT = ./common/KERNEL/stm32_flash.ld

#Add the directory dir to the list of directories to be searched for header files.
AM_CPPFLAGS = \
	-I ./Source
AM_CPPFLAGS += -I ./common/STM32F10x/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
AM_CPPFLAGS += -I ./common/STM32F10x/Libraries/CMSIS/CM3/CoreSupport
AM_CPPFLAGS += -I ./common/STM32F10x/Utilities/STM32_EVAL
AM_CPPFLAGS += -I ./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc
AM_CPPFLAGS += -I ./common/STM32F10x/Utilities/STM32_EVAL/stm3210c_eval
AM_CPPFLAGS += -I ./common/STM32F10x/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x

ST_LIB_HEADER = \
./common/STM32F10x/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/stm32f10x.h \
./common/STM32F10x/Libraries/CMSIS/CM3/CoreSupport/core_cm3.h \
./common/STM32F10x/Utilities/STM32_EVAL/stm32_eval.h \
./common/STM32F10x/Utilities/STM32_EVAL/stm3210c_eval/stm3210c_eval_lcd.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_usart.h \
./common/STM32F10x/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_rcc.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_gpio.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_i2c.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_spi.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/stm32f10x_exti.h \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/inc/misc.h

ST_LIB_SOURCE = \
./common/STM32F10x/Libraries/CMSIS/CM3/CoreSupport/core_cm3.c \
./common/STM32F10x/Utilities/STM32_EVAL/stm32_eval.c \
./common/STM32F10x/Utilities/STM32_EVAL/stm3210c_eval/stm3210c_eval_lcd.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c \
./common/STM32F10x/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c \
./common/STM32F10x/Libraries/STM32F10x_StdPeriph_Driver/src/misc.c



AM_CPPFLAGS += -I ./common/KERNEL 
AM_CPPFLAGS += -I ./common/KERNEL/FreeRTOS 
AM_CPPFLAGS += -I ./common/KERNEL/FreeRTOS/Source/include
AM_CPPFLAGS += -I ./common/KERNEL/FreeRTOS/Source
AM_CPPFLAGS += -I ./common/KERNEL/FreeRTOS/Source/portable/GCC/ARM_CM3
AM_CPPFLAGS += -I ./common/KERNEL/FreeRTOS/Source/portable/MemMang

FREERTOS_SOURCE = \
./common/KERNEL/FreeRTOS/Source/tasks.c \
./common/KERNEL/FreeRTOS/Source/list.c \
./common/KERNEL/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c \
./common/KERNEL/FreeRTOS/Source/portable/MemMang/heap_2.c  \
./common/KERNEL/stf_syscalls_minimal.c

FREERTOS_HEADER = \
./common/KERNEL/FreeRTOS/FreeRTOSConfig.h \
./common/KERNEL/FreeRTOS/Source/include/task.h \
./common/KERNEL/FreeRTOS/Source/include/list.h \
./common/KERNEL/FreeRTOS/Source/include/semphr.h \
./common/KERNEL/FreeRTOS/Source/portable/GCC/ARM_CM3/portmacro.h \
./common/KERNEL/stf_syscalls_minimal.h

SOURCE = \
./Source/main.c \
./Source/startup_stm32f10x.c \
$(ST_LIB_SOURCE) \
$(FREERTOS_SOURCE)

HEADER = \
./Source/stm32f10x_conf.h \
$(ST_LIB_HEADER) \
$(FREERTOS_HEADER)


bin_PROGRAMS = firmware-stm3210fx3
firmware_stm3210fx3_SOURCES = $(SOURCE) $(HEADER)
firmware_stm3210fx3_CFLAGS = $(uC_CFLAGS) $(LINKER_FLAGS) -Wa,-al=$(PACKAGE_NAME).as -Wall


# should use --gc-sections but the debugger does not seem to be able to cope with the option.
LINKER_FLAGS = -nostartfiles -Xlinker -o$(PACKAGE_NAME).axf -Xlinker -M -Xlinker -Map=$(PACKAGE_NAME).map -Xlinker --no-gc-sections

uC_CFLAGS = \
	-g \
	-Os \
	-std=gnu89 \
	-T $(LDSCRIPT) \
	-D STM32F10X_CL \
	-D USE_STM3210C_EVAL \
	-D USE_STDPERIPH_DRIVER \
	-D VECT_TAB_FLASH \
	-D GCC_ARMCM3 \
	-D inline= \
	-D PACK_STRUCT_END=__attribute\(\(packed\)\) \
	-D ALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) \
	-mthumb \
	-mcpu=cortex-m3 \
	-ffunction-sections \
	-fdata-sections


log: $(PACKAGE_NAME).axf hex
	$(host_alias)-nm -n $(PACKAGE_NAME).axf > $(PACKAGE_NAME)_SymbolTable.txt
	$(host_alias)-size --format=SysV $(PACKAGE_NAME).axf > $(PACKAGE_NAME)_MemoryListingSummary.txt
	$(host_alias)-size $(firmware_stm3210fx3_OBJECTS) > $(PACKAGE_NAME)_MemoryListingDetails.txt

$(PACKAGE_NAME).axf: $(firmware_stm3210fx3_OBJECTS) Makefile
	$(CC) $(uC_CFLAGS) $(firmware_stm3210fx3_OBJECTS) $(LINKER_FLAGS)

hex : $(PACKAGE_NAME).axf
	$(host_alias)-objcopy $(PACKAGE_NAME).axf -O ihex $(PACKAGE_NAME).hex
