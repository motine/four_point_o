#ifndef RESOURCES_H
#define RESOURCES_H

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define MAX_BRIGHTNESS 10

extern Adafruit_NeoMatrix matrix;

void setup_resources();

#endif
