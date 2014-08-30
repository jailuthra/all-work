def ambig(a):
    for i in range(0, len(a)):
        if i+1 != int(a[int(a[i])-1]):
            return False
    return True

if __name__ == '__main__':
    while True:
        n = input('')
        if n == 0:
            break
        else:
            a = raw_input('').split()
            if ambig(a):
                print 'ambiguous'
            else:
                print 'not ambiguous'
