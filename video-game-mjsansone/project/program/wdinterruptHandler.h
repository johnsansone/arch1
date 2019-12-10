//this struct is for all shapes
#include "timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "lcdtypes.h"
#include "lcdutils.h"
#include "lcddraw.h"
typedef struct{
  u_char posx1;
  u_char posx2;//right for ball //right for player
  u_char height;
  u_char length;
  u_char posx3;//left for ball //left for player
  u_char posy1;
  u_char posy2;// up for ball
  u_char posy3;//down for ball
  u_char vx;
  u_char vy;
  u_int shapeid;
  u_char s ;//size of shape
  u_char l ;//size of infill 
  int shapetype ;// this defines what shape it is
  
}shapes;
void otherp();
void movement(shapes *shape);
void drawsplayer(shapes *shape1);
void inplayers(shapes *s1);//, shapes *s2);
void enableL();
void disableL();
