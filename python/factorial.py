#!/usr/bin/python

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

# Computes the factorial of the given number
# chmod +x, then execute it like :  
# ./factorial.py [number]

import sys

factorial = 1
number = int(sys.argv[1])	

if ( number < 0 ):
    print ("FYI: factorials of negative integers isn't yet possible, blame math if you want to!")
    quit()

while ( number > 1 ):
    factorial *= number
    number -= 1
    
print ( factorial ) 	# Printing the answer after succesive multiplication!

