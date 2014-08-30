def is_prime(n):
    return not (n < 2 or any(n % i == 0 for i in range(2, int(n ** 0.5) +1)))

def primes(n):
    p = []
    for x in range(1, n+1):
        if is_prime(x):
            p.append(x)
    return p
