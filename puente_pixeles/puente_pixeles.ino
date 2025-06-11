

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(256, 1, NEO_GRB + NEO_KHZ800);
int incomingByte = 0; // for incoming serial data
unsigned char led[66];

void setup() {
  USBSerial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(8, OUTPUT);
  pixels.begin(); 
  pixels.clear();
  pixels.show();
}

void loop() {

  if (USBSerial.available() > 0) {
    USBSerial.readBytes(led,66);

    //if (led[0]>=100) pixi(led[0]-100,255);
    //else pixi(led[0],0);
    for (int i=0;i<66;i++) {

    int rojo = 0;
    int verde = 0;
    int azul = 0;

    if (led[i]==0) {
      rojo = 0;
      verde = 0;
      azul = 0;
    }

    else if (led[i]==1) {
      rojo = 100;
      verde = 0;
      azul = 0;
    }

    else if (led[i]==2) {
      rojo = 0;
      verde = 100;
      azul = 0;
    }

     else if (led[i]==3) {
      rojo = 0;
      verde = 0;
      azul = 100;
    }

     else if (led[i]==4) {
      rojo = 30;
      verde = 30;
      azul = 100;
    }

     else if (led[i]==5) {
      rojo = 100;
      verde = 30;
      azul = 30;
    }

     else if (led[i]==6) {
      rojo = 30;
      verde = 100;
      azul = 30;
    }

     else if (led[i]==7) {
      rojo = 0;
      verde = 100;
      azul = 100;
    }

     else if (led[i]==8) {
      rojo = 30;
      verde = 30;
      azul = 30;
    }

     else if (led[i]==9) {
      rojo = 100;
      verde = 0;
      azul = 100;
    }

     else if (led[i]==10) {
      rojo = 100;
      verde = 100;
      azul = 0;
    }

     else if (led[i]==11) {
      rojo = 100;
      verde = 50;
      azul = 0;
    }

     else if (led[i]==12) {
      rojo = 0;
      verde = 100;
      azul = 50;
    }

     else if (led[i]==13) {
      rojo = 50;
      verde = 0;
      azul = 100;
    }

     else if (led[i]==14) {
      rojo = 100;
      verde = 100;
      azul = 100;
    }

     else if (led[i]==15) {
      rojo = 30;
      verde = 50;
      azul = 80;
    }

     else if (led[i]==16) {
      rojo = 80;
      verde = 30;
      azul = 50;
    }


    pixels.setPixelColor((i*3),pixels.Color(rojo,verde,azul));
    pixels.setPixelColor((i*3)+1,pixels.Color(rojo,verde,azul));
    pixels.setPixelColor((i*3)+2,pixels.Color(rojo,verde,azul));
    

    //pixels.setPixelColor(i,pixels.Color(led[i*3],led[(i*3)+1],led[(i*3)+2]));
    }
   
  pixels.show();
  }
}



void pixi(int posi,int v) {

  //int r = random(255);
  //int g = random(255);
  //int b = random(255);

  
  
        pixels.setPixelColor (posi, pixels.Color(0,v,0));
    
  
}