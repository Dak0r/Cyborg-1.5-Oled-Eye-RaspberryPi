#include "CyberEye.h"
extern "C" {
    #include "Oled/OLED_Driver.h"
    #include "Oled/OLED_GUI.h"
    #include "Oled/DEV_Config.h"
}

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>

#include <signal.h>

#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()

#include <time.h>


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
//
time_t oled_now;
struct tm *timenow;
uint8_t now_time,new_time = 11;
DEV_TIME sDev_time;

void CyberEye::setup(int argc, char **argv) {

    std::cout << "CyberEye :: Setup" << std::endl;

    buildConfig(&eye_config);

    eye.init_pos();


    printf("1.5inch OLED Moudle Demo\r\n");
    //1.System Initialization
    if(DEV_ModuleInit()) {
        std::cout << "CyberEye :: DEV MODULE INIT FAILED -> EXIT" << std::endl;
        exit(0);
    }

    //2.show
    printf("**********Init OLED**********\r\n");
    OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
    OLED_Init(OLED_ScanDir );

    printf("OLED Show \r\n");
    GUI_Show();

    OLED_Clear(OLED_BACKGROUND);//OLED_BACKGROUND
    OLED_Display();

    printf("Show Pic\r\n");
    GUI_Disbitmap(0  , 2, Signal816  , 16, 8);
    GUI_Disbitmap(24 , 2, Bluetooth88, 8 , 8);
    GUI_Disbitmap(40 , 2, Msg816     , 16, 8);
    GUI_Disbitmap(64 , 2, GPRS88     , 8 , 8);
    GUI_Disbitmap(90 , 2, Alarm88    , 8 , 8);
    GUI_Disbitmap(112, 2, Bat816     , 16, 8);

    printf("Show 16 Gray Map\r\n");
    GUI_DisGrayMap(0,73,gImage_flower);

    GUI_DisString_EN(0 , 52, "MUSIC", &Font12, FONT_BACKGROUND, WHITE);
    GUI_DisString_EN(48, 52, "MENU" , &Font12, FONT_BACKGROUND, WHITE);
    GUI_DisString_EN(90, 52, "PHONE", &Font12, FONT_BACKGROUND, WHITE);
    OLED_Display();

    printf("Show time\r\n");

}

bool CyberEye::loop(unsigned long now) {

    //std::cout << "CyberEye :: Loop" << std::endl;

    bool exit_application = false;

    eye.update(now);

    time(&oled_now);
    timenow = localtime(&oled_now);

    sDev_time.Hour = timenow->tm_hour;
    sDev_time.Min = timenow->tm_min;
    sDev_time.Sec = timenow->tm_sec;
    now_time = sDev_time.Sec;

    OLED_ClearWindow(0, 22, 127, 47, WHITE);
    GUI_Showtime(0, 22, 127, 47, &sDev_time, WHITE);
    if(now_time != new_time){
        OLED_DisWindow(0, 22, 127, 47);
        new_time = now_time;
    }

    return exit_application;
}

