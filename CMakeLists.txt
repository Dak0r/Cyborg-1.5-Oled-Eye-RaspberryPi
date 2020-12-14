cmake_minimum_required(VERSION 3.14)
project(Cyborg_1_5_Oled_Eye_RaspberryPi)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)


include_directories(.)
include_directories(Natural-Eye-Behavior)
include_directories(Oled)

add_definitions(-DUSE_WIRINGPI_LIB)


add_executable(Cyborg_1_5_Oled_Eye_RaspberryPi
        LICENSE
        README.md CyberEye.cpp CyberEye.h
        Natural-Eye-Behavior/Eye.cpp Natural-Eye-Behavior/Eye.h Natural-Eye-Behavior/EyeConfig.h Natural-Eye-Behavior/EyeMathUtils.cpp Natural-Eye-Behavior/EyeMathUtils.h Natural-Eye-Behavior/EyeStatus.h Natural-Eye-Behavior/EyeModifier.cpp Natural-Eye-Behavior/EyeModifier.h Natural-Eye-Behavior/modifiers/RandomLookModifier.cpp Natural-Eye-Behavior/modifiers/RandomLookModifier.h Natural-Eye-Behavior/modifiers/RandomBlinkModifier.cpp Natural-Eye-Behavior/modifiers/RandomBlinkModifier.h Natural-Eye-Behavior/modifiers/GyroAffectedLookModifier.cpp Natural-Eye-Behavior/modifiers/GyroAffectedLookModifier.h Natural-Eye-Behavior/HeadStatus.h
        Oled/Debug.h Oled/DEV_Config.c Oled/DEV_Config.h Oled/dev_hardware_i2c.c Oled/dev_hardware_i2c.h Oled/dev_hardware_SPI.c Oled/dev_hardware_SPI.h Oled/OLED_Driver.c Oled/OLED_Driver.h Oled/OLED_GUI.c Oled/OLED_GUI.h Oled/sysfs_gpio.c Oled/sysfs_gpio.h
        Oled/Fonts/fonts.h Oled/Fonts/font8.c Oled/Fonts/font12.c Oled/Fonts/font16.c Oled/Fonts/font20.c Oled/Fonts/font24.c
        Main.cpp Utils/LedStrip.cpp Utils/LedStrip.h Utils/LedBreather.cpp Utils/LedBreather.h Utils/PowerOffButton.cpp Utils/PowerOffButton.h Utils/MPU6050.cpp Utils/MPU6050.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_library(WIRINGPI wiringPi)
find_library(I2C i2c)
#find_library(GYROLIB MPU6050)

target_link_libraries(Cyborg_1_5_Oled_Eye_RaspberryPi
        "${I2C}"
        "${WIRINGPI}"
        Threads::Threads
        #"${GYROLIB}"
        )

