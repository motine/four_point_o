#ifndef MODES_H
#define MODES_H

class Mode {
  public:

    Mode();
    // if loop returns a Mode, the mode will be set by ModeMaster after completing this call.
    virtual Mode* loop() {};
    // called when the sketch initializes
    virtual void init() {};
    // called when the state is entered
    virtual void enter() {};
    // called when the state is left
    virtual void leave() {};
};

class MBreathe : public Mode {
  public:
    MBreathe() : Mode() { };

    virtual Mode* loop();
};


#endif