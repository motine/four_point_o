#ifndef RESOURCES_H
#define RESOURCES_H

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define MAX_BRIGHTNESS 10

class Resources {
  public:
    Resources();

    void init();

    Adafruit_NeoMatrix matrix;
};

extern Resources resources;

#endif
