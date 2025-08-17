import math

def isPrime(N):
    # A better algorithm only checks against 2, and all the odd numbers up to the square root of n.
    if(N%2 ==0):
        return False
    for i in range(3,math.ceil(math.sqrt(N)), 2):
        if(N%i == 0):
            return False
    return True

def greatestPrimeFactor (N):
    # integer factors of a number N that are in addition to N or 1, i.e., the number is not prime, are from  [2, N//2]. Since as you
    # bigger 3 (the next integer factor from 2), 3 x N//2 gets bigger, and it already doesn't work at 5, and thus -> infinity.
    # we go only from [2,N//2) to look for factors, since 600851475143 is odd, if even, or generally, [2,N//2] or [2,N//2 + 1), but
    # N//2 doesn't not need to get checked since it won't be applicable for odd, and we check 2 already, in case of even factor check.
    gcf = 0
    # start at 3 for convenience since N is odd.
    for i in range (3, math.ceil(math.sqrt(N)) + 1, 2):
        print(i)
        if (isPrime(i) and N%i == 0):
            gcf = i
    return gcf

print(greatestPrimeFactor(600851475143))
# print(math.ceil(math.sqrt(4)))