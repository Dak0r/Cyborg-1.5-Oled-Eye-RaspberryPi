//
// Created by dakor on 10/13/20.
//

#include "PowerOffButton.h"
#include <iostream>
#include <wiringPi.h>

void PowerOffButton::init() {

    // POWER OF SWITCH, CONNECT TO GROUND TO SHUTDOWN //TODO: IMPLEMENT THIS
    pinMode(pinPowerOff, INPUT);
    pullUpDnControl(pinPowerOff, PUD_UP);
}

bool PowerOffButton::update(unsigned long time) {

    if(digitalRead(pinPowerOff) == LOW){ // PullUp active, so push button to ground
        printf("POWER OFF GPIO BUTTON PRESSED !!!! WILL SHUTDOWN\n");
        shutdownOnExit = true;
        return true;
    }
    return false;
}

void PowerOffButton::exit() {
    if(shutdownOnExit){
        printf("Calling Shutdown (requires admin privileges\n)");
        system("shutdown -hP now");
    }
}