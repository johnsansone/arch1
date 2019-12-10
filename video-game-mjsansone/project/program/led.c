#include <msp430.h>
#include "wdinterruptHandler.h"
#include "led.h"
#include "switches.h"

void led_init(){
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}
void led_on(){
  char ledFlags = 0;
  ledFlags |= LED_GREEN;
  ledFlags |= LED_RED;
   P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
   P1OUT |= ledFlags;
}
void led_off(){
  char ledFlags = 0;
   P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
   P1OUT |= ledFlags;
}
void led_update(pattern){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    switch (pattern){  
    case 0:
      
      ledFlags |= LED_GREEN;
      break;
    case 1:
      ledFlags |= LED_RED;
      break;
    case 2:
      
      break;
    case 3:
      ledFlags &= 0;
      break;
    case 4:
      ledFlags |= LED_GREEN;
      ledFlags |= LED_RED;
      break;
    case 5:
      disableL();
      break;
    case 6:
      enableL();
      break;
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

