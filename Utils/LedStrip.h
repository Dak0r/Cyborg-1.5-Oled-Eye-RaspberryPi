//
// Created by dakor on 9/30/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H
#define CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H


class LedStrip {
private:
    unsigned long timing = 500;
    int ledPins[10] = {100, 101, 102, 103, 104, 105, 106, 107};
    int ledCount = 8;
    int state = 0;
    unsigned long next_timing = 0;
    void clearLeds();

public:
    void init();
    void update(unsigned long time);
    void exit();
};


#endif //CYBORG_1_5_OLED_EYE_RASPBERRYPI_LEDSTRIP_H
