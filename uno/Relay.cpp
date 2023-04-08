#include "Relay.h"

Relay::Relay(int ctlPin) {
  _ctlPin = ctlPin;

  pinMode(_ctlPin, INPUT);
}

void Relay::close() {
  digitalWrite(_ctlPin, HIGH);
}

void Relay::open() {
  digitalWrite(_ctlPin, LOW);
}
