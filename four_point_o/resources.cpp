#include "resources.h"

void button_press(uint8_t pin) {
  switch (pin) {
    case BUTTON_OFF_PIN: 
      mode_master.setModeUnlessNull(&m_off);
      break;
    case BUTTON_BREATHE_PIN:
      mode_master.setModeUnlessNull(&m_breathe);
      break;
    
    case BUTTON_COLOR_A_PIN:
      mode_master.setModeUnlessNull(&m_color_a);
      break;
    case BUTTON_COLOR_B_PIN:
      mode_master.setModeUnlessNull(&m_color_b);
      break;
    case BUTTON_FLOW_PIN:
      mode_master.setModeUnlessNull(&m_flow);
      break;
  }
}

ModeMaster mode_master = ModeMaster(&m_off);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Button button_breathe = Button(BUTTON_BREATHE_PIN, button_press, NULL, button_press, NULL);

void setup_resources() {
  Serial.begin(9600);
  // LEDs
  strip.begin();
  strip.setBrightness(MAX_BRIGHTNESS);
  strip.show();

  button_breathe.setup();
};

void loop_resources() {
  mode_master.loop();
  button_breathe.loop();
}