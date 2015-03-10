#include <Arduino.h>
#include "resources.h"
#include "modes.h"

#define EULER 2.7182818284
#define PI 3.14159265359
#define DURATION 4000

Mode::Mode() {
};

Mode* MBreathe::loop() {
  float t = (millis() % (uint16_t)(DURATION)) / (float)DURATION;
  float percent = (pow(EULER, sin(2*PI*t)) - 0.35) / (EULER - 0.35);
  // float percent = sin(PI*t);
  uint8_t component = 255 * percent;
  resources.matrix.fillScreen(resources.matrix.Color(component, component, component));
  resources.matrix.show();

  return NULL;
}