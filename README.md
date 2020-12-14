# Cyborg-1.5-Oled-Eye-RaspberryPi
Displays an eye with natural random movement on an 1.5" Oled connected to the pi. Made it for a Cyberpunk / Cyborg costume 

## Checkout
Checkout this repository and its submodules:
```git clone --recurse-submodules https://github.com/Dak0r/Cyborg-1.5-Oled-Eye-RaspberryPi.git``` 

## Setup
Call Setup-Script: setup.sh to automatically setup your pi and the cross compile environment
Call it with the ip address of your pi and its ssh password as arguments:

``` setup.sh 192.168.178.XX raspberry```

## Build
Call the build scripts:

``` build.sh```
The executable will be in a "cmake-build" directory after that.

## Build and Run on Pi
Call the Build and Run Script with ip address of your pi and its ssh password:
``` build_and_run.sh 192.168.178.XX raspberry```
This will automatically build the project, sync the executable to your pi and run it in an ssh session.




## Other
While my Code is License as MIT, this Project uses Alex Mous MPU6050 Libarary (Licensed under the CC BY-NC SA 4.0) (Utils/MPU6050.cpp and Utils/MPU6050.h)