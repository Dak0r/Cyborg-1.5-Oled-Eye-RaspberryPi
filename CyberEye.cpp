#include "CyberEye.h"
#include <iostream>
#include <unistd.h>
#include <wiringPi.h>


void CyberEye::buildConfig(EyeConfig *eyeConfig) {
    eyeConfig->blink_timing_duration.min = 65;
    eyeConfig->blink_timing_duration.max = 85;

    eyeConfig->blink_timing_in_between.min = 1000;
    eyeConfig->blink_timing_in_between.max = 7000;

    eyeConfig->eyelid_upper_y_range.min = 0.1;
    eyeConfig->eyelid_upper_y_range.max = 0.5;
    eyeConfig->eyelid_lower_y_range.min = 0.9;
    eyeConfig->eyelid_lower_y_range.max = 0.5;

    eyeConfig->eyelid_movement_speed = 0.5;

    eyeConfig->pupil_size_speed = 0.2;
}


void CyberEye::setup(int argc, char **argv) {

    std::cout << "Hello World" << std::endl;

    buildConfig(&eye_config);

    eye.init_pos();

}

bool CyberEye::loop(unsigned long now) {

    bool exit_application = false;

    eye.update(now);

    return exit_application;
}

