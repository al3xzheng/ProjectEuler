#include <stdio.h>

// double check divided difference and tests and make sure float compatible, as there should be floats added.
#define size 10

double dividedDifference (int floor, int ceil, long long xy [size + 1]) {

    if(ceil == floor)
        return xy[floor];

    if(ceil - floor == 1)
        return (xy[ceil] - xy[floor]);

    return (1.0 * (dividedDifference(floor + 1, ceil, xy) - dividedDifference(floor, ceil - 1, xy))) / (ceil - floor);

}

double solution (long long xy [size + 1]) {

    // Lagrange Polynomial

    // int sum = 1;
    // long long OPofx;
    // long long partialSum = 0;
    // int x;

    // for(int i = 2; i <= 10; i++) {

    //     OPofx = 0;
    //     x = i + 1;

    //     for(int j = 1; j <= i; j++) {

    //         partialSum = 0;
      
    //         for(int k = 1; k <= i; k++) {

    //             OPofx *= x-k;


    //         }

    //         OPofx += partialSum;

    //     }



    // }

    // Newton Polynomial, since I'm afraid of large numbers in C.

    double sum = 1;
    int partialProduct;
    int x;

    for(int i = 2; i <= size; i++) {

        printf("%f\n", sum);

        sum += 1;
        x = i + 1;

        for(int j = 2; j <= i;j++) {

            partialProduct = 1;

            for(int k = 1;k <= j-1; k++) {

                partialProduct *= x - k;

            }

            // printf("%f\n", dividedDifference(1, j, xy));
            sum +=  dividedDifference(1, j, xy)* partialProduct;

        }

    }

    return sum;

}

int main () {

    long long n;

    long long xy [size + 1];


    for(long long i = 1; i <= size; i++) {

        // n = i*i*i;
        n = 1 + (i-1)*i*(1+i*i + i*i*i*i + i*i*i*i*i*i + i*i*i*i*i*i*i*i);
        xy[i] = n;
        // printf("%lld\n", n);

    }

    printf("Answer: %f", solution(xy));


    return 0;
}