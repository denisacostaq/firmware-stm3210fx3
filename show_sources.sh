#!/bin/bash

OPTIONS="Free-RTOS ST-LIB Source Salir"

select opt in $OPTIONS
do
	if [ "$opt" = "Salir" ]
	then
		exit
	elif [ "$opt" = "Free-RTOS" ]
	then
		echo -n 'FREERTOS_SOURCE =' && find src/common/KERNEL -name '*.c' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo ''
		echo -n 'FREERTOS_HEADER =' && find src/common/KERNEL -name '*.h' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo ''
		find src/common/KERNEL -type d | awk '{printf" \nINCLUDES += -I $(top_builddir)/%s",$1}' && echo ''
		echo ''
		echo 'template_SOURCES += $(FREERTOS_SOURCE) $(FREERTOS_HEADER)'
	elif [ "$opt" = "ST-LIB" ]
	then
		echo -n 'ST_LIB_SOURCE =' && find src/common/STM32F10x -name '*.c' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo ''
		echo -n 'ST_LIB_HEADER =' && find src/common/STM32F10x -name '*.h' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo ''
		find src/common/STM32F10x -type d | awk '{printf" \nINCLUDES += -I $(top_builddir)%s",$1}' && echo ''
		echo ''
		echo 'template_SOURCES += $(ST_LIB_SOURCE) $(ST_LIB_HEADER)'
	elif [ "$opt" = "Source" ]
	then
		echo -n 'my_SOURCE =' && find src/Source -name '*.c' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo -n 'my_HEADER =' && find src/Source -name '*.h' | awk '{printf" \\\n$(top_builddir)/%s",$1}' && echo ''
		echo ''
		find src/Source -type d | awk '{printf" \nINCLUDES += -I $(top_builddir)%s",$1}' && echo ''
	else
		clear
		echo "opción erronea"
	fi
done
