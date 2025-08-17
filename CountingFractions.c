#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 303963552391 Takes < minute to obtain.

// This beautiful algorithm was inspired by Anio. 

// When doing this problem initially, I initially thought that the numerator would be iterated through to
// find the coprime values of the denominator from [num + 1, d]. 

// I first thought that for each numerator value, we could iterate from [numerator, value + 1] and check
// if they were coprime, i.e. HCF(a,b) = 1, after all the upper bound is 12000, but that wouldn't be
// cut it for me, too inefficient.

// My second thought is confusing and wrong
// and basically just a confused version of the real algorithmic solution.
// This would require to use of an algorithm that required variable {prime factors} w.r.t. the numerator
// on various iteration of the denominator. This algorithm would also require subtracting to obtain the
// difference in HCF = 1 num & den for den > num.
// E.g. for numerator 4 = 2^2, we would only want from [5, d == 8]
// We would subtarct the number of coprime numerators w.r.t. the denominator by the co prime w.r.t. less than 
// the numerator.
// But one can see that this approach is essentially showing my lack of understanding and the same thing
// as the totient, W.R.T. the denominator.
// I then thought of the idea to think in the approach of the denominator and it worked!
// The answer is simply finding the totient for all [2,12000] 

// I ended up using this beautiful recursive algorithm that can calculator the coprime w.r.t. N,
// where the prime set are not necessarily the prime factor of N, thanks to talking to Anio.
// Could've used the basic one, but why not learn and try new things with others!

// I also came up with the combinatoric algorithm with division and combinations as well!

// Lesson Learned: NEVER CARRY OVER FAULTS FROM AN INITAL IDEA INTO ANOTHER.BE CAREFUL But also be
// intentional in trying new things.

// Since it really is just the totient function, you only need to prime factor set for each N
// I could've optimized and did what I did TotientPermutation (or TotientMaximum) to efficiently go through
// all <= N and obtain there prime factors in those N iterations as well, and then to find the totient 
// of all N as the answer using the totient formmula generated in the previous problem.

// But i chose this cool way thanks to Anio and learned!

void siever (bool * sieve) {

    for(int i = 0 ; i <= 1000000;i++) {
        sieve[i] = true;
    }
    // Search up to the square root of the upper bound. Root(1000000) = 1000
    for(int i = 2; i <= 1000; i++) {
        if(sieve[i]) {
            for(int j = i ; i*j <= 1000000;j++) {
                sieve[i*j] = false;
            }
        }
    }
}

long long intermediaryStep (int denominator, int primes [], int index) {
    if(index == -1)
        return 0;
    long long count = 0;
    for(int q = 0; q <= index; q++) {
        count += denominator/primes[q] - intermediaryStep(denominator/primes[q], primes, q-1);
    }
    return count;
}

// We know the upper bound is 1 000 000 => max. num. is 999 999, max. den. is 1 000 000
// int numberOfCoprimePerDen(int n, int primes [], int index) {
//     if(index == -1)
//         return 0;
//     int count = 0;
//     count += n/primes[index] - intermediaryStep(n/primes[index], primes, index-1);
//     return count;
// }

long long solution(bool *sieve) {

    long long answer = 0;
    long long count = 0;

    int temp = 0;
    int index = 0;

    for(int i = 2; i <= 12000; i++) {


        // If i (denominator) is prime
        if(sieve[i])
            answer += i - 1;

        else {
            
            count = 0;
            index = 0;
            temp = i;

            // Maximum of 7 unique prime factors for a value <= 1000000, i.e. 2,3,5,7,11,13,17 : 510510.
            int * primes = (int*) calloc(7,sizeof(int));
            int j = 2;
    
            while(temp != 1) {
                if(sieve[j] && temp % j == 0) {
                    temp /= j;
                    if(index == 0 || (index > 0 && primes[index - 1] != j)) {
                        primes[index] = j;
                        index++;
                    }
                    j--;
                }
                j++;
            }

            count = intermediaryStep(i, primes, index-1) - 1;

            answer += (i - 1) - count ;
            free(primes);
        }
        // printf("%d\n", answer);
    }

    return answer;
}

int main() {

    bool sieve[1000001];
    siever(sieve);

    printf("%lld", solution(sieve));

}