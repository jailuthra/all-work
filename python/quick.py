#!/usr/bin/env python3

def main():
    arr = []
    fname = sys.argv[1]
    with open(fname, 'r') as f:
        for line in f:
            arr.append(int(line.rstrip('\r\n')))
    quicksort(arr, start=0, end=len(arr)-1)
    print('Sorted list is: ', arr)
    return

def quicksort(arr, start, end):
    if end - start < 1:
        return 0
    b = start + 1
    for i in range(start+1, end):
        if arr[i] <= arr[start]:
            arr[b], arr[i] = arr[i], arr[b]
            b += 1
    arr[start], arr[b-1] = arr[b-1], arr[start]
    quicksort(arr, start, b-1)
    quicksort(arr, b, end)

if __name__ == '__main__':
    main()
