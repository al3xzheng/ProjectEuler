#include <stdio.h>
#include <math.h>

// int numFactors(int n) {
//     for(int )
// }

# define maxValue 510510
# define arrSize 20
//14063680
# define primeBound 30

void sieve (int * primes) {

    for(int i = 2; i < primeBound; i++) {
        primes[i] = 1;
    }

    for(int i = 2; i <= sqrt(primeBound); i++) {
        if(primes[i]) {
            for(int j = i ; i * j < primeBound;j++) {
                primes[i*j] = 0;
            }
        }
    }

}

void solution (int * array, int * primes, int prev, int index, int product, int sum, long long number, int * store) {

    if(index == arrSize)
        return;

    // if(number == 294053760) {
    //     printf("Here: %d", product * (sum+ 1));
    //     // for(int j = 0 ; j < index; j++) {
    //     //     printf("%d ", array[j]);
    //     // }
    // }

    if((product * (2*sum + 1)) >= 1999 && number < *store ) {
        *store = number;
        printf("%d %d\n", number, product * (2*sum + 1));
        for(int j = 0 ; j < index; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
        return;
    }

    for(int i = prev; i < primeBound;i++) {
        if(primes[i]) {
            if(maxValue / i < number)
                return;
            array[index] = i;
            if(index > 0 && i != prev) 
                solution(array, primes, i , index + 1, product * (2*sum + 1), 1, number*i, store);
            else {
                solution(array, primes, i , index + 1, product, sum + 1, number*i, store);
            }
        }
    }

}

int main () {

    int array [arrSize];
    int primes[primeBound];

    sieve(primes);

    int store = __INT_MAX__;
    solution(array, primes, 2, 0,1,0, 1,&store);

    return 0;
}