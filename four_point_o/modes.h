#ifndef MODES_H
#define MODES_H

class Mode {
  public:

    Mode();
    virtual Mode* loop() {};
    virtual void init() {};
    virtual void enter() {};
    virtual void leave() {};
};

class MBreathe : public Mode {
  public:
    MBreathe() : Mode() {};
    virtual Mode* loop();
};


#endif