//#include "FS.h"
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

  int xpos = 100;
  int ypos = 100;
  int dx=20;
  int dy=20;
  int xpos1 = 100;
  int ypos1 = 100;
  int appSelect=0;

void setup(void) {

  Serial.begin(115200);
  tft.init();
  tft.fillScreen((0xFFFF));
}

void loop() {
  uint16_t x, y;
  tft.setRotation(3);
  tft.fillRect(0,0,80,80,TFT_BLUE);
  tft.fillRect(80,0,80,80,TFT_YELLOW);
  tft.fillRect(160,0,80,80,TFT_RED);
  if (tft.getTouch(&x, &y)) {
    //tft.fillEllipse(x,y,10,10,TFT_BLACK);
    tft.fillRect(345,20,130,20,TFT_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(TFT_BLACK);
    tft.setCursor(350,20);
    tft.print(int(x));
    tft.print(" ");
    tft.print(int(y));
    delay(100);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(350,20);
    tft.print(int(x));
    tft.print(" ");
    tft.print(int(y));
  }
  if (400<=x  &&  x<=480 && y<=310 && y>=230){  //Touch pico Pong
  if (appSelect==2){
    xpos1=100;
    ypos1=100;
  }
  if (appSelect==3){
    tft.fillRect(0,0,470,400,TFT_WHITE);
  }
  appSelect=1;
  }
  if(appSelect==1){
      xpos1=xpos1 + dx;
  ypos1=ypos1 + dy;

  if (xpos1>420){
    dx=-dx;
  }
  if (xpos1<20){
    dx=-dx;
  }
  if (ypos1>260){
    dy=-dy;
  }
  if (ypos1<100){
    dy=-dy;
  }

  tft.fillRect(xpos1,ypos1,10,10,TFT_BLACK);
  tft.fillRect(xpos1, 280, 60, 20, TFT_BLACK);
  delay(10);
  tft.fillRect(xpos1,ypos1,10,10,TFT_WHITE);
  tft.fillRect(xpos1, 280, 60, 20, TFT_WHITE);


  }
  if (320<=x  &&  x<=400 && y<=310 && y>=230){   //Touch pico Invaders

  if (appSelect==1){
    xpos=100;
    ypos=100;
  }
  if (appSelect==3){
    tft.fillRect(0,0,470,400,TFT_WHITE);
  }
  appSelect=2;
  }
  if (appSelect==2){
   tft.setRotation(3);
   ypos=0;
    xpos=xpos + dx;

  if (xpos>400){
    dx=-dx;
  }
  if (xpos<20){
    dx=-dx;
  }

  tft.fillRect(xpos+10, ypos+100, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+30, ypos+100, 10, 10, TFT_YELLOW);

  tft.fillRect(xpos+0, ypos+100+10, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+10, ypos+100+10, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+20, ypos+100+10, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+30, ypos+100+10, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+40, ypos+100+10, 10, 10, TFT_YELLOW);

  tft.fillRect(xpos, ypos+100+20, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+10, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+20, ypos+100+20, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+30, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+40, ypos+100+20, 10, 10, TFT_YELLOW);

  tft.fillRect(xpos+0, ypos+100+30, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+10, ypos+100+30, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+20, ypos+100+30, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+30, ypos+100+30, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+40, ypos+100+30, 10, 10, TFT_YELLOW);

  tft.fillRect(xpos+10, ypos+100+40, 10, 10, TFT_YELLOW);
  tft.fillRect(xpos+30, ypos+100+40, 10, 10, TFT_YELLOW);

  tft.fillRect(240, 260, 20, 20, TFT_YELLOW);
  tft.fillRect(220, 280, 60, 20, TFT_YELLOW);

   delay(200);

  tft.fillRect(xpos+10, ypos+100, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+30, ypos+100, 10, 10, TFT_WHITE);

  tft.fillRect(xpos+0, ypos+100+10, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+10, ypos+100+10, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+20, ypos+100+10, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+30, ypos+100+10, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+40, ypos+100+10, 10, 10, TFT_WHITE);

  tft.fillRect(xpos, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+10, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+20, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+30, ypos+100+20, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+40, ypos+100+20, 10, 10, TFT_WHITE);

  tft.fillRect(xpos+0, ypos+100+30, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+10, ypos+100+30, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+20, ypos+100+30, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+30, ypos+100+30, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+40, ypos+100+30, 10, 10, TFT_WHITE);

  tft.fillRect(xpos+10, ypos+100+40, 10, 10, TFT_WHITE);
  tft.fillRect(xpos+30, ypos+100+40, 10, 10, TFT_WHITE);
  }

  if (320>=x  &&  x>=240 && y<=310 && y>=230){   //Touch Logikara
  
  if (appSelect==1 or appSelect==2){
    tft.fillRect(0,0,470,400,TFT_WHITE);
  }
  appSelect=3;
  }
  if (appSelect==3){
  tft.drawLine(470, 90, 10, 90, TFT_BLACK);
  tft.drawLine(385, 170, 10, 170, TFT_BLACK);
  tft.drawLine(385, 310, 385, 100, TFT_BLACK);
  tft.drawCircle(50,250,50,TFT_RED);
  tft.fillRect(130,200,100,100,TFT_BLACK);
  tft.setTextSize(4);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(160,240);
  tft.print("ON");
  tft.fillRect(260,200,100,100,TFT_BLACK);
  tft.setTextSize(4);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(280,240);
  tft.print("OFF");

  tft.fillRect(390,100,80,220,TFT_YELLOW);
  tft.fillRect(400,320-y,60,30,TFT_BLACK);

 
  if (80>=x && 10<=x && y>=100 && y<=320){
    tft.fillRect(400,60,60,25,TFT_BLACK);

    tft.setTextSize(3);
    tft.setTextColor(TFT_BLACK);
    tft.setCursor(400,60);
    tft.print(int(y));
    delay(200);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(400,60);
    tft.print(int(y));

    //tft.fillRect(370,0,80,80,TFT_BLACK);
  }
    if (360>=x  &&  x>=260 && y<=130 && y>=30){ 
    tft.fillRect(200,100,50,50,TFT_YELLOW);
    tft.fillCircle(50,250,50,TFT_YELLOW);
    }
    if (260>=x  &&  x>=130 && y<=130 && y>=30){ 
    tft.fillRect(200,100,50,50,TFT_BLUE);
    tft.fillCircle(50,250,50,TFT_BLUE);
    }
  

  }
  


  
}




