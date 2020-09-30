//
// Created by dakor on 9/30/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H
#define CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H


class LedStrip {
private:
    unsigned long timing = 500;
    int ledPins[10] = {108, 109, 110, 111, 112, 113, 114, 107, 106, 105};
    int ledCount = 10;
    int state = 0;
    unsigned long next_timing = 0;

public:
    void init();
    void update(unsigned long time);
    void exit();
};


#endif //CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H
