cmake_minimum_required(VERSION 3.14)
project(Cyborg_1_5_Oled_Eye_RasperryPi)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cyborg_1_5_Oled_Eye_RasperryPi
        LICENSE
        README.md CyberEye.cpp CyberEye.h
        Natural-Eye-Behavior/Eye.cpp Natural-Eye-Behavior/Eye.h Natural-Eye-Behavior/EyeConfig.h Natural-Eye-Behavior/EyeMathUtils.cpp Natural-Eye-Behavior/EyeMathUtils.h Natural-Eye-Behavior/EyeStatus.h Main.cpp)
