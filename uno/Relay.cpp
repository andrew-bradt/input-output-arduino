#include "Relay.h"

Relay::Relay(int ctlPin) {
  _ctlPin = ctlPin;

  pinMode(_ctlPin, INPUT);
}

void Relay::allowCurrent() {
  digitalWrite(_ctlPin, HIGH);
}

void Relay::blockCurrent() {
  digitalWrite(_ctlPin, LOW);
}
