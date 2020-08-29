cmake_minimum_required(VERSION 3.14)
project(Cyborg_1_5_Oled_Eye_RasperryPi)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 14)

# Set Cross Compilers from Cross-Compile-Env
# Comment to use the Compilers which are set by Clion
SET(CMAKE_C_COMPILER ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)


#set(CMAKE_FIND_ROOT_PATH /home/dakor/Projects/Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot)
set(CMAKE_FIND_ROOT_PATH ../Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot)
# Use our definitions for compiler tools
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the valueTarget directories only
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#
#SET ( CMAKE_CXX_FLAGS "-std=c++0x --sysroot=${CMAKE_FIND_ROOT_PATH} -Wl,-rpath,/opt/vc/lib" )


#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_INSTALL_RPATH "/opt/vc/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


include_directories(.)
include_directories(Natural-Eye-Behavior)
include_directories(${CMAKE_FIND_ROOT_PATH}/usr/include/arm-linux-gnueabihf) # Compiler doesn't find standard some sys headers if not set

add_executable(Cyborg_1_5_Oled_Eye_RasperryPi
        LICENSE
        README.md CyberEye.cpp CyberEye.h
        Natural-Eye-Behavior/Eye.cpp Natural-Eye-Behavior/Eye.h Natural-Eye-Behavior/EyeConfig.h Natural-Eye-Behavior/EyeMathUtils.cpp Natural-Eye-Behavior/EyeMathUtils.h Natural-Eye-Behavior/EyeStatus.h
        Main.cpp)


target_link_libraries(Cyborg_1_5_Oled_Eye_RasperryPi)

