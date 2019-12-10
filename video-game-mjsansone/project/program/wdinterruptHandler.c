#include <msp430.h>
#include <stdlib.h>
#include "wdinterruptHandler.h"
short num1 = 0;
short tem1 = 0;
u_char vx;
u_char vy;
#include "led.h"

short enablelow = 0;
void enableL(){
  enablelow = 1;
}
void disableL(){
  enablelow = 0;
}


shapes *play1;
shapes *playb;
void inplayers(shapes *s1)//, shapes *s2)
{
  play1=s1;
  //playb=s2;
}

void otherp()// this is a copy of the malloc of the other player if this is not done then it does not work
{
 
  playb = malloc(sizeof(shapes));
  playb->posx1 =  malloc(sizeof(unsigned char));
  playb->posy1 = malloc(sizeof(unsigned char));
  playb->posx2 = malloc(sizeof(unsigned char));
  playb->height  = malloc(sizeof(unsigned char));
  playb->length  = malloc(sizeof(unsigned char));
  playb->posx3 = malloc(sizeof(unsigned char));
  playb->posy2 = malloc(sizeof(unsigned char));
  playb->posy3 = malloc(sizeof(unsigned char));
  playb->vx = malloc(sizeof(unsigned char));
  playb->vy = malloc(sizeof(unsigned char));
  playb->s = malloc(sizeof(unsigned char));
  playb->l = malloc(sizeof(unsigned char));
  playb->posx1 = 40; //160/2;
  playb->posy1 = 15;
  playb->height = 20;
  playb->length = 20;
 
 

}
void drawsplus()//shapes *shape)
{
  u_int x = 0; //shape->posx1;
  u_int y = 0;//shape->posy1;
  u_int s = 0;//shape->s;
  u_int l = 0;//shape->l;
  u_int x1 = 20;
  u_int x2 = 50;
  u_int x3 = 30;
  u_int x4 = 40;
  u_int y1 = 10;
  u_int y2 = 40;
  u_int y3 = 20;
  u_int y4 = 30;
  for(;y <= y2;)
    {
      if(y < y3 || y > y4)
	{
	  if(x >= x3 && x <=x4)
	    {
	      drawPixel(x,y,COLOR_WHITE);
	      x++;
	    }
	  else if(x< x3)
	    {
	      x = x3;
	      drawPixel(x,y,COLOR_WHITE);
	      x++;
	    }
	  else if (x>x4)
	    {
	      x=x1;
	      y++;
	    }
	  
	}
      if(y >= y3 && y <= y4 )
	{
	  if(x>=x1 && x<= x2)
	    {
	      drawPixel(x,y,COLOR_WHITE);
	      x++;
	    }
	 else if(x>x2)
	    {
	      y++;
	      x=x1;
	    }
	}
    }
  	   
}



void drawsball(shapes *shape)// was going to do movement but drawing more than 3 or 2 things crashes the msp430
{
  movement(shape);
}
  void movement(shapes *shape)
  {
    
    
    if(shape->posy2 == 1)
      {
	shape->posy1 = shape->posy1 + shape->vy;
	
      }
    else if(shape->posy3 == 1)
      {
	shape ->posy1 = shape->posy1 - shape->vy;
      }
    if(shape->posx2 ==1)
      {
	shape->posx1 += shape->vx;
      }
    else
      {
	shape->posx1 -= shape->vx;
      }
      
  }

void drawsplayer(shapes* shape1)
{ 
  
  if(shape1->posx2==1 )
    {
      fillRectangle(shape1->posx1, shape1->posy1,shape1->height,shape1->length, COLOR_WHITE);
    }
  else if(shape1->posx3==1)
    {
      fillRectangle(shape1->posx1,shape1->posy1,shape1->length,shape1->length,COLOR_WHITE);
    }
  else
    {
      
      
      fillRectangle(shape1->posx1,shape1->posy1,shape1->height,shape1->length, COLOR_WHITE); 
       }
  
}
void drawplayer1()
{
  
}
void draws(shapes *shape)
{
  if(shape->shapetype = 0)
    {
      drawsball(shape);
    }
  else if(shape->shapetype = 1)
    {
      drawsplayer(shape);
    }
}

void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char blink_count = 0;
  if(enablelow == 0){
    if(num1==0)//clear screen and draw plus 1/8 of the time
      {
	num1++;
	clearScreen(COLOR_BLUE);
	drawsplus();
    }
    if(num1==8) // draw player 1/8 of the time note this is not active if dim is on as i waas trouble shooting and ran out of time
      
      {
	drawsplayer(play1);
	num1 = 0;
      }
    else
      {
       
	num1++;
      }
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
