#ifndef DistanceSensor_H
#define DistanceSensor_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
#include "SR04.h"

class DistanceSensor {
	public:
		DistanceSensor(int inPin, int outPin);
    int getDistance();

	private:
    SR04 _sensor;
};
#endif
