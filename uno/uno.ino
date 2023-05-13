#include "Consts.h"
#include "Goose.h"
#include "Relay.h"
#include "SR04.h"
#include "DistanceMonitor.h"

SR04 sr04 = SR04(ECHO_PIN, TRIGGER_PIN);
Relay nearRelay = Relay(NEAR_CTL_PIN);

Goose goose = Goose({
   .enterNear = [](){
      nearRelay.close();
      Serial.println(SERIAL_MSG_NEAR);
   },
   .enterFar = [](){ Serial.println(SERIAL_MSG_FAR); },
   .exitNear = [](){ nearRelay.open(); },
   .exitFar = [](){}
});

DistanceMonitor distanceMonitor = DistanceMonitor({
   .sensor = sr04,
   .intervalSettings = {PING_DELAY_MS, PING_COUNT},
   .nearSettings = {
      {NEAR_MIN_CM, NEAR_MAX_CM},
      [](){ goose.setState(NEAR); }
   },
   .farSettings = {
      {FAR_MIN_CM, FAR_MAX_CM},
      [](){ goose.setState(FAR); }
   }
});

void setup() {
   delay(1000);
   Serial.begin(9600);
}

void loop() {
   distanceMonitor.handleDistance();
}
