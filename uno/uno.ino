//
//
//void setup(){
//  Serial.begin(9600);
//  Serial.println("uno.ino");
//}
//
//void loop(){
//  
//}

//www.elegoo.com
//2016.12.08
#include "/Users/andrewbradt/exhibition_may_2023/arduino/lib/ultrasound.h"
//#define TRIG_PIN 2
//#define ECHO_PIN 4
//SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
//long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
//   a=sr04.Distance();
//   if(a < 30) {
//    Serial.print(a);
//    Serial.println("cm"); 
//   }
//   delay(100);
     Serial.println(getDistance());
}
