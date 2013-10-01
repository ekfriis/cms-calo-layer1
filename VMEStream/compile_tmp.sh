#!/bin/bash 

export SOFTDIR=${SOFTDIR:-/afs/cern.ch/user/d/dbelknap/softipbus}
export FLAGS='-g -Wall -Iinclude -I'$SOFTDIR'/include -I/opt/xdaq/include/ -DLINUX'
export LDFLAGS='-L/opt/xdaq/lib/ -lCAENVME -llog4cplus'

g++ -o bin/vme2fd $FLAGS $LDFLAGS -DLOG_LEVEL=0x0\
  src/vme2fd.cc \
  src/vmestream/caen.cc \
  src/vmestream/VMEController.cc \
  src/vmestream/VMEStream_PC.c \
  $SOFTDIR/src/circular_buffer.c $SOFTDIR/src/buffer.c $SOFTDIR/src/bytebuffer.c \
  src/vmestream/OrscEmulator.cc src/vmestream/OrscEchoEmulator.cc \
  src/vmestream/OrscIpbusEmulator.cc \
  ../softipbus/src/transactionhandler.c \
  ../softipbus/src/serialization.c ../softipbus/src/handlers.c \
  ../softipbus/src/testmembase.c
