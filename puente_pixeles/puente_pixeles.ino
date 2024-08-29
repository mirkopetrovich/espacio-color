

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(27, 6, NEO_RBG + NEO_KHZ800);
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
  pixels.begin(); 
  pixels.clear();
  pixels.show();
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

  if (incomingByte>=100) pixi(incomingByte-100,255);
  else pixi(incomingByte,0);
  pixels.show();
  }


}

void pixi(int posi,int v) {

  //int r = random(255);
  //int g = random(255);
  //int b = random(255);

  for (int i=0;i<3;i++) {
  
        pixels.setPixelColor(i+(posi*3), pixels.Color(0,v,0));
    
  }
}