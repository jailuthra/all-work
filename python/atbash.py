#!/usr/bin/env python3

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

str1 = input('Enter the String You Want To Code/Decode: ')
str2 = ''
for char in str1:
    x = ord(char)
    if x<=122 and x>=97: 
        x = ( 27 - (x-96) ) + 96
    elif x<=90 and x>=65: 
        x = ( 27 - (x-64) ) + 64
    char = chr(x)
    str2 = str2 + char
print ('Your Required String Is: '+ str2)

