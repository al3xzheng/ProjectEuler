#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Wow, what a super poor performance by me. My takeaway from this question was how in the beginning of
    this question, I felt a bit rushed and under pressure. Hence I did not think enough and just thought
    the brute force would work easily.

    My biggest problem was that I didn't implement a way to get the sum of (restricted) divisors initially
    in a fast manner, and had to do it for every step.

    This teaches me to, one, think harder and write more. Put effort in the BEGINNING in finding the solution,
    i.e., the most optimal idea. A settling of ideas in the beginning results in very hard pivoting. I need
    to do more math on paper (especially in the beginning) and stop trying to do everything in my head, in
    the beginning. 

    1. So, read the question very carefully in the beginning and think hard and carefully and fully to grasp
    the idea of an optimal solution. Don't have to pivot due to a mistake and oversight.

    2. In terms of time complexity and a search/traversal through n taking nP(n), where P(n) is the complexity
    of the operation. It is faster to implement a solution that requires some P(n) dispersed over n, than
    to repeat P(n) for every n. It's obvious, but this is a good generalization that can lead to 
    good optimizations.

    To properly get the sum of divisors for all n, an algorithm dispersed over n is taking the sum of divisors
    of k, P(k), and for qk it is q*P(k) + P(k) + q for q being a new prime factor, or q*P(k) + P(k) for an
    existing prime factor. Though this is my initial hypothesis. Need to verify and think and extrapolate
    harder to verify.

    Gonna save time and go on to the next one. Not gonna optimize. I learned.sdfsd


    */

void sieve (int *primes) {

    for(int i = 2; i < 1000000; i++) {
        primes[i] = 1;
    }

    for(int i = 2; i < 1000; i++) {
        if(primes[i]) {

            for(int j = i ; i*j < 1000000;j++) {
                primes[i*j] = 0;
            }

        }
    }

}

int sumDivisors(int *primes, int * factors, int size, int n, int prev) {

    // Note that if the first sum of factors of n already exists in members it cannot be the start of
    // the longest chain, hence. Useless info though, since we'll check through eerything at the end
    // Or will we?

    if(primes[n])
        return 0;

    int sum = 0;

    for(int i = prev; i < size; i++) {
        if(n%factors[i] == 0) {
            sum += n / factors[i];
            sum += sumDivisors(primes, factors, size, n/factors[i], i);
        }
    }

    return sum;

    // if(start == size)
    //     return 0;

    // if(factors[start] * product == n)
    //     return 0;

    // int sum = 0;

    // for(int i = start; i < size; i++) {
    //     if(product != 1)
    //         sum += product * factors[start];
    //     sum += sumDivisors(i + 1, factors, size, n, product * factors[start]);
    // }
    
    // return sum;

    // for(int i = 0 ; i < size ; i++) {

    //     for(int j = i; j < size; j++) {



    //     }

    // }

    // Plan, just do this one at a time for each n without thinking about setting up sequential ones,
    // don't even check if there is a sequential like 14 for 28, since will invoke doubles.

    // Do this and then add prmes, through a sum in the generateFunction.
    // if(i == 1 || primes[i]) {
    //     return 0;
    // }

    // if(members[i] != 0)
    //     return members[i];

    // int sum = 0;
    // for(int i = 0 ; i < size; i++) {
    //     if(i == 0 || primes[i] != primes[i-1]) {
    //         sum += i/primes[i];
    //         sum += sumDivisors(members, primes, size, sum);
    //     }
    // }

    // members[i] = sum + 1;

    // return sum;
}

