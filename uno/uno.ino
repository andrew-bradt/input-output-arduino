#include "Consts.h"
#include "Goose.h"
#include "Relay.h"
#include "DistanceMonitor.h"

Relay nearRelay = Relay(NEAR_CTL_PIN);
Relay farRelay = Relay(FAR_CTL_PIN);

Goose goose = Goose({
   .enterNear = [](){
      nearRelay.close();
      Serial.println(SERIAL_MSG_NEAR);
   },
   .enterFar = [](){
      farRelay.close();
      Serial.println(SERIAL_MSG_FAR);
   },
   .exitNear = [](){
      nearRelay.open();
   },
   .exitFar = [](){
      farRelay.open();
   }
});

DistanceMonitor distanceMonitor = DistanceMonitor({
   .sensorSettings = {ECHO_PIN, TRIGGER_PIN},
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
