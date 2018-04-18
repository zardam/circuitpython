// LEDs
//#define MICROPY_HW_LED_MSC              PIN_PA17 // red
// #define UART_REPL
#define USB_REPL

#define MICROPY_HW_NEOPIXEL (&pin_PA27)

#define MICROPY_HW_BOARD_NAME "Adafruit CRICKit M0"
#define MICROPY_HW_MCU_NAME "samd21g18"

// These pins are not reset. PA24 and PA25 are USB data.
#define MICROPY_PORT_A        (PORT_PA24 | PORT_PA25 | PORT_PA27)
#define MICROPY_PORT_B        (0)

#define CIRCUITPY_INTERNAL_NVM_SIZE 0

#include "internal_flash.h"

#define BOARD_FLASH_SIZE (0x00040000 - 0x2000 - 0x010000)
