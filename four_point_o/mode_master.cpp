#include <Arduino.h>
#include "mode_master.h"
#include "modes.h"
#include "resources.h"

ModeMaster::ModeMaster() : mode_breathe(new MBreathe()) {
  current_mode = mode_breathe;
  
  // resources.matrix.fillScreen(resources.matrix.Color(255,0,0));
  // resources.matrix.show();
  // Serial.print(F("Constructor!"));
}

ModeMaster::~ModeMaster() {
  delete mode_breathe;
}

void ModeMaster::loop() {
  current_mode->loop();
}

void ModeMaster::setModeUnlessNull(Mode* mode) {
  if (mode != NULL) {
    if (current_mode != NULL) {
      current_mode->leave();
    }
    current_mode = mode;
    current_mode->enter();
  }
}
