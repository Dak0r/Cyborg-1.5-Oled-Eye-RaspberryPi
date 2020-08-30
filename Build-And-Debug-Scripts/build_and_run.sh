#!/usr/bin/env bash
echo $0
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

build.sh

utils/sync_build.sh $IP $PASS

sshpass -p "raspberry" ssh pi@$IP "zsh -l -c 'cd /home/pi/cyborg_build/ && ./Cyborg_1_5_Oled_Eye_RasperryPi'"
