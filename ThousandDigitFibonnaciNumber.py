def getIndex ():
    prev = 1
    prev2 = 1
    fib = prev + prev2
    index = 3
    while(fib < 10**999):
        prev = prev2
        prev2 = fib
        fib = prev + prev2
        index = index + 1
    return index

print(getIndex())