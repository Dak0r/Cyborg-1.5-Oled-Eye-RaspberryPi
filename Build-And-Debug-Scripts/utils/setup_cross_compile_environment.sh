#!/usr/bin/env bash

if [ "$1" != "" ]; then
    if [ "$1" != "update" ]; then
      IP=$1
  else
      IP="192.168.178.48"
  fi
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
if [ "$UPDATE" == "1" ]; then
    sudo rm -rf /opt/raspi-toolchain/
fi

# USES: https://github.com/Pro/raspi-toolchain
# also see: https://stackoverflow.com/questions/19162072/how-to-install-the-raspberry-pi-cross-compiler-on-my-linux-host-machine/58559140#58559140

if [ ! -d "/opt/cross-pi-gcc/" ]; then
   #   git clone https://github.com/raspberrypi/tools.git ../../raspberrypi-tools
   wget https://github.com/Pro/raspi-toolchain/releases/latest/download/raspi-toolchain.tar.gz ~/
   sudo tar xfz raspi-toolchain.tar.gz --strip-components=1 -C /opt
   rm ./raspi-toolchain.tar.gz
   wget https://raw.githubusercontent.com/Pro/raspi-toolchain/master/Toolchain-rpi.cmake /opt/cross-pi-gcc/Toolchain-rpi.cmake
fi


sudo apt install rsync sshpass

sshpass -p $PASS rsync -vR --progress -rl --delete --delete-after --safe-links pi@$IP:/{lib,usr,opt/vc/lib} ../../Cyborg-1.5-Oled-Eye-RaspberryPi-Cross-Compile-Sysroot/