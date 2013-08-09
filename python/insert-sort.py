#!/usr/bin/env python3

a = [4,15,8,14,5,9,0,11]
i = 0
while (i+1 < len(a)):
    j = i+1
    while ( (a[j] < a[j-1]) and j>0 ):
        key = a[j]
        a[j] = a[j-1]
        a[j-1] = key
        j = j-1
    i = i+1

print (a)
