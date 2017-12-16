esptool.py --chip esp8266 --port /dev/ttyUSB0 erase_flash
esptool.py --chip esp8266 --port /dev/ttyUSB0 write_flash -z 0x0000 fw.bin
