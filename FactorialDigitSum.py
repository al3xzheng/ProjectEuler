# in java would have to computer 100! and save as string and go through the string indices and parse to int, then sum

def factorial (N):
    if(N == 1):
        return 1
    return N * factorial(N-1)

def sumOfDigits (N):
    sum = 0
    while(N > 0):
        sum += N %10;
        # initially forgot about the integer division with double slashes in python
        N = N//10;
    return sum

N = 100
# print(type(factorial(100)))
print(sumOfDigits(factorial(100)))

