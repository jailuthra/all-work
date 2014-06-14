#!/usr/bin/env python3

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

def main():
    str1 = input()
    print (atbash(str1))

def atbash(str1):
    str2 = ''
    for char in str1:
        x = ord(char)
        if x<=122 and x>=97: 
            x = ( 27 - (x-96) ) + 96
        elif x<=90 and x>=65: 
            x = ( 27 - (x-64) ) + 64
        char = chr(x)
        str2 += char
    return str2

if __name__ == '__main__':
    main()
