t = input('')

for _ in xrange(t):
    h = input('')
    n, m = map(int, raw_input('').split())
    a, b, ind = map(int, raw_input('').split())
    d = map(int, raw_input('').split())
    x = []
    x.append(0)
    for i in range(1, n):
        x.append(x[i-1] + d[ind])
        ind = (a * ind + b) % m
    w = x[n-1]
    print ("%.1f" % (h*w/2.0))
