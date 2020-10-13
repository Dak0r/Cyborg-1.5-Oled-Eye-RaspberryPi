//
// Created by dakor on 10/13/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPBERRYPI_POWEROFFBUTTON_H
#define CYBORG_1_5_OLED_EYE_RASPBERRYPI_POWEROFFBUTTON_H


class PowerOffButton {
    private:
        const int pinPowerOff = 6;
        bool shutdownOnExit = false;


    public:
        void init();
        bool update(unsigned long time);
        void exit();
};


#endif //CYBORG_1_5_OLED_EYE_RASPBERRYPI_POWEROFFBUTTON_H
