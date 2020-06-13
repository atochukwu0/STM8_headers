# STM8_headers

FOSS device headers and examples for STM8 microcontrollers


##STM8 Device Headers 

Open-Sources device headers for all STM8 8-bit microcontroller families.
Headers are compatible with SDCC, Cosmic and IAR compilers


##Example Projects 

Below projects have been tested successfully with SDCC, Cosmic and IAR

adc_measure
  - measure analog voltage every ~500ms
  - print value via UART using printf()

------------------------

blink_interrupt
  - blink LED in TIM4 interrupt service routine

------------------------

blink_noInterrupt
  - blink LED with a simple NOP() loop

------------------------

I2C_LCD
  - Periodically print text to 2x16 char LCD attached to I2C
  - LCD type Batron BTHQ21605V-COG-FSRE-I2C 2X16 (Farnell 1220409)

------------------------

low-power_auto-wake
  - enter power-down mode with wake via port-ISR or AWU

------------------------

millis_delay
  - test 1ms ISR, millis(), micros() etc., similar to  Arduino

------------------------

pin_interrupt
  - TLI interrupt on pin D7 (not port). Corresponds to INTx on Arduino

------------------------

pin_read_write
  - read and write pin states without interrupts

------------------------

port_interrupt
  - port interrupt on pin PE5. Corresponds to port change interrupts on Arduino

------------------------

PWM_generate
  - generate a PWM on pin PD2/TIM3_CH1 (=pin 3 on sduino)

------------------------

read_unique_ID
  - read unique identifier and print via UART
  - Note: UID not supported by all devices

------------------------

read_write_D-flash
  - save data to D-flash/EEPROM and read back

------------------------

read_write_option_bytes
  - change option bytes, e.g. activate/deactivate the ROM-bootloader

------------------------

read_write_P-flash
  - save data to P-flash and read back

------------------------

serial_gets_printf
  - serial input/output with gets and printf
  - without interrupts or FIFO

------------------------

serial_printf
  - serial output via printf
  - without interrupts or FIFO

------------------------

serial_printf_FIFO_interrupt
  - serial output via printf
  - using Tx & Rx FIFO and interrupts
  - similar to Arduino Serial class
  
------------------------

serial_write
  - echo read bytes from UART
  - without interrupts or FIFO

------------------------

STM8_StdPeriphLib
  - mix with functions/headers of the STM8S Standard Peripheral Library (SPL)
