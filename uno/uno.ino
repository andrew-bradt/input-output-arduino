#include "/Users/andrewbradt/exhibition_may_2023/arduino/lib/goose/Goose.h"
#include "Consts.h"

Goose goose = Goose({
   .nearCtlPin = NEAR_CTL_PIN,
   .farCtlPin = FAR_CTL_PIN, 
   .nearCallback = [](){
      Serial.println(SERIAL_MSG_NEAR);
   },
   .farCallback = [](){
      Serial.println(SERIAL_MSG_FAR);
   }
});

void setup() {
}

void loop() {
}
