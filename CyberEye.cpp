#include <iostream>
#include <unistd.h>
#include <chrono>
#include <signal.h>
#include "CyberEye.h"

#include "Natural-Eye-Behavior/Eye.h"
#include "Natural-Eye-Behavior/EyeConfig.h"

using namespace EyeBehavior;

bool cancel;
void sigint_handler(int sig) {
    printf("^C caught\n");
    cancel = true;
}

unsigned long  millis(){
    auto time = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

}

void buildConfig(EyeConfig *eyeconfig) {
    eyeconfig->blink_timing_duration.min = 65;
    eyeconfig->blink_timing_duration.max = 85;

    eyeconfig->blink_timing_in_between.min = 1000;
    eyeconfig->blink_timing_in_between.max = 7000;

    eyeconfig->eyelid_upper_y_range.min = 0.1;
    eyeconfig->eyelid_upper_y_range.max = 0.5;
    eyeconfig->eyelid_lower_y_range.min = 0.9;
    eyeconfig->eyelid_lower_y_range.max = 0.5;

    eyeconfig->eyelid_movement_speed = 0.5;

    eyeconfig->pupil_size_speed = 0.2;
}

int main(int argc, char* argv[]) {

    signal(SIGINT, &sigint_handler);

    std::cout << "Hello World" << std::endl;

    EyeConfig eyeconfig;

    buildConfig(&eyeconfig);

    Eye eye(&eyeconfig);
    eye.init_pos();

    while(!cancel){
        unsigned long now = millis();
        eye.update(millis());

        std::cout << "Test Debug " << now  << std::endl;

        usleep(100);
    }

}

