/**********************
  Simple blink project w/o interrupts
   
  supported hardware:
    - STM8S Discovery board (https://www.st.com/en/evaluation-tools/stm8s-discovery.html)
    - STM8L Discovery board (https://www.st.com/en/evaluation-tools/stm8l-discovery.html)
    - Sduino Uno (https://github.com/roybaer/sduino_uno)
    - muDuino (http://www.cream-tea.de/presentations/160305_PiAndMore.pdf)
  
  Functionality:
    - blink LED w/o ISR. Mainly for testing toolchain
    - pass port structure to function
**********************/

/*----------------------------------------------------------
    SELECT BOARD
----------------------------------------------------------*/
//#define STM8S_DISCOVERY
//#define STM8L_DISCOVERY
#define SDUINO
//#define MUDUINO

/*----------------------------------------------------------
    INCLUDE FILES
----------------------------------------------------------*/
#if defined(STM8S_DISCOVERY)
  #include "../../include/STM8S105C6.h"
  #define LED_PORT   sfr_PORTD
  #define LED_PIN    0
#elif defined(STM8L_DISCOVERY)
  #include "../../include/STM8L152C6.h"
  #define LED_PORT   sfr_PORTC
  #define LED_PIN    7
#elif defined(SDUINO)
  #include "../../include/STM8S105K6.h"
  #define LED_PORT   sfr_PORTC
  #define LED_PIN    5
#elif defined(MUDUINO)
  #include "../../include/STM8S207MB.h"
  #define LED_PORT   sfr_PORTH
  #define LED_PIN    2
#else
  #error undefined board
#endif



// toggle specified pin. Pass port struct as pointer
void toggle_pin(PORT_t *port, uint8_t pin) {
  
  port->ODR.byte ^= (1 << pin);
  
} // toggle_pin



/////////////////
//    main routine
/////////////////
void main (void) {

  uint32_t  i;
    
  // switch to 16MHz (default is 2MHz)
  sfr_CLK.CKDIVR.byte = 0x00;
    
  // configure LED pin as output
  LED_PORT.DDR.byte = (uint8_t) (1 << LED_PIN);    // input(=0) or output(=1)
  LED_PORT.CR1.byte = (uint8_t) (1 << LED_PIN);    // input: 0=float, 1=pull-up; output: 0=open-drain, 1=push-pull
  LED_PORT.CR2.byte = (uint8_t) (1 << LED_PIN);    // input: 0=no exint, 1=exint; output: 0=2MHz slope, 1=10MHz slope
  

  // main loop
  while(1) {
	
    // toggle LED. Pass port struct as pointer
    toggle_pin(&LED_PORT, LED_PIN);
    
    // simple wait
    for (i=0; i<300000L; i++)
      NOP();
    
  } // main loop

} // main

/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/