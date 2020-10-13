//
// Created by dakor on 10/13/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDBREATHER_H
#define CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDBREATHER_H

#include <wiringPi.h>

class LedBreather {
private:
    int state = 0;
    const int breathTime = 1000;
    const int breathTimeTrans = 250;
    long nextStateTime = 0;

    unsigned long next_timing = 0;
    const int pinBlue = 19;
    const int pinGreen = 26;
    const int commonAnodeLedOff = HIGH;
    const int commonAnodeLedOn = LOW;


public:
    void init();
    void update(unsigned long time);
    void exit();
};


#endif //CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDBREATHER_H
