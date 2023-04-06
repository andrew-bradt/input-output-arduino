#include "Relay.h"

Relay::Relay(int ctlPin) {
  _ctlPin = ctlPin;

  pinMode(_ctlPin, INPUT);
}

void Relay::allow_current() {
  digitalWrite(_ctlPin, HIGH);
}

void Relay::block_current() {
  digitalWrite(_ctlPin, LOW);
}
