#ifndef DISTANCEMONITOR_H
#define DISTANCEMONITOR_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>
#include <SR04.h>

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

struct DistanceMonitorParams {
	SR04 sensor;
	IntervalSettings intervalSettings;
	DistanceSetting nearSettings;
	DistanceSetting farSettings;
};

class DistanceMonitor {
	public:
		DistanceMonitor(DistanceMonitorParams params);
		void handleDistance();

	private:
		SR04 _sensor;
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
