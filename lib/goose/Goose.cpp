#include "Goose.h"

struct GooseParams {
  int nearCtlPin;
  int farCtlPin;
  void (*nearCallback) ();
  void (*farCallback) ();
};

Goose::Goose(GooseParams params) : 
  _nearRelay(params.nearCtlPin), 
  _farRelay(params.farCtlPin), 
  _nearCallback(params.nearCallback), 
  _farCallback(params.farCallback) {
}

void Goose::near() {
  _nearRelay.allowCurrent();
  _farRelay.blockCurrent();
  _nearCallback();
}

void Goose::far() {
  _nearRelay.blockCurrent();
  _farRelay.allowCurrent();
  _farCallback();
}

void Goose::off() {
  _nearRelay.blockCurrent();
  _farRelay.blockCurrent();
}
