#!/usr/bin/env bash

if [ "$1" != "" ]; then
      IP=$1
else
      IP="192.168.178.48"
fi
if [ "$2" != "" ]; then
      PASS=$2
else
      PASS="raspberry"
fi

UPDATE="0"
if [ "$1" == "update" ]; then
      UPDATE="1"
fi
if [ "$2" == "update" ]; then
      UPDATE="1"
fi
if [ "$3" == "update" ]; then
      UPDATE="1"
fi
if [ "$UPDATE" != "1" ]; then
      git clone https://github.com/raspberrypi/tools.git ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools
fi

 sshpass -p $PASS rsync -r -P --links pi@$IP:/lib ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/
 sshpass -p $PASS rsync -r -P --links pi@$IP:/usr ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/
 sshpass -p $PASS rsync -r -P --links pi@$IP:/bin ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/
 sshpass -p $PASS rsync -r -P --links pi@$IP:/opt ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/
 sshpass -p $PASS rsync -r -P --links pi@$IP:/var ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Crosscompile-Env/raspberrypi-tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/
