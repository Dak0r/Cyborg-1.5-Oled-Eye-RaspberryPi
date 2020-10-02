//
// Created by dakor on 9/30/20.
//

#include "LedStrip.h"
#include <iostream>

#include <unistd.h>
#include <wiringPi.h>
#include <mcp23017.h>

/* Pin-Base */
#define BASE 100
/* Baustein-Adresse */
#define I2CADDR 0x20

void LedStrip::init() {
    mcp23017Setup(BASE, I2CADDR);

    // OLED USES BCM MODE SO WE NEED TO USE THIS TOO
    //pinMode(16, OUTPUT);
    //digitalWrite(16, HIGH);

    for(int i=0; i < ledCount; i++){
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], HIGH);
        usleep(100 * 1000);
    }
    for(int i=0; i < ledCount; i++){
        digitalWrite(ledPins[i], 0);
    }

}

void LedStrip::update(unsigned long time) {

    if(next_timing < time){
        state++;
        //printf("LED Strip State:  %d \n", state);
        next_timing = time + timing;

        if(state <= ledCount) { // First: Turn on all leds sequentially
            //printf("LED Strip Sequential:  %d \n", state-1);
            digitalWrite(ledPins[state - 1], HIGH);
        }else if((state > ledCount ) && (state < 2*ledCount)){ // Turn off sequentially
            int ledIndex = state - ledCount - 1;
            //printf("LED Strip Sequential:  %d \n", ledIndex);
            digitalWrite(ledPins[ledIndex], 0);
        }else if((state >= 2*ledCount) && (state < 3*ledCount -1)){ // Second: running light to left
            clearLeds();
            int ledIndex = ledCount - (state - (2*ledCount)+2) ;
            //printf("LED Strip Running Light BACK  %d \n", ledIndex);
            digitalWrite(ledPins[ledIndex], HIGH);
        }else {
            //printf("LED Strip RESET \n");
            state = 1;
            next_timing = 0;
        }
    }
}

void LedStrip::clearLeds() {
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], 0);
    }
}

void LedStrip::exit() {
    digitalWrite (16, 0) ;
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], 0);
    }
}