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
float timeScale = 1;
float refValue = 1000/60;
float time_scale(){
    return timeScale;
}

int main(int argc, char* argv[]) {
    printf("CYBORG EYE :: RUNNING\n");

    startTime = millis();

    int targetFPS = 30;
    //int targetFPS = 10; // for easier debugging
    float targetFrameTime = 1000/targetFPS;

    printf("Target FPS %d\n", targetFPS);

    CyberEye cyberEye;
    signal(SIGINT, &sigint_handler);


    cyberEye.setup(argc, argv);

    while(!cancel){
        unsigned long now = millis();

        bool cancel_app = cyberEye.loop(now);

        cancel = cancel || cancel_app;

        unsigned long after = millis();

        unsigned long loopTime = (after-now);

        unsigned long waitTime = (loopTime > targetFrameTime ? 0 : targetFrameTime-loopTime);
        //printf("Wait time %d \n", waitTime);
        usleep(waitTime * 1000);

        timeScale = (float) (loopTime + waitTime) / refValue;

        printf("Time Scale:  %f  -  Wait Time: %d\n", time_scale(), waitTime);
    }

}