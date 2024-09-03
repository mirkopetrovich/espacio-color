#define CHICA

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(192, 6, NEO_GRB + NEO_KHZ800);


int alto = 5;

#ifdef CHICA
int ancho = 3;
#endif

#ifdef BIG
int ancho = 4;
#endif

int pixeles = alto * ancho;
int offset = ancho + 1;

int seg = 0;

#ifdef CHICA
const bool mono[] = { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,    // 0 
                      1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,    // 1
                      1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,    // 2
                      1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,    // 3
                      1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,    // 4
                      1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,    // 5
                      1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1,    // 6
                      1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,    // 7
                      1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,    // 8
                      1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,    // 9
                      0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,    // A
                      1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0,    // B
                      1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1,    // C
                      1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0,    // D
                      1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1,    // E
                      1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0 };  // F
#endif

#ifdef BIG
const bool mono[] = { 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1,  // 0
                      0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1,  // 1
                      1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,  // 2
                      1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,  // 3
                      1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1,  // 4
                      1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,  // 5
                      1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,  // 6
                      1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,  // 7
                      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,  // 8
                      1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,  // 9
                      0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1,  // A
                      1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0,  // B
                      1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,  // C
                      1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0,  // D
                      1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1,  // E
                      1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 };// F
#endif




void setup() {
  pixels.begin();
  pixels.clear();
}

void loop() {
  pixels.clear();


 turing(((seg/4096)%16),0,2);
 turing(((seg/256)%16),offset*1,2);
 turing(((seg/16)%16),offset*2,2);
 turing((seg%16),offset*3,2);
  turing(((seg/16)%16),offset*4,2);
 turing((seg%16),offset*5,2);
 
 
  pixels.show();   
  delay(100);
  seg++; 
  }



void turing(int numero, int posX, int posY){
  for (int i=0;i < pixeles; i++) {
    if (mono[i + (numero*pixeles)]) pixels.setPixelColor(XY((i%ancho+posX),floor(i/ancho)+posY),pixels.Color(100,10,60));
  }
}

uint8_t XY (uint8_t x, uint8_t y) {
  const uint8_t XYTable[] = {
     7,  15,  23,  31,  39,  47,  55,  63,  71,  79,  87,  95, 103, 111, 119, 127, 135, 143, 151, 159, 167, 175, 183, 191,
     6,  14,  22,  30,  38,  46,  54,  62,  70,  78,  86,  94, 102, 110, 118, 126, 134, 142, 150, 158, 166, 174, 182, 190,
     5,  13,  21,  29,  37,  45,  53,  61,  69,  77,  85,  93, 101, 109, 117, 125, 133, 141, 149, 157, 165, 173, 181, 189,
     4,  12,  20,  28,  36,  44,  52,  60,  68,  76,  84,  92, 100, 108, 116, 124, 132, 140, 148, 156, 164, 172, 180, 188,
     3,  11,  19,  27,  35,  43,  51,  59,  67,  75,  83,  91,  99, 107, 115, 123, 131, 139, 147, 155, 163, 171, 179, 187,
     2,  10,  18,  26,  34,  42,  50,  58,  66,  74,  82,  90,  98, 106, 114, 122, 130, 138, 146, 154, 162, 170, 178, 186,
     1,   9,  17,  25,  33,  41,  49,  57,  65,  73,  81,  89,  97, 105, 113, 121, 129, 137, 145, 153, 161, 169, 177, 185,
     0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184
  };

  uint8_t i = (y * 24) + x;
  uint8_t j = XYTable[i];
  return j;
}


/*
const int mono[] = {246,223,146,95,31,63,44,251,121,62,115,252,247,242,164,247,223,239,61,95,110,186,239,36,250,219,188,211,249,164};

const bool mono_8b[] =        { 1, 1, 1, 1, 0, 1, 1, 0,    // 246
                                1, 1, 0, 1, 1, 1, 1, 1,    // 223
                                1, 0, 0, 1, 0, 0, 1, 0,    // 146
                                0, 1, 0, 1, 1, 1, 1, 1,    // 95
                                0, 0, 0, 1, 1, 1, 1, 1,    // 31
                                0, 0, 1, 1, 1, 1, 1, 1,    // 63
                                0, 0, 1, 0, 1, 1, 0, 0,    // 44
                                1, 1, 1, 1, 1, 0, 1, 1,    // 251
                                0, 1, 1, 1, 1, 0, 0, 1,    // 121
                                0, 0, 1, 1, 1, 1, 1, 0,    // 62
                                0, 1, 1, 1, 0, 0, 1, 1,    // 115
                                1, 1, 1, 1, 1, 1, 0, 0,    // 252
                                1, 1, 1, 1, 0, 1, 1, 1,    // 247
                                1, 1, 1, 1, 0, 0, 1, 0,    // 242
                                1, 0, 1, 0, 0, 1, 0, 0,    // 164
                                1, 1, 1, 1, 0, 1, 1, 1,    // 247
                                1, 1, 0, 1, 1, 1, 1, 1,    // 223
                                1, 1, 1, 0, 1, 1, 1, 1,    // 239
                                0, 0, 1, 1, 1, 1, 0, 1,    // 61
                                0, 1, 0, 1, 1, 1, 1, 1,    // 95
                                0, 1, 1, 0, 1, 1, 1, 0,    // 110
                                1, 0, 1, 1, 1, 0, 1, 0,    // 186
                                1, 1, 1, 0, 1, 1, 1, 1,    // 239
                                0, 0, 1, 0, 0, 1, 0, 0,    // 36
                                1, 1, 1, 1, 1, 0, 1, 0,    // 250
                                1, 1, 0, 1, 1, 0, 1, 1,    // 219
                                1, 0, 1, 1, 1, 1, 0, 0,    // 188
                                1, 1, 0, 1, 0, 0, 1, 1,    // 211
                                1, 1, 1, 1, 1, 0, 0, 1,    // 249
                                1, 0, 1, 0, 0, 1, 0, 0 };  // 164



void turing(int numero, int posx, int posy){
  for (int i=0;i<15;i++) {  
    int offset = i+(numero*15);
    int valor = floor(mono[int(floor(offset/8))]/pow(2,7-offset%8));
  if (valor%2) pixels.setPixelColor(XY(i%3+posx,floor(i/3)+posy),pixels.Color(0,0,255));
  }
} 
*/