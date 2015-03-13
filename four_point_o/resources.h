#ifndef RESOURCES_H
#define RESOURCES_H

#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include "button.h"
#include "mode_master.h"

#define LED_PIN 6
#define LED_COUNT 13
#define MAX_BRIGHTNESS 10

#define EULER 2.7182818284
#define PI 3.14159265359

#define BREATHE_DURATION 4000
#define FLOW_SPEED_DIVISOR 20 // higher value means slower

#define BUTTON_OFF_PIN 8
#define BUTTON_BREATHE_PIN 9
#define BUTTON_COLOR_A_PIN 10
#define BUTTON_COLOR_B_PIN 11
#define BUTTON_FLOW_PIN 12

extern ModeMaster mode_master;
extern Adafruit_NeoPixel strip;
extern Button button_breathe;

void setup_resources();
void loop_resources();

#endif
