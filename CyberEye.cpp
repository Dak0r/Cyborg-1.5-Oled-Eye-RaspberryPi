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
    eyeConfig->blink_timing_duration.min = 65; // was -200
    eyeConfig->blink_timing_duration.max = 85; // was -200

    eyeConfig->blink_timing_in_between.min = 0;
    eyeConfig->blink_timing_in_between.max = 4000;

    eyeConfig->eyelid_upper_y_range.min = 0.0;
    eyeConfig->eyelid_upper_y_range.max = 0.5;
    eyeConfig->eyelid_lower_y_range.min = 1.0;
    eyeConfig->eyelid_lower_y_range.max = 0.5;

    eyeConfig->eyelid_movement_speed = 0.25;

    eyeConfig->pupil_size.min = 0.4f;
    eyeConfig->pupil_size.max = 0.9f;
    eyeConfig->pupil_size_speed = 0.1;
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


    OLED_Clear(OLED_BACKGROUND);//OLED_BACKGROUND
    OLED_Display();
    //2.show
    printf("**********Init OLED**********\r\n");
    OLED_SCAN_DIR OLED_ScanDir = SCAN_DIR_DFT;//SCAN_DIR_DFT = D2U_L2R
    OLED_Init(OLED_ScanDir );

    /*printf("OLED Show \r\n");
    GUI_Show();

    OLED_Clear(OLED_BACKGROUND);//OLED_BACKGROUND*/
    //OLED_Display();

}

bool CyberEye::loop(unsigned long now) {

    //std::cout << "CyberEye :: Loop" << std::endl;

    bool exit_application = false;

    eye.update(now);

    /*time(&oled_now);
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
     */

    OLED_ClearWindow(0, 0, 127, 127, BLACK);

    int posX = (int)(64 + (eye.get_position_x()*18));
    int posY = (int)(64 + (eye.get_position_y()*10));
    int size = 36;
    GUI_DrawCircle(posX, posY, size+10, WHITE, DRAW_EMPTY , DOT_PIXEL_DFT);
    GUI_DrawCircle(posX, posY, size+6, WHITE, DRAW_EMPTY , DOT_PIXEL_DFT);
    GUI_DrawCircle(posX, posY, size*eye.get_pupil_size(), WHITE, DRAW_FULL , DOT_PIXEL_DFT);

    //GUI_DrawLine(posX, posY-10, posX, posY+10, BLACK, LINE_DOTTED, DOT_PIXEL_2X2);
    //GUI_DrawLine(posX-10, posY, posX+10, posY, BLACK, LINE_DOTTED, DOT_PIXEL_2X2);

    //u8g2.drawBox(posX-48, posY-48,98,96*eye.get_upper_eyelid());
    //printf("Eyelid Y-Bottom: %d \n", lerpInt(posY-60, posY, eye.get_upper_eyelid()));
    //printf("Eyelid Y-Bottom: %f ---- %d \n", eye.get_upper_eyelid(), lerpInt(0, 127, eye.get_upper_eyelid()));
    //GUI_DrawRectangle(posX-60, 0, posX+60, lerpInt(0, 127, eye.get_upper_eyelid()), WHITE, DRAW_FULL , DOT_PIXEL_DFT);
    //GUI_DrawRectangle(0, 0, 127, lerpInt(0, 127, eye.get_upper_eyelid()), BLACK, DRAW_FULL , DOT_PIXEL_DFT);
    OLED_ClearWindow(0, 0, 127, lerpInt(0, 127, eye.get_upper_eyelid()), BLACK);
    OLED_ClearWindow(0, lerpInt(0, 127, eye.get_lower_eyelid()), 127, 127, BLACK);
    //float lower_eyelid = eye.get_lower_eyelid();
    //GUI_DrawRectangle(posX-30, posY-30+(98*(lower_eyelid)), posX+30, posY+30, BLACK, DRAW_FULL , DOT_PIXEL_DFT);
    //u8g2.drawBox(posX-48, posY-48+(98*(lower_eyelid)),98,48);


    OLED_DisWindow(0, 0, 127, 127);

    return exit_application;
}

