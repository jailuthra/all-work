def sort(l):
    n = len(l)
    for i in range(0, n):
        j = i+1
        m = i
        while j < n:
            if (l[j] < l[m]):
                m = j
            j += 1
        l[i], l[m] = l[m], l[i]
    return l

if __name__ == '__main__':
    t = input('')
    for _ in xrange(t):
        n = input('')
        pie = map(int, raw_input('').split())
        weight = map(int, raw_input('').split())
        pie = sort(pie)
        weight = sort(weight)
        i,j,count = 0,0,0
        while i<n and j<n:
            if pie[i] <= weight[j]:
                count += 1
                i += 1
                j += 1
            else:
                j += 1
        print count
