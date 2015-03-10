#include <Arduino.h>
#include "mode_master.h"
#include "modes.h"
#include "resources.h"

ModeMaster::ModeMaster() : 
  mode_breathe(new MBreathe()) {

  setModeUnlessNull(mode_breathe);
}

ModeMaster::~ModeMaster() {
  delete mode_breathe;
}

void ModeMaster::loop() {
  setModeUnlessNull(current_mode->loop());
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
