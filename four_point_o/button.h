#define LONGPRESS_DURATION 10 // ms

// can't use typedef for call back function because something is wrong with the Arduino build chain.

typedef void (*callback_t)(uint8_t button_pin);

class Button {
  public:
    Button(uint8_t pin, callback_t button_down, callback_t button_up, callback_t button_press, callback_t button_longpress);
    void setup();
    void loop();
    
  protected:
    unsigned long millis_down; // when did it go down? 0 if the button is up
    const callback_t callback_button_down;
    const callback_t callback_button_up;
    const callback_t callback_button_press;
    const callback_t callback_button_longpress;
    const uint8_t pin;
};