LD_FILE = boards/samd21x18-bootloader-crystalless.ld
USB_VID = 0x239A
USB_PID = 0x8019

#FLASH_IMPL = spi_flash.c
FLASH_IMPL = internal_flash.c

CHIP_VARIANT = SAMD21G18A
CHIP_FAMILY = samd21

# Include these Python libraries in firmware.
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_BusDevice
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_LIS3DH
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_NeoPixel
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Thermistor
