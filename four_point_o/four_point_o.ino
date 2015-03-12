#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "resources.h"
#include "modes.h"
#include "mode_master.h"

ModeMaster mode_master = ModeMaster();

void setup() {
  Serial.begin(9600);
  setup_resources();
}

void loop() {
  mode_master.loop();
}