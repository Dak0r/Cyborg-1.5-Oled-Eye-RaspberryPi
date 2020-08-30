#!/usr/bin/env bash
cd ../cmake-build/
#./cmake_build.sh
export RASPBIAN_ROOTFS=$HOME/Projects/Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Sysroot/
export PATH=/opt/cross-pi-gcc/bin:$PATH
export RASPBERRY_VERSION=1
cmake -DCMAKE_TOOLCHAIN_FILE=/opt/cross-pi-gcc/Toolchain-rpi.cmake ..
make