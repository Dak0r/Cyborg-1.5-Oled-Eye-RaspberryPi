//
// Created by dakor on 8/25/20.
//

#ifndef CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H
#define CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H

#include "Natural-Eye-Behavior/Eye.h"
#include "Natural-Eye-Behavior/EyeConfig.h"

using namespace EyeBehavior;

class CyberEye
{
private:
    EyeConfig eye_config;
    Eye eye;

    void buildConfig(EyeConfig *eyeConfig);

public:
    CyberEye() : eye(&eye_config){
    }
    void setup(int argc, char* argv[]);

    bool loop(unsigned long now);

};
#endif //CYBORG_1_5_OLED_EYE_RASPERRYPI_CYBEREYE_H
