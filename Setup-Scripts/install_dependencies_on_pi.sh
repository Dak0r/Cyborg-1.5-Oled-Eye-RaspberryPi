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
sshpass -p $PASS ssh pi@$IP "sudo apt-get install zsh gdbserver wiringpi -y"
sshpass -p $PASS ssh pi@$IP "cd ~; mkdir cyborg_dependencies; cd cyborg_dependencies/; wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.60.tar.gz; tar zxvf bcm2835-1.60.tar.gz; cd bcm2835-1.60/; sudo ./configure; sudo make && sudo make check && sudo make install; "