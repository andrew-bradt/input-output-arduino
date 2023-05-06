#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int inPin, int outPin) : _sensor(outPin, inPin) {}

int DistanceSensor::getDistance() { 
  return _sensor.Distance(); 
}
