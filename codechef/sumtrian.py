#!/usr/bin/env python2

def main():
    n = input('')
    for i in range(0, n):
        rows = input('')
        matrix = []
        for j in range(0, rows):
            matrix.append([int(x) for x in raw_input('').split()])
        print(sum(matrix))

def sum(matrix):
    last = len(matrix) - 1
    while last > 0:
        matrix[last-1] = merge_rows(matrix[last-1], matrix[last])
        last -= 1
    return matrix[0][0]

def merge_rows(a, b):
    for i in range(0, len(a)):
        a[i] += max(b[i], b[i+1])
    return a

if __name__ == "__main__":
    main()
