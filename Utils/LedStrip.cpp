//
// Created by dakor on 9/30/20.
//

#include "LedStrip.h"

#include <unistd.h>
#include <wiringPi.h>
#include <mcp23017.h>

/* Pin-Base */
#define BASE 100
/* Baustein-Adresse */
#define I2CADDR 0x20

void LedStrip::init() {
    //wiringPiSetup () ;
    mcp23017Setup(BASE, I2CADDR);

    // OLED USES BCM MODE SO WE NEED TO USE THIS TOO
    pinMode(16, OUTPUT);
    digitalWrite(16, HIGH);


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
        next_timing = time + timing;

        if(state <= ledCount) { // First: Turn on all leds sequentually
            digitalWrite(ledPins[state - 1], HIGH);
        }else if(state > ledCount + 1){ // Second: running light to right
            for (int i = 0; i < ledCount; i++) {
                digitalWrite(ledPins[i], 0);
            }
            digitalWrite(ledPins[state - (ledCount+2)], HIGH);
        }else if(state >= 2*ledCount + 2){ // Second: running light to left
            for (int i = 0; i < ledCount; i++) {
                digitalWrite(ledPins[i], 0);
            }
            digitalWrite(ledPins[ledCount - (state - (2*ledCount+2))], HIGH);
        }else if(state >= 3*ledCount + 3){
            state = 0;
        }
    }
}

void LedStrip::exit() {
    digitalWrite (16, 0) ;
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], 0);
    }
}