#!/usr/bin/env python2

import serial
import os

ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
    i = ser.read();
    if (i=='1'): 
        #print "Hello, World"
        os.system("shutdown -h now")
        exit()

