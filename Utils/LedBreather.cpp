//
// Created by dakor on 10/13/20.
//

#include "LedBreather.h"

void LedBreather::init() {
    // OLED USES BCM MODE SO WE NEED TO USE THIS TOO
    pinMode(pinBlue, OUTPUT);
    digitalWrite(pinBlue, commonAnodeLedOn);
    pinMode(pinGreen, OUTPUT);
    digitalWrite(pinGreen, commonAnodeLedOn);
}

void LedBreather::update(unsigned long time) {

    if(time > nextStateTime){


        state++;

        if(state == 1){
            digitalWrite(pinBlue, commonAnodeLedOn);
            pinMode(pinGreen, OUTPUT);
            digitalWrite(pinGreen, commonAnodeLedOff);
            nextStateTime = time + breathTime;
        }else if(state == 2){
            digitalWrite(pinBlue, commonAnodeLedOn);
            pinMode(pinGreen, OUTPUT);
            digitalWrite(pinGreen, commonAnodeLedOn);
            nextStateTime = time + breathTimeTrans;
        }else if(state == 3){
            digitalWrite(pinBlue, commonAnodeLedOff);
            pinMode(pinGreen, OUTPUT);
            digitalWrite(pinGreen, commonAnodeLedOn);
            nextStateTime = time + breathTime;
        }else if(state == 4){
            digitalWrite(pinBlue, commonAnodeLedOn);
            pinMode(pinGreen, OUTPUT);
            digitalWrite(pinGreen, commonAnodeLedOn);
            nextStateTime = time + breathTimeTrans;
            state = 0;
        }
    }

}

void LedBreather::exit() {
    // OLED USES BCM MODE SO WE NEED TO USE THIS TOO
    digitalWrite(pinBlue, commonAnodeLedOn);
    digitalWrite(pinGreen, commonAnodeLedOff);
}