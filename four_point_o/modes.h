#ifndef MODES_H
#define MODES_H

class Mode {
  public:
    Mode();
    // if loop returns a Mode, the mode will be set by ModeMaster after completing this call.
    virtual Mode* loop() { return NULL; };
    // called when the sketch initializes
    virtual void init() {};
    // called when the state is entered
    virtual void enter() {};
    // called when the state is left
    virtual void leave() {};
};

class MOff : public Mode {
  public:
    MOff() : Mode() { };
    void enter();
};
extern MOff m_off;

class MBreathe : public Mode {
  public:
    MBreathe() : Mode() { };
    virtual Mode* loop();
};
extern MBreathe m_breathe;

class MFlow : public Mode {
  public:
    MFlow() : Mode() { };
    virtual Mode* loop();
};
extern MFlow m_flow;

class MColor : public Mode {
  public:
    MColor(uint32_t color) : Mode(), color(color) { };
    void enter();
    uint32_t color;
};
extern MColor m_color_a;
extern MColor m_color_b;

#endif