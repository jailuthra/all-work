#!/usr/bin/env python3

import sys

def main():
    arr = []
    fname = sys.argv[1]
    with open(fname, 'r') as f:
        for line in f:
            arr.append(int(line.rstrip('\r\n')))
    merge_sort(arr, start=0, end=len(arr)-1)
    print('Sorted list is: ', arr)
    return

def merge(arr, start, mid, end):
    # Slice the array from mid
    left = arr[start:mid+1]
    right = arr[mid+1:end+1]
    i = 0
    j = 0
    k = start
    # Sort and merge back the slices, until one exhausts
    while ((i < len(left)) and (j < len(right))):
        if (left[i] <= right[j]):
            arr[k] = left[i]
            i += 1
            k += 1
        else:
            arr[k] = right[j]
            j += 1
            k += 1
    # If right exhausted, merge back remaining left
    while (i < len(left)):
        arr[k] = left[i]
        i += 1
        k += 1
    # If left exhausted, merge back remaining right
    while (j < len(right)):
        arr[k] = right[j]
        j += 1
        k += 1
    return

def merge_sort(arr, start, end):
    if (start < end):
        mid = int((start + end) / 2)
        merge_sort(arr, start, mid)
        merge_sort(arr, mid+1, end)
        merge(arr, start, mid, end)
    return

if (__name__ == '__main__'):
    main()
