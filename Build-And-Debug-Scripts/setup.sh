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

./utils/install_dependencies_on_pi.sh $IP $PASS
./utils/setup_cross_compile_environment.sh $IP $PASS
