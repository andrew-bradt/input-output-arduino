#ifndef CONSTANTS_H
#define CONSTANTS_H

// Relay Pins
const int NEAR_CTL_PIN =  2;
const int FAR_CTL_PIN =  3;

// Sensor Pins
const int ECHO_PIN =  4;
const int TRIGGER_PIN =  5;


const int SERIAL_MSG_NEAR =  0;
const int SERIAL_MSG_FAR =  1;

const int PING_DELAY_MS =  10;
const int PING_COUNT =  30;

const int NEAR_MIN_CM =  10;
const int NEAR_MAX_CM =  30;
const int FAR_MIN_CM =  40;
const int FAR_MAX_CM =  100;

#endif
