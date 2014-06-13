#!/usr/bin/env python3

import sys

inversions = 0

def main():
    global inversions
    arr = []
    fname = sys.argv[1]
    with open(fname, 'r') as f:
        for line in f:
            arr.append(int(line.rstrip('\r\n')))
    count_inv(arr, 0, len(arr)-1)
    print('Number of inversions are:', inversions)
    return

def count_split_inv(arr, start, mid, end):
    global inversions
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
            # inversions += elements remaining in left
            inversions += len(left) - i
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

def count_inv(arr, start, end):
    if (start < end):
        mid = int((start + end) / 2)
        count_inv(arr, start, mid)
        count_inv(arr, mid+1, end)
        count_split_inv(arr, start, mid, end)
    return

if (__name__ == '__main__'):
    main()
