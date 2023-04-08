#include "Goose.h"

Goose::Goose(GooseParams params) : 
  _state(OFF),
  _enterNear(params.enterNear),
  _enterFar(params.enterFar),
  _exitNear(params.exitNear),
  _exitFar(params.exitFar)
{}

void Goose::setState(State state) {
  if (_state == state) return;

  _dispatchHandler(state);
  _state = state;
}

void Goose::_dispatchHandler(State state) {
  if (state == OFF) {
    _handleOff();
  } else if (state == FAR) {
    _handleFar();
  } else if (state == NEAR) {
    _handleNear();
  }
}

void Goose::_handleNear() {
  _enterNear();
  _exitFar();
}

void Goose::_handleFar() {
  _enterFar();
  _exitNear();
}

void Goose::_handleOff() {
  _exitNear();
  _exitFar();
}
