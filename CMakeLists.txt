cmake_minimum_required(VERSION 3.14)
project(Cyborg_1_5_Oled_Eye_RaspberryPi)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)


include_directories(.)
include_directories(Natural-Eye-Behavior)


add_executable(Cyborg_1_5_Oled_Eye_RasperryPi
        LICENSE
        README.md CyberEye.cpp CyberEye.h
        Natural-Eye-Behavior/Eye.cpp Natural-Eye-Behavior/Eye.h Natural-Eye-Behavior/EyeConfig.h Natural-Eye-Behavior/EyeMathUtils.cpp Natural-Eye-Behavior/EyeMathUtils.h Natural-Eye-Behavior/EyeStatus.h
        Main.cpp)

find_library(WIRINGPI wiringPi)

target_link_libraries(Cyborg_1_5_Oled_Eye_RaspberryPi
        "${WIRINGPI}"
        )

