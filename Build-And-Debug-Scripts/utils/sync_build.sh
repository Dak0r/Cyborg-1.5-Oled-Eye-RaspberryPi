#!/usr/bin/env bash
echo "value 0:"
echo $0
echo "value 1:"
echo $1

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

sshpass -p $PASS ssh pi@$IP "mkdir cyborg_build"
sshpass -p $PASS rsync -r -P --links ../cmake-build/Cyborg_1_5_Oled_Eye_RasperryPi pi@$IP:/home/pi/cyborg_build/
sshpass -p $PASS rsync -zarv --prune-empty-dirs --include="*/" --include="*.cpp" --exclude="*" ../ pi@$IP:/home/pi/cyborg_build/
