#include "Consts.h"
#include "Goose.h"
#include "Relay.h"

Relay nearRelay = Relay(NEAR_CTL_PIN);
Relay farRelay = Relay(FAR_CTL_PIN);

GooseParams gooseParams = {
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
};

Goose goose = Goose(gooseParams);

void setup() {
   delay(5000);
   Serial.begin(9600);
   Serial.println("Starting, both off");
}

void loop() {
   Serial.println("near (on), far(off)");
   goose.setState(NEAR);
   delay(1000);

   Serial.println("far (on), near(off)");
   goose.setState(FAR);
   delay(1000);
}
