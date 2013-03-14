def exp(a,b):
    ans = 1
    while (b>0):
        ans = ans*a
        b -= 1
    return ans

def exp2(a,b):
    if b == 1:
        return a
    else: return a*exp2(a,b-1)

    
