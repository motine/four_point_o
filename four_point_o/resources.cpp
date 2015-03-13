#include "resources.h"

void button_press(uint8_t pin) {
  Serial.println(F("HUhuhu"));
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

ModeMaster mode_master = ModeMaster(&m_color_a);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Button button_off =     Button(BUTTON_OFF_PIN, button_press, NULL, button_press, NULL);
Button button_breathe = Button(BUTTON_BREATHE_PIN, button_press, NULL, button_press, NULL);
Button button_color_a = Button(BUTTON_COLOR_A_PIN, button_press, NULL, button_press, NULL);
Button button_color_b = Button(BUTTON_COLOR_B_PIN, button_press, NULL, button_press, NULL);
Button button_flow =    Button(BUTTON_FLOW_PIN, button_press, NULL, button_press, NULL);

void setup_resources() {
  Serial.begin(9600);
  // LEDs
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();

  button_off.setup();
  button_breathe.setup();;
  button_color_a.setup();
  button_color_b.setup();
  button_flow.setup();
}
void loop_resources() {
  mode_master.loop();
  button_off.loop();
  button_breathe.loop();
  button_color_a.loop();
  button_color_b.loop();
  button_flow.loop();
}