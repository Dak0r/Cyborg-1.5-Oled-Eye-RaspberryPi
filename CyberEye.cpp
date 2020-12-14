#include "CyberEye.h"
extern "C" {
    #include "Oled/OLED_Driver.h"
    #include "Oled/OLED_GUI.h"
    #include "Oled/DEV_Config.h"
}
#include "modifiers/RandomLookModifier.h"
#include "modifiers/RandomBlinkModifier.h"

#include <iostream>
#include <unistd.h>
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

void CyberEye::setupEyeModifiers() {

    unsigned long now = millis();

    EyeModifier* randomLookModifier = new RandomLookModifier();
    EyeModifier* randomBlinkModifier = new RandomBlinkModifier();

    randomLookModifier->init(now, 1);
    randomBlinkModifier->init(now, 1);

    active_modifiers->push_back(randomLookModifier);
    active_modifiers->push_back(randomBlinkModifier);
}

void CyberEye::setup(int argc, char **argv) {

    std::cout << "CyberEye :: Setup" << std::endl;

    active_modifiers = new std::vector<EyeModifier *>();

    buildConfig(&eye_config);
    setupEyeModifiers();

    eye.init(millis(), &eye_config, active_modifiers);
    eye.init_head_gyro();


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

    OLED_ClearWindow(0, 0, 128, 128, BLACK);
    OLED_DisWindow(0, 0, 128, 128);

	// Calculate Gyro offsets
	// Uncomment, run once and paste values into Utils/MPU6050.h
    /*
     float ax, ay, az, gr, gp, gy; //Variables to store the accel, gyro and angle values
	std::cout << "Calculating the offsets...\n    Please keep the accelerometer level and still\n    This could take a couple of minutes...";
	mpu6050.getOffsets(&ax, &ay, &az, &gr, &gp, &gy);
	std::cout << "Gyroscope R,P,Y: " << gr << "," << gp << "," << gy << "\nAccelerometer X,Y,Z: " << ax << "," << ay << "," << az << "\n";
     exit(0);
     */

    ledStrip.init();
    ledBreather.init();
    powerOffButton.init();

    mpu6050.calc_yaw = true;


}

bool CyberEye::loop(unsigned long now) {

    bool exit_application = false;


    // READ GYRO DATA
    float gX, gY, gZ;
    mpu6050.getGyro(&gX, &gY, &gZ);

    // Update eye
    eye.update_head_gyro(gY, gX, gZ);
    eye.update(now);

    // Update others
    ledStrip.update(now);
    ledBreather.update(now);
    exit_application = powerOffButton.update(now);

    // RENDERING
    OLED_ClearWindow(0, 0, 128, 128, BLACK);


    // Render Base Eye
    float eye_pos_x = eye.get_position_x();
    float eye_pos_y = eye.get_position_y();

    if(eye_pos_x > 1) { eye_pos_x = 1; }
    if(eye_pos_x < -1) { eye_pos_x = -1; }
    if(eye_pos_y > 1) { eye_pos_x = 1; }
    if(eye_pos_y < -1) { eye_pos_y = -1; }

    int posX = (int)(64 + (eye_pos_x*18));
    int posY = (int)(64 + (eye_pos_y*10));
    int size = 36;
    GUI_DrawCircle(posX, posY, size+10, WHITE, DRAW_EMPTY , DOT_PIXEL_DFT);
    GUI_DrawCircle(posX, posY, size+6, WHITE, DRAW_EMPTY , DOT_PIXEL_DFT);
    GUI_DrawCircle(posX, posY, size*eye.get_pupil_size(), WHITE, DRAW_FULL , DOT_PIXEL_DFT);

    // Render Upper Eye Lid
    OLED_ClearWindow(0, 0, 128, lerpInt(0, 128, eye.get_upper_eyelid()), BLACK);

    // Render Lower Eyelid
    OLED_ClearWindow(0, lerpInt(0, 128, eye.get_lower_eyelid()), 128, 128, BLACK);


    OLED_DisWindow(0, 0, 127, 127);

    return exit_application;
}

void CyberEye::quit() {

    delete (active_modifiers);

    OLED_ClearWindow(0, 0, 128, 128, BLACK);
    OLED_DisWindow(0, 0, 128, 128);
    DEV_ModuleExit();
    ledStrip.exit();
    ledBreather.exit();
    powerOffButton.exit(); // should be last in order, because it can trigger a system shutdown

}

