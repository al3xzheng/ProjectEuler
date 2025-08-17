#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void siever(bool * sieve) {


    for(int i = 2; i < 10000;i++) {
        sieve[i] = true;
    }

    for(int i = 2; i < 100;i++) {
        if(sieve[i]) {
            for(int j = i ; i *j < 10000;j++) {
                sieve[i*j] = false;
            }
        }
    }

}

int sumPrimesToN(int N, int index, int * primes) {

    if(N < 0 )
        return 0;
    if(N == 0)
        return 1;
    int answer = 0;
    for(int i = index;i>= 0; i--) {
        answer += sumPrimesToN(N-primes[i], i, primes);
    }
    return answer;
}

int solution(bool *sieve ) {

    int primeCount = 0;
    int * primes = (int*)malloc(sizeof(int));

    for(int i = 2; i < 10000 ;i++) {
        

        if(sumPrimesToN(i,primeCount-1,primes) > 5000)
            return i;

        if(sieve[i]) {
            primeCount++;
            primes = (int*)realloc(primes, primeCount*sizeof(int));
            primes[primeCount-1] = i;
        }

    }

    return 0;
}

int main() {

    bool sieve [10000];
    siever(sieve);

    printf("%d", solution(sieve));
    
    return 0;
}