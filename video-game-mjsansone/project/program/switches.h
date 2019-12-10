#ifndef SWITCHES_INCLUDED
#define SWITCHES_INCLUDED

#define SW0 BIT0
#define SW1 BIT1
#define SW2 BIT2
#define SW3 BIT3
#define SWITCHES (SW0 | SW1 | SW2 | SW3) /* ONLY 4 SWITCH ON THIS BOARD */
//#define SWITCH_STATE (switch_state_down0 | switch_state_down1 | switch_state_down2 | switch_state_down3) //may be wrong as this is for expression
void switch_init();

void switch_interrupt_handler();


//extern char SWITCH_STATE;
extern char switch_state_down0,switch_state_down1,switch_state_down2,switch_state_down3, switch_state_changed; /* effectively boolean */



#endif // included
