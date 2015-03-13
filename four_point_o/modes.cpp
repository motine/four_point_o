#include <Arduino.h>
#include "resources.h"
#include "modes.h"

Mode::Mode() {
}

extern MOff m_off = MOff();
extern MBreathe m_breathe = MBreathe();
extern MFlow m_flow = MFlow();
extern MColor m_color_a = MColor(strip.Color(255,0,0));
extern MColor m_color_b = MColor(strip.Color(0,255,0));

void fill_all(uint32_t color) {
  for (uint8_t i=0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void MOff::enter() {
  fill_all(strip.Color(0, 0, 0));
  strip.show();
}

Mode* MBreathe::loop() {
  float t = (millis() % (uint16_t)(BREATHE_DURATION)) / (float)BREATHE_DURATION;
  uint8_t component = 255 * (pow(EULER, sin(2*PI*t)) - 0.35) / (EULER - 0.35);
  // float percent = sin(PI*t);
  fill_all(strip.Color(component, component, component));
  strip.show();
  return NULL;
}

// converts a HSV to RGB values. For optimization we assume full S and full V.
// hue is between 0.0 and 1.0.
// for conversion for:
// - http://www.rapidtables.com/convert/color/hsv-to-rgb.htm
// - http://en.wikipedia.org/wiki/HSL_and_HSV#From_HSV
uint32_t hue_to_rgb(uint16_t hue) {
  // uint8_t h = hue / 60;
  // float x = 1 - abs(fmod(hue / 60.0, 2.0) - 1);
  // uint8_t xi = x * 255;

  uint8_t h = hue / 60;
  uint16_t x = 255*(1 - abs(fmod(hue / 60.0, 2.0) - 1));
  
  switch (h) {
    case 0:  return strip.Color(255,   x,   0);
    case 1:  return strip.Color(  x, 255,  0);
    case 2:  return strip.Color(  0, 255,  x);
    case 3:  return strip.Color(  0,   x, 255);
    case 4:  return strip.Color(  x,   0, 255);
    default: return strip.Color(255,   0,  x);
  }
}

Mode* MFlow::loop() {
  fill_all(hue_to_rgb((millis() / FLOW_SPEED_DIVISOR % 360)));
  strip.show();
  return NULL;
}

Mode* MColor::loop() {
  fill_all(color);
  strip.show();
  return NULL;
}