#ifndef GOOSE_H
#define GOOSE_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <inttypes.h>
#include "Relay.h"

struct GooseParams {
  int nearCtlPin;
  int farCtlPin;
  void (*nearCallback) ();
  void (*farCallback) ();
};

class Goose {
  
public:
  Goose(GooseParams params);
  void near();
  void far();
  void off();

private:
  Relay _nearRelay;
  Relay _farRelay;
  void (*_nearCallback) ();
  void (*_farCallback) ();
};
#endif
