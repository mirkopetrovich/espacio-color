#include <Adafruit_NeoPixel.h>

#define BRILLO 20
Adafruit_NeoPixel pixels(320, 6, NEO_GRB + NEO_KHZ800);
const bool mono[] = { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 
                      1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
                      1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
                      1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,
                      1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,
                      1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
                      1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1,
                      1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0,
                      1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
                      1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
                      0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
                      1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0,
                      1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1,
                      1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0,
                      1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1,
                      1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0 };

const bool bocho[] = { 1, 1, 1, 1, 0, 1, 1, 0,    // 246
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


const unsigned char pocho[] = { 246, 223, 146, 95, 31, 63, 44, 251, 121, 62, 115, 252, 247, 242, 164, 247, 223, 239, 61, 95, 110, 186, 239, 36, 250, 219, 188, 211, 249, 164 };



const uint8_t kMatrixWidth = 40;
const uint8_t kMatrixHeight = 8;
#define LAST_VISIBLE_LED 319

void setup() {
  pixels.begin();
  pixels.clear();
}

void loop() {
  rhex(0, 0, 2);
  rhex(0, 4, 2);
  rhex(0, 8, 2);
  rhex(0, 12, 2);
  rhex(0, 16, 2);
  pixels.show();
  delay(300);
  pixels.clear();
}

void rhex(int numero, int posX, int posY) {
  for (int i = 0; i < 15; i++) {
    if (mono[i + (numero * 15)]) pixels.setPixelColor(XY((i % 3 + posX), floor(i / 3) + posY), pixels.Color(BRILLO,BRILLO,BRILLO));
  }
}

uint16_t XY(uint16_t x, uint16_t y) {
  if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint16_t XYTable[] = {
     7,  15,  23,  31,  39,  47,  55,  63,  71,  79,  87,  95, 103, 111, 119, 127, 135, 143, 151, 159, 167, 175, 183, 191, 199, 207, 215, 223, 231, 239, 247, 255, 263, 271, 279, 287, 295, 303, 311, 319,
     6,  14,  22,  30,  38,  46,  54,  62,  70,  78,  86,  94, 102, 110, 118, 126, 134, 142, 150, 158, 166, 174, 182, 190, 198, 206, 214, 222, 230, 238, 246, 254, 262, 270, 278, 286, 294, 302, 310, 318,
     5,  13,  21,  29,  37,  45,  53,  61,  69,  77,  85,  93, 101, 109, 117, 125, 133, 141, 149, 157, 165, 173, 181, 189, 197, 205, 213, 221, 229, 237, 245, 253, 261, 269, 277, 285, 293, 301, 309, 317,
     4,  12,  20,  28,  36,  44,  52,  60,  68,  76,  84,  92, 100, 108, 116, 124, 132, 140, 148, 156, 164, 172, 180, 188, 196, 204, 212, 220, 228, 236, 244, 252, 260, 268, 276, 284, 292, 300, 308, 316,
     3,  11,  19,  27,  35,  43,  51,  59,  67,  75,  83,  91,  99, 107, 115, 123, 131, 139, 147, 155, 163, 171, 179, 187, 195, 203, 211, 219, 227, 235, 243, 251, 259, 267, 275, 283, 291, 299, 307, 315,
     2,  10,  18,  26,  34,  42,  50,  58,  66,  74,  82,  90,  98, 106, 114, 122, 130, 138, 146, 154, 162, 170, 178, 186, 194, 202, 210, 218, 226, 234, 242, 250, 258, 266, 274, 282, 290, 298, 306, 314,
     1,   9,  17,  25,  33,  41,  49,  57,  65,  73,  81,  89,  97, 105, 113, 121, 129, 137, 145, 153, 161, 169, 177, 185, 193, 201, 209, 217, 225, 233, 241, 249, 257, 265, 273, 281, 289, 297, 305, 313,
     0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256, 264, 272, 280, 288, 296, 304, 312
  };

  uint16_t i = (y * kMatrixWidth) + x;
  uint16_t j = XYTable[i];
  return j;
}