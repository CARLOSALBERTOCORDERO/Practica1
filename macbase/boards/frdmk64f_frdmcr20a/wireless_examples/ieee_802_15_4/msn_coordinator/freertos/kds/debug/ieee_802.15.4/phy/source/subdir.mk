################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/ASP.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MPM.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyDebug.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyISR.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyPacketProcessor.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyPlmeData.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyStateMachine.c \
E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyTime.c 

OBJS += \
./ieee_802.15.4/phy/source/ASP.o \
./ieee_802.15.4/phy/source/MPM.o \
./ieee_802.15.4/phy/source/PhyDebug.o \
./ieee_802.15.4/phy/source/PhyISR.o \
./ieee_802.15.4/phy/source/PhyPacketProcessor.o \
./ieee_802.15.4/phy/source/PhyPlmeData.o \
./ieee_802.15.4/phy/source/PhyStateMachine.o \
./ieee_802.15.4/phy/source/PhyTime.o 

C_DEPS += \
./ieee_802.15.4/phy/source/ASP.d \
./ieee_802.15.4/phy/source/MPM.d \
./ieee_802.15.4/phy/source/PhyDebug.d \
./ieee_802.15.4/phy/source/PhyISR.d \
./ieee_802.15.4/phy/source/PhyPacketProcessor.d \
./ieee_802.15.4/phy/source/PhyPlmeData.d \
./ieee_802.15.4/phy/source/PhyStateMachine.d \
./ieee_802.15.4/phy/source/PhyTime.d 


# Each subdirectory must supply rules for building sources it contributes
ieee_802.15.4/phy/source/ASP.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/ASP.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/MPM.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MPM.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyDebug.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyDebug.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyISR.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyISR.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyPacketProcessor.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyPacketProcessor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyPlmeData.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyPlmeData.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyStateMachine.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyStateMachine.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ieee_802.15.4/phy/source/PhyTime.o: E:/ITESO/kds_dscae_o2019/macbase/middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/PhyTime.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wall  -g -D_DEBUG=1 -DCPU_MK64FN1M0VMD12 -DFSL_RTOS_FREE_RTOS -DFRDM_K64F_MCR20A -DFRDM_K64F -DFREEDOM -I../../../../../../../../rtos/freertos_8.2.3/Source/portable/GCC/ARM_CM4F -I../../../../../../../../rtos/freertos_8.2.3/Source/include -I../../../../../../../../middleware/wireless/framework_5.0.5/Common/rtos/FreeRTOS/config -I../../../../../../../../rtos/freertos_8.2.3/Source -I../../../../../../../../CMSIS/Include -I../../../../../../../../devices -I../../../../../../../../middleware/mmcau_2.0.0 -I../../../../../../../../middleware/usb_1.1.0 -I../../../../../../../../middleware/usb_1.1.0/osa -I../../../../../../../../middleware/usb_1.1.0/include -I../../../../../../../../middleware/usb_1.1.0/device -I../../../../../../../../middleware/wireless/framework_5.0.5/OSAbstraction/Interface -I../.. -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/source/App -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/mac/interface -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/interface -I../../../../../../../../middleware/wireless/framework_5.0.5/GPIO -I../../../../../../../../middleware/wireless/framework_5.0.5/Keyboard/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/LED/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/SPI_Adapter -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/Flash/Internal -I../../../../../../../../middleware/wireless/framework_5.0.5/Common -I../../../../../../../../middleware/wireless/framework_5.0.5/MemManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Messaging/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/Panic/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/RNG/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Interface -I../../../../../../../../middleware/wireless/framework_5.0.5/TimersManager/Source -I../../../../../../../../middleware/wireless/framework_5.0.5/FunctionLib -I../../../../../../../../middleware/wireless/framework_5.0.5/Lists -I../../../../../../../../middleware/wireless/framework_5.0.5/SecLib -I../../../../../../../../middleware/wireless/framework_5.0.5/ModuleInfo -I../../../../../../../../middleware/wireless/framework_5.0.5/MWSCoexistence/Interface -I../../.. -I../../../../../../../../devices/MK64F12/drivers -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/MCR20A/MCR20Drv -I../../../../../../../../middleware/wireless/ieee_802_15_4_5.0.5/phy/source/XcvrSpi -I../../../../../../../../middleware/wireless/framework_5.0.5/SerialManager/Source/USB_VirtualCom -I../../../../../../../../devices/MK64F12 -I../../../../../../../../devices/MK64F12/utilities -std=gnu99 -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h -include ../../../../../../../../boards/frdmk64f_frdmcr20a/wireless_examples/ieee_802_15_4/msn_coordinator/freertos/app_preinclude.h  -fshort-wchar  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


