#ifndef GOOSE_H
#define GOOSE_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <inttypes.h>

enum State {
  OFF = 0,
  FAR = 1,
  NEAR = 2,
};
struct GooseParams {
  void (*enterNear) ();
  void (*enterFar) ();
  void (*exitNear) ();
  void (*exitFar) ();
};

class Goose {
  
public:
  Goose(GooseParams params);
  void setState(State state);

private:
  State _state;
  void (*_enterNear) ();
  void (*_enterFar) ();
  void (*_exitNear) ();
  void (*_exitFar) ();
  void _dispatchHandler(State state);
  void _handleNear();
  void _handleFar();
  void _handleOff();
};
#endif
