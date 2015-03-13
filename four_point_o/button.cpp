#include <Arduino.h>
#include "button.h"

// Button::Button(uint8_t pin): pin(pin) {
Button::Button(uint8_t pin, callback_t button_down, callback_t button_up, callback_t button_press, callback_t button_longpress) :
  pin(pin), callback_button_down(button_down), callback_button_up(button_up), callback_button_press(button_press), callback_button_longpress(button_longpress) {
}
void Button::setup() {
  pinMode(pin, INPUT_PULLUP);
}

void Button::loop() {
  int pin_state = digitalRead(pin);
  if (millis_down == 0) { // the button was up before
    if (pin_state == LOW) { // we have a push down
      millis_down = millis();
      callback_button_down(pin);
    }
  } else {
    if (pin_state == HIGH) { // we have a release
      millis_down = 0;
    }
  }
}