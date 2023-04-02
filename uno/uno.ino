#include "/Users/andrewbradt/exhibition_may_2023/arduino/lib/ultrasound.h"

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   Serial.println(getDistance());
}
