#! /usr/bin/env python

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

import sys

x = " "
y = "*"

a = int(sys.argv[1]) - 2
A = a + 1
b = 1
c = a
print (A*x + y)
while (a>0):
    print (a*x + y + b*x + y)
    a-=1
    b+=2
print ((c+A+2)*y)
    
    
