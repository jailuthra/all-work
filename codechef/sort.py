#!/usr/bin/env python3

count = 0

def sort(A):
    less = []
    greater = []
    global count
    if len(A) <= 1:
        return A
    pivot = A[int((len(A)+1)/2)-1]
    for element in A:
        count += 1
        if element < pivot:
            less.append(element)
        elif element > pivot:
            greater.append(element)
    return concat(sort(less), pivot, sort(greater))

def concat(A, p, B):
    A.append(p)
    return A + B

def main():
    N = input('')
    A = [int(x) for x in input('').split(' ')]
    sort(A)
    print(count)

if __name__ == "__main__":
    main()
