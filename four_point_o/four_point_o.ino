#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "resources.h"
#include "modes.h"
#include "mode_master.h"

ModeMaster mode_master = ModeMaster();

void setup() {
  // Serial
  Serial.begin(9600);
  
  resources.init();
}

uint8_t counter = 0;

void loop() {
  mode_master.loop();
}