#!/usr/bin/env python2

import sys

def strxor(a, b):   # xor two strings of diff len
    if len(a) > len(b):
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])

def read_ciphers():
    with open(sys.argv[1]) as f:
        ciphers = f.readlines()
    ciphers = [c.strip() for c in ciphers]
    return ciphers

def main():
    ciphers = read_ciphers()
    print(ciphers)
    target = '32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52e301d16e9f52f904'
    for cipher in ciphers:
        xorred = strxor(cipher.decode('hex'), target.decode('hex'))
        decoded = ""
        for ch in xorred:
            if ch.isalpha():
                decoded += ch
            else:
                decoded += ' '
        print(decoded)

if __name__ == "__main__":
    main()
