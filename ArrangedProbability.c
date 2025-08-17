// from math import sqrt

// # x = 49;


// # while (x<2000000000000):




// # i = 1000000000000
// # counter = 0

// # # // look for som etrick with the modulo, element of integers.
// # while (counter < 20):

// #     N = (sqrt(1+8*i*(i-1)) + 1) /2
// #     # print(str(N/2 + 0.5))
// #     if( N - int(N) == 0 and 2*i*(i-1) == N*(N-1)): #N > 1000000000000 and
// #         print(str(N))
// #         print(str(i))
// #         counter +=1
// #     i+=1


// # a = 41
// # b = 29
// # k = 1681

// # while (a < 200):

// #     while(k != -1):
// #         m = k//b -1
// #         while((a + b*m) % k != 0):
// #             m+=1
// #         temp = a
// #         a = (a * m + 2 * b) // k
// #         b = (temp + b * m) // k
// #         k = (m*m-2)//k

// #     print(str(a) + " " + str(b))

// # min = 2000000000000
// # N = 4

// # while (True):

// #     i = (sqrt(1+2*N*(N-1)) + 1) /2
// #     # print(str(N/2 + 0.5))
// #     if(i - int(i) == 0 and 2*i*(i-1) == N*(N-1)):
// #         # print(str(N))
// #         # print(str(i))
// #         x = 2*N - 1
// #         y = int(sqrt((x*x + 1) /2))
// #         # while(x < 2000000000000 or x%2 == 0):
// #         #     temp = x
// #         #     x = x*x+2*y*y
// #         #     y = 2*temp*y
// #         print(str(x))
// #         print(str(y))
// #         # if(((x+1)//2) < min):
// #         #     min = x
// #         #     print(str(min))


// #         # counter +=1
// #     N+=1

//     # // printf("%lld\n", b);
//     # value = (1.0*(i*(i-1))) / (b*(b-1));
//     # // printf("%lld\n", value);
//     # if(value == 2)
//     #     printf("%lld\n", i);

#include <stdio.h>
#include <math.h>

int main () {

    long long x_n = 41;
    long long y_n1 = 29;
    long long y_n2 = 5;
    long long temp;

    while(x_n <= 2000000000000) {

        x_n = 5*x_n + y_n1 + y_n2;
        temp = y_n2;
        y_n2 = y_n1;
        y_n1 =  6*y_n1 - temp;

    }

    if(x_n % 2 == 0)
        printf("even, odd error\n");

    printf("X of Pell: %lld\n", x_n);
    printf("Total N: %lld\n", (x_n+1)/2);

    long long N = (x_n+1)/2;

    // Sqrt function can not compute square root of long longs will compute in python easily then.
    // printf("Total BLUE (solution): %lld", (int)sqrt(N*N));
    
    // SEE ArrangedProbabilityManualCalculation.py for answer!!


    return 0;
}