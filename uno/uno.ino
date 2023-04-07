#include "Consts.h"
#include "Goose.h"

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
   Serial.begin(9600);
   Serial.println("Starting");
}

void loop() {
   Serial.println("near (on), far(off)");
   goose.near();
   delay(1000);

   Serial.println("far (on), near(off)");
   goose.far();
   delay(1000);
}
