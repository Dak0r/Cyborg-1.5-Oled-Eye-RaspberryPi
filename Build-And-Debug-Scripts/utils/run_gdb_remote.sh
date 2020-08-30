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


# Kill gdbserver on remote if it's running
sshpass -p $PASS ssh pi@$IP killall gdbserver &> /dev/null

# launch gdbserver, listening on port 9091
sshpass -p $PASS ssh \
  -L9091:localhost:9091 \
  pi@$IP \
  "zsh -l -c 'cd /home/pi/cyborg_build/ && gdbserver --once :9091 ./Cyborg_1_5_Oled_Eye_RaspberryPi'"
