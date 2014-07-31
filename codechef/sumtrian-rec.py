#!/usr/bin/env python2

def main():
    n = input('')
    for i in range(0, n):
        rows = input('')
        matrix = []
        for j in range(0, rows):
            matrix.append([int(x) for x in raw_input('').split()])
        print(weight(matrix, 0, 0))

def weight(matrix, i, j):
    #print('weight called with', i, j)
    if i < len(matrix)-1:
        return matrix[i][j] + max(weight(matrix, i+1, j), weight(matrix, i+1, j+1))
    else:
        return matrix[i][j]

if __name__ == "__main__":
    main()