// void generateNumbers (int * members, int *primes, int * factors, int index, int size, int prev, int product) {

    // for(int i = prev; i <= 999991; i++) {

    //     if(primes[i]) {

    //         product *= i;

    //         if(index == 0 || factors[index-1] != i){
    //             factors[index] = i;
    //             index++;
    //             size++;
    //         }

    //         int k = sumDivisors(primes, factors, size, product) + 1;

    //         if(k < 1000000)
    //             members[product] = k ;


    //         if(product * i >= 1000000)
    //             return;

    //         generateNumbers(members, primes, factors, index, size, i, product);

    //     }
    // }

    // for(int i = 3; i < 1000000;i++) {

    //     track = 0;
    //     temp = sumDivisors(i, members);
    //     // figure out the lowest bound for which sumDivisors = 1, will be bricked up, and replace that with
    //     // i. Then do sum divisors code efficiently.
    //     if(temp >= 1000000 ||  temp ==1)
    //         continue;

    //     members[i] = temp;
        
    //     // convuloted temp and i here.
    //     while (members[temp] != i) {
    //         if(members[temp] == 0)
    //             temp
    //         temp = members[temp];
    //     }
    //     members[temp]


    // }

// }

void populatePrimes (int * primes, int * factors, int * size, int n) {

    int index = 0;

    for(int i = 2; n > 1; i++) {
        if(primes[i] && n %i == 0) {
            if(index == 0 || factors[index - 1] != i) {
                factors[index] = i;
                index++;
                *size+= 1;
            }
            n /= i;
            i--;
        }
    }

}

void longestChain (int * members, int * primes, int * factors, bool * chain, int n, int * count, int * start ) {

    if(n >= 1000000 || members[n] == -2 || primes[n]) {
        *chain = false;
        return;
    }

    if(members[n] == -1) {
        // printf("%d\n", n);
        *start = n;
        return;
    }
    
    members[n] = -1;
    int size = 0;
    int temp = n;
    populatePrimes(primes, factors, &size, n);
    n = sumDivisors(primes, factors, size, n, 0) + 1;
    longestChain(members, primes, factors, chain, n, count, start);

    members[temp] = -2;

    if(temp == *start)
        *chain = false;

    if(*chain) {
        if(temp != *start)
            *count+=1;
        if(*start == 14316)
            printf("14316: %d\n", temp);
    }


}

void solution (int * primes, int * members) {

    int count;
    int max = 0;
    int start;
    bool chain = false;

    int factors[7];

    for(int i = 2; i < 1000000; i++) {

        // if(i == 12496)
        //     printf("HERE: %d", members[12496]);
        if(members[i] < 0)
            continue;
        // printf("%d:\n", i);

        if(primes[i]) {
            members[i] = -2;
        }
    
        else {

            chain = true;
            count = 0;
            longestChain(members, primes, factors, &chain, i, &count, &start);

            if(count > max) {
                max = count;
                printf("%d %d %d\n", i, start, count);
            }
            // printf("4 check: %d\n", members[4]);


        }


    }

}

int main () {

    int * members = (int*)calloc(1000000, sizeof(int));
    int * primes = (int*)malloc(1000000 * sizeof(int));

    sieve(primes);
    // int factors[7];
    // int size = 0;
    // int n = 9464;

    // while (n != 1) {
        
    // size = 0;
    // populatePrimes(primes, factors, &size, n);
    // n = sumDivisors(primes, factors, size, n, 0) + 1;
    // printf("%d\n", n);
    // }
    // populatePrimes(primes, factors, &size, 25046);
    // for(int i = 0 ; i < size;i++) {
    //     printf("%d\n", factors[i]);
    // }

    // printf("%d", 1);

    // printf("%d", sumDivisors(primes, factors, size, 25046, 0) + 1);

    solution(primes, members);

    // int * factors = (int*) malloc(7 *sizeof(int));

    // generateNumbers(members, primes, factors, 0, 0, 2, 1);

    // int temp = 0;
    // int rem;
    // int max = 0;
    // int count = 0;

    // for(int i = 2; i < 1000000; i++) {

    //     if(members[i] > 1) {

    //         temp = i;
    //         count = 0;

    //         while(members[temp] > 1) {
    //             rem = members[temp];
    //             members[temp] = -1;
    //             temp = rem;
    //             count++;
    //         }

    //         if(count > max) {
    //             max = count;
    //             printf("%d\n", i);
    //         }

    //     }

    // }


    return 0;

}