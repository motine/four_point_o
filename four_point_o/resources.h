#ifndef RESOURCES_H
#define RESOURCES_H

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define MAX_BRIGHTNESS 10

class Resources {
  public:
    Resources() : 
      matrix(Adafruit_NeoMatrix(8, 8, LED_PIN, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800)) { };

    void init() {
      // LEDs
      matrix.begin();
      matrix.setTextWrap(false);
      matrix.setBrightness(MAX_BRIGHTNESS);
      matrix.fillScreen(matrix.Color(0,0,0));
      matrix.show();
    };
    Adafruit_NeoMatrix matrix;
};

extern Resources resources;

#endif
