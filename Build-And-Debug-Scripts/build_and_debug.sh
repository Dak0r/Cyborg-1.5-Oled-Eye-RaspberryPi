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

utils/run_gdb_remote.sh $IP $PASS