#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Values used are heavily specific to the bound of L <= 1500000
// KISS: Keep It Simple, Stupid.
// https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
// See last page(s) of little black book (50-75)

int gcd(int a, int b) {

    int temp = 0;
    while(b != 0) {
        temp = a;
        a = b;
        b = temp%b;
    }

    return a;

}

int solution() {

    int answer = 0;
    int * lengths = (int*) calloc(750001, sizeof(int));
    int * lengthsTrack = (int*) calloc(750001, sizeof(int));
    int primitiveLength = 0;

    for(int i = 2; i <= 865; i++) {
        for(int j = 1; j < i; j++) {

            if(j <= 750000/i - i) {
                if(gcd(i,j) == 1 ) {

                    primitiveLength = i*(i+j);
    
                    if(i%2 != 0 && j%2 != 0 ) //&& i < 2.41421 * j
                        primitiveLength /= 2;
                    // printf("%d %d %d\n", i, j, primitiveLength);

    
                    if(lengthsTrack[primitiveLength] == 0) {

                        lengthsTrack[primitiveLength] = 1;
                        for(int k = 1; primitiveLength * k < 750001;k++) {
                            lengths[k*primitiveLength] +=1;
                        }
    
                    }
    
                    
                }
            }

            else{
                break;
            }

        }
    }

    for(int i = 0; i < 750001;i++) {
        if(lengths[i] == 1)
            answer++;
    }
    free(lengths);
    return answer;
}


int main () {

    printf("%d", solution());

    return 0;
}











// void sieve (bool * primes) {
//     for(int i = 2; i < 187500; i++) {
//         primes[i] = true;
//     }
//     for(int i = 2;i <= 433; i++) {
//         if(primes[i]) {
//             for(int j = i; i*j< 187500;j++) {
//                 primes[i*j] = false;
//             }
//         }
//     }
// }


// long long intermediaryStep (int denominator, int primes [], int index) {
//     if(index == -1)
//         return 0;
//     long long count = 0;
//     for(int q = 0; q <= index; q++) {
//         count += denominator/primes[q] - intermediaryStep(denominator/primes[q], primes, q-1);
//     }
//     return count;
// }

// int getPrimeFactors(int n, int *factors, bool* primes) {

//     while(n%2 == 0) {
//         n/=2;
//     }

//     int index = 1;
//     int count = 0;
//     int i = 3;
//     while(n != 1) {
//         if(primes[i] && n%i == 0) {
//             if(factors[index-1] != i) {
//                 factors[index] = i;
//                 count++;
//                 index++;
//             }
//             n /= i;

//             i--;
//         }
//         i++;
//     }
//     return count;
// }

// int solution (bool *primes) {

//     int max = 0;
//     int answer = 0;

//     // Go through all even numbers from 1-375000 (determined upper bound)
//     for(int i = 1; i <= 187500; i++) {

//         int * factors = (int*)calloc(6, sizeof(int));
//         factors[0] = 2;
//         int count = getPrimeFactors(i, factors, primes);

//         // m
//         if(i <= 433) {
//             max = 2*i;
//         }
//         else {
//             max = 750000/(i*2) - 1;
//         }

//         // for(int k = 0 ; k < 6;k++) {
//         //     printf("%d %d\n", i, factors[k]);
//         // }
//         // printf("\n");

//         // some altaration here to get might need some subtraction . also incorporate the 865.
//         answer += max - intermediaryStep(max, factors, count);
//         // printf(" %d %d\n", 2*i, answer);


//         // n
//         if(i <= 432) {
//             answer += 750000/(2*i+1) - intermediaryStep(750000/(2*i+1), factors, count) -  (2*i - intermediaryStep(2*i, factors, count));
//         }

//         // printf(" %d %d\n", 2*i,answer);

//         free(factors);

//     }

//     // can implement hash if desired and necessary (not nessecary in honesty)

//     return answer;
// }

// int main () {

//     bool primes[187500];
//     sieve(primes);

//     int hash [375000];

//     printf("%d", solution(primes));

//     return 0;
// }