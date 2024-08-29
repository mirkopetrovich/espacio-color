

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(256, 6, NEO_GRB + NEO_KHZ800);  //NEO_RBG para calugas
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pixels.begin(); 
  pixels.clear();
  pixels.show();
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte==255) pixels.clear();
    pixels.setPixelColor(incomingByte,pixels.Color(255,255,255));


  pixels.show();
  }





}