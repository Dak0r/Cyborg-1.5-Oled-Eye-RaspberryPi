//
// Created by dakor on 8/25/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H
#define CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H

#include "Natural-Eye-Behavior/Eye.h"
#include "Natural-Eye-Behavior/EyeConfig.h"
#include "Utils/LedStrip.h"
#include "Utils/LedBreather.h"
#include "Utils/PowerOffButton.h"
#include "Utils/MPU6050.h"

using namespace EyeBehavior;

class CyberEye
{
private:
    EyeConfig eye_config;
    Eye eye;
    LedStrip ledStrip;
    LedBreather ledBreather;
    PowerOffButton powerOffButton;
    MPU6050 mpu6050 = MPU6050(0x68);
    std::vector<EyeModifier*>* active_modifiers;

    float gyroXInit = 0;
    float gyroYInit = 0;
    bool gyroInitSet = false;
    void buildConfig(EyeConfig *eyeConfig);
    void setupEyeModifiers();

    void render();
    void setupOLED();
    void shutdownOLED();


public:
    CyberEye() {
    }
    void setup(int argc, char* argv[]);

    bool loop(unsigned long now);

    void quit();

};
#endif //CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H
