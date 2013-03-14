#!/usr/bin/python

# Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

import sys

n = int(sys.argv[1])  
answer = 0

while (int(n/5) > 0):
    n = int(n/5)
    answer += n

print(answer)
    
    
