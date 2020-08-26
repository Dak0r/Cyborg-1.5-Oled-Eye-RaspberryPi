cmake_minimum_required(VERSION 3.14)
project(Cyborg_1_5_Oled_Eye_RasperryPi)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_TOOLCHAIN_FILE /home/dakor/Projects/GakkenEyeCrossCompileEnv/Toolchain-rpi.cmake)
set(CMAKE_FIND_ROOT_PATH ../Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot)
# Use our definitions for compiler tools
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the valueTarget directories only
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#
SET ( CMAKE_CXX_FLAGS "-std=c++0x --sysroot=${CMAKE_FIND_ROOT_PATH} -Wl,-rpath,/opt/vc/lib" )


#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_INSTALL_RPATH "/opt/vc/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_executable(Cyborg_1_5_Oled_Eye_RasperryPi
        LICENSE
        README.md CyberEye.cpp CyberEye.h
        Natural-Eye-Behavior/Eye.cpp Natural-Eye-Behavior/Eye.h Natural-Eye-Behavior/EyeConfig.h Natural-Eye-Behavior/EyeMathUtils.cpp Natural-Eye-Behavior/EyeMathUtils.h Natural-Eye-Behavior/EyeStatus.h
        Main.cpp)
