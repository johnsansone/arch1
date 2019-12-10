#include <msp430.h>
short num1 = 0;
short tem1 = 0;
#include "led.h"
short enablelow = 0;
void enableL(){
  enablelow = 1;
}
void disableL(){
  enablelow = 0;
}
void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  
  static char blink_count = 0;
  if(enablelow == 0){
      
    }
  else{

    if(num1 ==0){
        num1= num1 + 1;
	led_on();
      }
    else if(num1 >= 3){
	num1 = 0;
        led_off();	
      }
    else{
	num1= num1 + 1;
        led_off();
      }
    }
}
