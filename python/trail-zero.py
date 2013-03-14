#!/usr/bin/python

import sys

n = int(sys.argv[1])  
answer = 0

while (int(n/5) > 0):
    n = int(n/5)
    answer += n

print(answer)
    
    
