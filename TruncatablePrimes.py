import math


def isPrime (N):
    if(N==1):
        return False
    if(N%2 == 0):
        return False
    for i in range(3, math.ceil(math.sqrt(N)) + 1, 2):
        if(N%i==0):
            return False
    return True

def leftRightPrime (N):
    if(not isPrime(N)):
       return False
    left = N//10
    while(left != 0):
        if(not isPrime(left)):
            return False;
        left = left//10
    while(N !=0):
        if(not isPrime(N)):
            return False
        N = N %(math.pow(10,int((math.log(N,10)))))

    return True

startEnd = {2:3,3:7,5:3,7:3}

numPrimes = 4;

startend = [2,3,5,7]

for start in startend:
    for end in startend:
        for i in range(1,10000):
            number = int(start*math.pow(10, int(math.log(i,10)) + 2) + i*10 + end)
            if(leftRightPrime(number)):
                print(number)

# print(isPrime(239))


print("ans: "+  str(37 + 23 + 53 + 73 + 373 + 313 + 317 + 3137 + 797 + 3797 + 739397))
