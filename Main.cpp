#include "CyberEye.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <signal.h>

bool cancel;
unsigned long startTime = 0;

void sigint_handler(int sig) {
    printf("^C caught\n");
    cancel = true;
}

unsigned long  millis(){
    auto time = std::chrono::high_resolution_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(time).count() -  startTime;

}

int main(int argc, char* argv[]) {
    printf("CYBORG EYE :: RUNNING\n");

    startTime = millis();

    int targetFPS = 60;
    int targetFrameTime = 1000/targetFPS;

    printf("Target FPS %d\n", targetFPS);

    CyberEye cyberEye;
    signal(SIGINT, &sigint_handler);


    cyberEye.setup(argc, argv);

    while(!cancel){
        unsigned long now = millis();

        cancel = cyberEye.loop(now);

        unsigned long after = millis();

        unsigned long waitTime = targetFrameTime-(after-now);

        usleep(waitTime * 1000);
    }

}