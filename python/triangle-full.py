#! /usr/bin/env python

import sys

x = " "
y = "*"
a = int(sys.argv[1]) - 2
A = a+1
b = 3
c = a
print (A*x + y)
while (a>0):
    print (a*x +b*y)
    a-=1
    b+=2
print ((c+A+2)*y)

    
