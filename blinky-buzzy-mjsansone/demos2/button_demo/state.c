#include "state.h"
#include "wdinterruptHandler.h"
#include "buzzer.h"
#include "led.h"
short count0 = 0;
short count1 = 0;
short count2 = 0;
short count3 = 0;
void button0()
{
  switch(count0){
    case 0:
      count0 = 1;
      buzzer_set_period(1000);
      led_update(5);
      break;
    case 1:
      count0 = 2;
      buzzer_set_period(1500);
      led_update(5);
      break;
    case 2:
      count0 = 3;
      buzzer_set_period(1750);
      led_update(5);
      break;
    case 3:
      count0 = 0;
      buzzer_set_period(0000);
      led_update(5);
      break;
    }
  
}
void button1()
{
  switch(count1){
    case 0:
      count1 = 1;
      buzzer_set_period(2000);
      led_update(6);
      break;
    case 1:
      count1 = 2;
      buzzer_set_period(1750);
      led_update(6);
      break;
    case 2:
      count1 = 3;
      buzzer_set_period(1500);
      led_update(6);
      break;
    case 3:
      count1 = 0;
      buzzer_set_period(2000);
      led_update(6);
      break;
    }

}
void button2()
{
  disableL();
  switch(count2){
    case 0:
      count2 = 1;
      buzzer_set_period(1200);
      led_update(4);
      break;
    case 1:
      count2 = 2;
      buzzer_set_period(1800);
      led_update(3);
      break;
    case 2:
      count2 = 3;
      buzzer_set_period(1300);
      led_update(1);
      break;
    case 3:
      count2 = 0;
      buzzer_set_period(1200);
      led_update(0);
      break;
  }

}
void button3()
{
  disableL();
  switch(count3){
    case 0:
      count3 = 1;
      buzzer_set_period(1500);
      led_update(0);
      break;
    case 1:
      count3 = 2;
      buzzer_set_period(1000);
      led_update(1);
      break;
    case 2:
      count3 = 3;
      buzzer_set_period(1250);
      led_update(3);
      break;
    case 3:
      count3 = 0;
      buzzer_set_period(2000);
      led_update(4);
      break;
    }

}/*
void mode_update(short button){
  switch(button){
  case 0:
    button0();
    break;
  case 1:
    button1();
  break;    
  case 2:
     disableL();
    button2();
  break;
  case 3:
     disableL();
    button3();
  break;
  }
}*/
void mode_update(short button){
  switch(button){
  case 0:
    button0();
    break;
  case 1:
    button1();
  break;    
  case 2:
    button2();
  break;
  case 3:
    button3();
  break;
  }
} 
