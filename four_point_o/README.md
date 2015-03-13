# four\_point\_o

A little project with 5 buttons a LED matrix. 

## Programming

If you want to change PINs and durations of animations, please go to `resources.h`.

If you want to change the initial mode when the program starts, please see `resources.cpp` and change the line with `ModeMaster mode_master = ModeMaster(&m_color_a);`. Change `m_color_a` to another mode (e.g. `m_off, m_breathe, m_flow, m_color_a, m_color_b`, definitions in `modes.h`).

If you want to change the color of the simple modes, please see `modes.cpp` and find the line `extern MColor m_color_a = MColor(strip.Color(255,0,0));`.

## Libraries used

- Adafruit NeoPixel ([GitHub](https://github.com/adafruit/Adafruit_NeoPixel) & see Uberguide above)

## Credits

I used to following software:

* TextMate for text editing
* Arduino GUI for compiling and uploading (with the external editor setting enabled)