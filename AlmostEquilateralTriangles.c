#include <stdio.h>
#include <math.h>
#include <float.h>

#define size 22360

/*
Organizing my thoughts

I've proved that a for a < b < c, and thus A = 2*a can be the side that differs by 1 from the length of
the other two sides, which are repeating.

We know the area of the triangle will be integral. What if heigth wasn't integral? then a wouldn't be integral
What if 2*a = A was integral, Then it would work. if a, b aren't integral, is c integral, for pythagorean
identity?
Yes it could be...

*/

void sieve (int * primes) {
    for(int i = 2; i < size;i++) {
        primes[i] = 1;
    }
    for(int i = 2; i <=149; i++) {
        if(primes[i]) {
            for(int j = i; i * j < size;j++) {
                primes[i*j] = 0;
            }
        }
    }
}

long long solution () {

    long long sum = 0;
    int a,b,c;

    // if m,n coprime w/ one even, results in a primitive triple
    // if m,n coprime w/ no even, results in a non-primitive triple
    // if m,n not coprime, the km, kn, does not affect our solution journey

    // check if the primitive triple of 2 coprime odds is in the set of 1 even , 1 odd coprime numbers.

    for(int i = 2; i < size;i++) {
        for(int j = 1; j < i;j++) {

            if(i%2 == 0 && j % 2 == 0)
                continue;
            
            if(i%2 == 1 && j % 2 == 1) {
                if(((i*i-3*j*j) == 2 || (i*i-3*j*j) == -2) && i*i < 500000000) {
                    sum += 2*i*i;
                    printf("%lld\n", 2*i*i);
                }
            }

            if(((i*i-3*j*j) == -1 || (i*i-3*j*j) == 1) && i*i < 250000000) {
                sum += 4*i*i;
                printf("%lld\n", 4*i*i);
            }

        }
    }

    float h;

    // for(int i = 2; i <= 333333333;i++) {
    //     h = sqrt(i*i - (((i-1)*1.0)/2)* (((i-1)*1.0)/2));
    //     if((((i-1) *h)/2) - (int)(((i-1) *h)/2) == 0) {
    //         // printf("1 - c: %d Area: %f\n", i, (((i-1) *h)/2));
    //         sum += 3*i-1;
    //     }
    //     h = sqrt(i*i - (((i+1)*1.0)/2)* (((i+1)*1.0)/2));
    //     // printf("%f\n", h);
    //     if((((i+1) *h)/2) - (int)(((i+1) *h)/2) == 0) {
    //         // printf("2  - c: %d Area: %f\n", i, (((i+1) *h)/2));
    //         sum += 3*i-1;
    //     }
    // }

    return sum;

}

int main () {

    // int primes[size];
    // sieve(primes);

    printf("sol: %d", solution());



    return 0;
}