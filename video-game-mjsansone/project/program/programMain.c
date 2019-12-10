#include <msp430.h>
#include <stdlib.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "wdinterruptHandler.h"
void main(void) 
{

shapes *play1;
shapes *playb;

 play1 = malloc(sizeof(shapes));
  
  play1->posx1 = 40; // hard coded for testing
  play1->posy1 = 15;
  play1->height = 20;
  play1->length = 20;

  
  configureClocks();
  switch_init();
  led_init();
  lcd_init();//start lcd
  u_char width = screenWidth, height = screenHeight;
  clearScreen(COLOR_BLUE);
  // drawString5x7(10,10, "hello", COLOR_GREEN, COLOR_RED); // this crashes the program //do not remove this or it crashes
  buzzer_init();
  enableWDTInterrupts();
  
  inplayers(play1);// start players
  or_sr(0x18);  // CPU off, GIE on
} 
