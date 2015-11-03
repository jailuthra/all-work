import sys
import random

comparisons = 0

def main():
    global comparisons
    with open(sys.argv[1], 'r') as f:
        arr = [int(x) for x in f.read().split()]
    quicksort(arr, 0, len(arr)-1)
    # print(arr)
    print(comparisons)

def getPivot(arr, l, r):
    first = arr[l]
    mid = arr[(l+r)//2]
    last = arr[r]
    if first <= mid <= last or last <= mid <= first:
        return (l+r)//2
    elif mid <= first <= last or last <= first <= mid:
        return l
    else:
        return r

def partition(arr, l, r):
    k = getPivot(arr, l, r)
    k = random.randint(l, r)
    pivot = arr[k]
    arr[k], arr[l] = arr[l], arr[k]
    i = l+1
    for j in range(l+1, r+1):
        if arr[j] < pivot:
            arr[j], arr[i] = arr[i], arr[j]
            i += 1
    arr[l], arr[i-1] = arr[i-1], arr[l]
    return i-1

def quicksort(arr, l, r):
    if r - l < 0:
        return
    global comparisons
    comparisons += r - l
    p = partition(arr, l, r)
    quicksort(arr, l, p-1)
    quicksort(arr, p+1, r)
        
if __name__ == '__main__':
    main()
