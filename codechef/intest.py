#!/usr/bin/env python2

from sys import stdin

n = raw_input().split(' ')
k = int(n[1])
n = int(n[0])
ans = 0

for i in range(0, n):
    t = int ( stdin.readline() )
    if (t%k) == 0: ans += 1

print (ans)
