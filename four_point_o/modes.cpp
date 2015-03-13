#include <Arduino.h>
#include "resources.h"
#include "modes.h"

#define EULER 2.7182818284
#define PI 3.14159265359
#define BREATHE_DURATION 4000

Mode::Mode() {
}

extern MBreathe m_breathe = MBreathe();
extern MFlow m_flow = MFlow();

Mode* MBreathe::loop() {
  float t = (millis() % (uint16_t)(BREATHE_DURATION)) / (float)BREATHE_DURATION;
  float percent = (pow(EULER, sin(2*PI*t)) - 0.35) / (EULER - 0.35);
  // float percent = sin(PI*t);
  uint8_t component = 255 * percent;
  matrix.fillScreen(matrix.Color(component, component, component));
  matrix.show();

  return NULL;
}

Mode* MFlow::loop() {
  float t = (millis() % (uint16_t)(BREATHE_DURATION)) / (float)BREATHE_DURATION;
  float percent = (pow(EULER, sin(2*PI*t)) - 0.35) / (EULER - 0.35);
  // float percent = sin(PI*t);
  uint8_t component = 255 * percent;
  matrix.fillScreen(matrix.Color(component, component, component));
  matrix.show();

  return NULL;
}