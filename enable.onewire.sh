#!/bin/bash

if [ $(grep w1-gpio /boot/config.txt | wc -l) -eq 0 ]
then
    echo "Added OneWire to boot config.txt, reboot needed..."
    echo "dtoverlay=w1-gpio" >> /boot/config.txt
fi

modprobe w1-gpio
modprobe w1-therm


ls /sys/bus/w1/devices/*

