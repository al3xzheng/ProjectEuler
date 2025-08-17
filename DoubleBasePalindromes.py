import math

def isPalindrome (N):
    reverse = 0
    n = N
    while(n !=0):
        reverse = reverse*10 + n%10
        n = n//10
    return reverse == N

def inBinary(N) :
    binary = 0
    while(N!=0) :
        msb = int(math.log(N,2))
        binary = binary + pow(10, msb)
        N = N - pow(2, msb)
    return binary

# print(isPalindrome(585585))
print(inBinary(585585))
print(isPalindrome(inBinary(585585)))

sum = 0

for i in range(1, 1000000):
    if(isPalindrome(i) and isPalindrome(inBinary(i))):
        print(i)
        sum = sum + i;

print(sum)