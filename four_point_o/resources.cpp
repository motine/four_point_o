#include "resources.h"

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, LED_PIN, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

void setup_resources() {
  // LEDs
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(MAX_BRIGHTNESS);
  matrix.fillScreen(matrix.Color(0,0,0));
  matrix.show();
};