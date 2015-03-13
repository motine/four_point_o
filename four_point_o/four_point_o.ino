#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "modes.h"
#include "mode_master.h"
#include "resources.h"

void setup() {
  setup_resources();
}

void loop() {
  mode_master.loop();
}