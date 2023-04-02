#include "SR04.h"
#define TRIG_PIN 2
#define ECHO_PIN 4
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;



int getDistance() {
	a=sr04.Distance();
	if (a < 30) {
		Serial.println(a);
	}
	delay(10);
}

