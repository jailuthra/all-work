#!/usr/bin/env python2

import serial, os, time

ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
    i = ser.read();
    if (i=='1'): 
        print "Shutting down..."
        time.sleep(3)
        os.system("shutdown -h now")
        exit()

