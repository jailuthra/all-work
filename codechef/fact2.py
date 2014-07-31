#! /usr/bin/python2

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

i = 0
t = input()

def fact(n):
    factorial = 1
    while ( n > 1 ):
        factorial *= n
        n -= 1
    return factorial

for i in range (i, t):
    n = input()
    print ( fact(n) )     

