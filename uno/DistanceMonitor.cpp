#include "DistanceMonitor.h"

DistanceMonitor::DistanceMonitor(DistanceMonitorParams params) :
  _sensor(params.sensorSettings.inPin, params.sensorSettings.outPin),
  _intervalSettings(params.intervalSettings),
  _nearRange(params.nearSettings.range),
  _farRange(params.farSettings.range),
  _nearHandler(params.nearSettings.withinRangeHandler),
  _farHandler(params.farSettings.withinRangeHandler),
  _distance(params.farSettings.range.min)
{}

void DistanceMonitor::handleDistance() {
  _getDistance();

  if (_isNear()) _nearHandler();
  else if (_isFar()) _farHandler();

  delay(1);
}

void DistanceMonitor::_getDistance() {
  _distance = _sensor.getDistance();
}

bool DistanceMonitor::_isFar() {
  return ((_distance >= _farRange.min) && (_distance <= _farRange.max));
}

bool DistanceMonitor::_isNear() {
  return ((_distance >= _nearRange.min) && (_distance <= _nearRange.max));
}
