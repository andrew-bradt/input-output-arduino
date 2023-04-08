#ifndef RELAY_H
#define RELAY_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
class Relay {

public:
	Relay(int ctlPin);
  void close();
  void open();

private:
  int _ctlPin;
};
#endif
