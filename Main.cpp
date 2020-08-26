#include <iostream>
#include <unistd.h>
#include <chrono>
#include <signal.h>
#include "CyberEye.h"

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
    std::cout << "Hello World" << std::endl;

    startTime = millis();

    int targetFPS = 60;
    int targetFrameTime = 1000/targetFPS;

    CyberEye cyberEye;
    signal(SIGINT, &sigint_handler);


    cyberEye.setup(argc, argv);

    while(!cancel){
        unsigned long now = millis();

        cancel = cyberEye.loop(now);

        unsigned long after = millis();

        unsigned long waitTime = targetFrameTime-(after-now);

        std::cout << "FrameWaitTime: " << waitTime << std::endl;

        usleep(waitTime * 1000);
    }

}