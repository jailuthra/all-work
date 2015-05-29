def powerset(s):
    n = len(s)
    masks = [1<<j for j in xrange(n)]
    for i in xrange(2**n):
        yield [s[j] for j in range(n) if (masks[j] & i)]


if __name__ == '__main__':
    t = input('')
    for _ in xrange(t):
        h = list(raw_input(''))
        score = 0
        s = powerset(h)
        for e in s:
            print e
        #while True:
        #    if palindrome(max(s, key=len))

        print score
