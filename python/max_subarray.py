def max_cross_subarray(A, low, mid, high):
    s = ls = A[mid]
    i = mid-1
    max_left = mid
    while (i >= low):
        s = s + A[i]
        if (s > ls):
            ls = s
            max_left = i
        i = i-1
    s = rs = A[mid+1]
    j = mid+2
    max_right = mid+1
    while (j <= high):
        s = s + A[j]
        if (s > rs):
            rs = s
            max_right = j
        j = j+1
    return (max_left, max_right, ls + rs)

def max_subarray(A, low, high):
    if (low == high):
        return (low, high, A[low])
    else:
        mid = int((low + high)/2)
        (left_low, left_high, left_sum) = max_subarray(A, low, mid)
        (right_low, right_high, right_sum) = max_subarray(A, mid+1, high)
        (cross_low, cross_high, cross_sum) = max_cross_subarray(A, low, mid, high)
        if (left_sum >= max(right_sum, cross_sum)):
            return (left_low, left_high, left_sum)
        elif (right_sum >= max(left_sum, cross_sum)):
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)

def diff_transform(A):
    B = []
    for i in range(0, len(A)-1):
        B.append(A[i+1]-A[i])
    return B

def main():
    print("Enter the stock-prices for each day: ")
    price_list = list(map(int, input().split()))
    a = diff_transform(price_list)
    m = max_subarray(a, 0, len(a)-1)
    print("Buy stock on day %d, and sell on %d for maximum profit of %d" % (m[0], m[1]+1, m[2]))

if (__name__ == "__main__"):
    main()
