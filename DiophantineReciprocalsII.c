#include <stdio.h>
#include <stdlib.h>

# define target 7999999
# define max 10953009486979560
/////////////9350130049860600

void sieve (int primes [50]) {

    for(int i = 2; i < 50; i++) {
        primes[i] = 1;
    }

    for(int i = 2; i < 8; i++) {
        if(primes[i]) {
            for(int j = i; i * j < 50; j++) {
                primes[i*j] = 0;
            }
        }
    }

}

void generatePreliminarySequence (int primes[], long long * min, int track [], int index, int prev, long long number, int product, int sum) {

    if(sum >= 4)
        return;
    
    if(abs((product * (2*sum + 1)) - target) < *min && (product * (2*sum + 1)) > target) {
        *min = abs((product * (2*sum + 1))- target);
        printf("Answer: %lld %d | ", number, (product * (2*sum + 1)));
        for(int i = 0 ; i < index; i++) {
            printf("%d ", track[i]);
        }
        printf("\n");
    }

    for(int i = prev; i <= 41; i++) {
        if(primes[i]) {
            if(max / i < number)   
                return;
            track[index] = i;
            if(i == prev)
                generatePreliminarySequence(primes, min, track, index + 1, i, number * i, product, sum + 1);
            else {
                generatePreliminarySequence(primes, min, track, index + 1, i, number * i, product * (2*sum + 1), 1);
            }
        }
    }

}


int main () {

    // 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47
    int primes [50];
    int track [50] = {0};
    sieve(primes);

    // long long k = (long long) 2*2*2*3*3*3;
    // for(long long i = 5; i <= 41; i++) {
    //     if(primes[i]) {
    //         printf("%d ", i);
    //         k *= i;
    //     }
    // }
    // printf("%lld",k );

    long long min = __INT_MAX__;

    generatePreliminarySequence(primes, &min, track, 0, 2, 1, 1, 0);

    return 1;
}