def gcd(a, b):
    if (b == 0):
        return a
    else:
        return gcd(b, a%b)

T = input('')
for _ in xrange(T):
    b,a = map(int, raw_input('').split())
    print(gcd(a, b))

