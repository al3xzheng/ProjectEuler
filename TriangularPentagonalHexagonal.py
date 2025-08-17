
import itertools
from math import sqrt


def digitalRoot(N):
    dr = 0;
    while(N != 0):
        dr += N% 10
        N = N//10
        if(N == 0 and dr > 9):
            N  = dr
            dr = 0
    return dr

def isTriangularInverse ( N) :
    l = N%10;
    m = int(sqrt(N))
    if(l != 9 and l !=  6 and l !=  5 and  l!=  4 and  l !=  1 and  l != 0) :
        return False
    if(digitalRoot(N) != 1 and  digitalRoot(N) != 4 and  digitalRoot(N) != 7 and  digitalRoot(N) != 9):
        return False
        # while (m*m < N) {
        #    m = (m + N/m) / 2;
        #    System.out.println(m);
        # }
        # System.out.println(m);
    return m*m == N and m % 2 == 1

def isPentagonalInverse ( N) :
    l = N%10;
    m = int(sqrt(N))
    if(l != 9 and l !=  6 and l !=  5 and  l!=  4 and  l !=  1 and  l != 0) :
        return False
    if(digitalRoot(N) != 1 and  digitalRoot(N) != 4 and  digitalRoot(N) != 7 and  digitalRoot(N) != 9):
        return False
        # while (m*m < N) {
        #    m = (m + N/m) / 2;
        #    System.out.println(m);
        # }
        # System.out.println(m);
    return m*m == N and (m+1) %6 == 0


def solution () :
    o = 1;
    for i in itertools.count(1):
        o += 4*i + 1;
        if(isTriangularInverse(1+8*o) and isPentagonalInverse(1+24*o) and o != 40755):
            return o;

    # public static void main(String[] args) {
# print(isTriangularInverse(1+8*40755) );
print(solution());
