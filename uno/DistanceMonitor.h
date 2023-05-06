#ifndef DISTANCEMONITOR_H
#define DISTANCEMONITOR_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
#include "DistanceSensor.h"

struct Range {
	int min;
	int max;
};

struct IntervalSettings {
	int wait;
	int count;
};

struct DistanceSetting {
	Range range;
	void (*withinRangeHandler) ();
};

struct SensorSettings {
	int inPin;
	int outPin;
};

struct DistanceMonitorParams {
	SensorSettings sensorSettings;
	IntervalSettings intervalSettings;
	DistanceSetting nearSettings;
	DistanceSetting farSettings;
};

class DistanceMonitor {
	public:
		DistanceMonitor(DistanceMonitorParams params);
		void handleDistance();

	private:
		DistanceSensor _sensor;
		IntervalSettings _intervalSettings;
		Range _nearRange;
		Range _farRange;
		void (*_nearHandler) ();
		void (*_farHandler) ();
		int _distance;
		void _getDistance();
		bool _isNear();
		bool _isFar();
};
#endif
