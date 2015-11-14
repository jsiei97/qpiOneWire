# qpiOneWire aka the Qt sysfs onewire wrapper

A linux sysfs onewire wrapper impl in QT for systems like the Raspberry PI.


## sysfs w1

```
cat /sys/bus/w1/devices/28-000000b51bac/w1_slave 
37 01 4b 46 7f ff 09 10 26 : crc=26 YES
37 01 4b 46 7f ff 09 10 26 t=19437
```


## Links

* https://learn.adafruit.com/adafruits-raspberry-pi-lesson-11-ds18b20-temperature-sensing/hardware
* http://raspberrypi.stackexchange.com/questions/13329/connecting-multiple-ds18b20-to-different-gpio-ports
* http://raspberrypi.stackexchange.com/questions/26623/ds18b20-not-listed-in-sys-bus-w1-devices

### Links to parts

* http://www.raspberrypi.org/

