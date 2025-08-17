#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define size 12000

// Before it was about finding an idea, now it's about find the solution. There's a difference between
// an idea and the solution, many ideas can illude themselves as the solution, but only one is the best idea,
// and a couple, the soution.
// Stop trying to go with an idea and trick it into the solution.
// This results in an unoptimal solution. This doesn't work anymore (maybe...).
// Actually think through an idea. I'm good at generating ideas. 
// The problem was generating these ideas off originally bad ideas, due to going to deep into a bad idea.
// I call trying to trick the idea into the solution. Then, dealing with the Failer's Fatigue.

void sieve (int * primes) {

    for(int i = 2; i < 2*size + 1; i++) {

        primes[i] = 1;

    }

    for(int i = 2; i <= 109; i++) {

        if(primes[i]) {

            for(int j = i ; i * j < 2*size+1; j++) {

                primes[i*j] = 0;

            }

        }

    }

}

int getPrimeFactors(int *primeFactors, int * primes, int i) {

    int index = 0;

    while(i%2 == 0) {
        i/=2;
        primeFactors[index] = 2;
        // *sum += 2;
        index++;
    }

    if(i == 1)
        return index;

    int j = 3;
    
    while(!primes[i]) {
        if(primes[j] && i%j == 0) {

            while(i%j == 0) {
                i/=j;
                primeFactors[index] = j;
                // *sum += j;
                index++;
            }

        }

        if(i == 1)
            return index;

        j+=2;

    }


    // *sum += i;
    primeFactors[index] = i;


    return index+1;

}

void DivisionsForK(int * primeFactors, int * NsatKs, int j , int n, int x) {

    int * division = (int*)calloc(n,sizeof(int));
    int index = 0;
    int temp;
    int sum;
    int factor;
    int amount;
    int track;

    for(int i = 1; i < pow(j,n); i++) {

        index = 0;
        temp = i;
        sum = 0;
        factor = 1;
        amount = 0;
        track = 0;

        while(temp != 0) {
            division[index] = temp %j;
            temp/=j;
            index++;
        }

        // if(x==8) {
        //     printf("here");
        // }


        for(int l = 0; l < j;l++) {
            temp = 1;
            for(int q = 0 ; q < n;q++) {
                if(division[q] == l) {
                    if(l == 0) {
                        sum += primeFactors[q];
                        amount++;
                    }
                    else {
                        temp *= primeFactors[q];
                    }
                }
            }
            if(l !=0) {
                factor *= temp;
                sum += temp;
                track+= temp;
            }
            
        }

        if(amount + (j-1) + x-sum <= size && (NsatKs[amount + (j-1) + x-sum] == 0 || NsatKs[amount + (j-1) + x-sum] > x)) {
            NsatKs[amount + (j-1) + x-sum] = x;
            // printf("1: %d %d \n", amount + (j-1) + x-sum, x);
        }

        temp = x/factor;
        
        if(j+x-(temp+track) <= size && (NsatKs[j+x-(temp+track)] == 0 || NsatKs[j+x-(temp+track)] > x)) {
            NsatKs[j+x-(temp+track)] = x;
            // printf("2: %d %d\n", j+x-(temp+track),x);

        }
        

    }

    free(division);

}

void populateKs(int * primeFactors, int *NsatKs, int n, int i) {

    DivisionsForK(primeFactors, NsatKs, 2, n, i);

    for(int j = 3; j <= (n +1)/2; j++) {

        DivisionsForK(primeFactors, NsatKs, j, n, i);

    }

    // for(int j = 1; j < (int)pow(2, n)-1;j++) {

    //     amount = 0;
    //     index = 0;
    //     temp = j;
    //     a = 0;
    //     b = 1;

    //     while(temp!=0) {

    //         if(temp%2 == 1) {
    //             a += primeFactors[index];
    //             amount++;
    //         }
    //         else {
    //             b *= primeFactors[index];
    //         }
    //         temp/=2;
    //         index++;

    //     }

    //     for(int q = index; q < n; q++) {
    //         b *= primeFactors[q];
    //     }

    //     if(amount+1+i-(a+b) <= size && (NsatKs[amount+1+i-(a+b)] == 0 || NsatKs[amount+1+i-(a+b)] > i)) {
    //         NsatKs[amount+1+i-(a+b)] = i;
    //         if(i < 100)
    //             printf("1: %d %d %d %d %d\n", amount+1+i-(a+b), amount, i, a, b);
    //     }

    //     a = i/b;
        
    //     if(2+i-(a+b) <= size && (NsatKs[2+i-(a+b)] == 0 || NsatKs[2+i-(a+b)] > i))
    //         NsatKs[2+i-(a+b)] = i;
    //         if(i < 100)
    //             printf("2: %d %d %d %d\n", 2+i-(a+b),i,a,b);
    // }

}

void getKs (int * NsatKs, int * primes, int i ,int index, int n, int track, int finalSum, int product, int count, int * visited) {

    if(track == n) {

        // if(i == 8)
            // printf("here: %d %d %d \n", finalSum, count, product);

        // if(i == 60)

        if(product != 1)
            return;

        if(i - finalSum + count <= size && (NsatKs[i - finalSum + count] == 0 || NsatKs[i - finalSum + count] > i))
            NsatKs[i - finalSum + count] = i;
        
        return;

    }

    product *= primes[index%n];
    visited[index%n] = 1;

    // if(i ==8)
    //     printf("testing: %d %d %d %d\n", finalSum, product, count, track);

    // int * newVisited = (int*) malloc(n, sizeof(int));
    // memcpy(newVisited, visited, n * sizeof(int));
    // if(index%n != 0)
    //     newVisited[index%n] = 0;

    // getKs(NsatKs, primes,  i, index + 1,n, track, finalSum, product/primes[index%n] , count, newVisited);
    
    // idea is to do a for loop of n - 1 ahead (with modulo operation embedded in each function to 
    // accomodate this) and still using visited, return if it's visited. If not, keep going.

    if(track == n-1) {

        // if(i == 8)
            // printf("here1: %d %d\n", finalSum, product);

        getKs(NsatKs, primes,  i, 0,n, track + 1, finalSum + product ,1, count+1, visited);

        // if(i == 8)
            // printf("here2: %d %d\n", finalSum, product);
    
        getKs(NsatKs, primes, i, 0, n, track + 1, finalSum, product, count, visited);

    }

    else {

        for(int j = index + 1; j < index + n; j++) {

            if(visited[j%n] == 0 ) {

                int * newVisited = (int*) malloc(n * sizeof(int));
                memcpy(newVisited, visited, n * sizeof(int));

                getKs(NsatKs, primes, i, j, n, track + 1, finalSum + product ,1, count + 1, newVisited);
        
                getKs(NsatKs, primes, i, j, n, track + 1, finalSum, product, count, newVisited);

                free(newVisited);
            }
            

        }

    }
    

}

void obtainKs(int i, int * NsatKs, int * primes, int n, int product, int track, int sum, int count) {

    if(track == i && product == 1) {
        if(i - sum + count <= size && (NsatKs[i - sum + count] == 0 || NsatKs[i - sum + count] > i))
            NsatKs[i - sum + count] = i;
        return;
    }

    for(int j = 0; j < n; j++) {

        if((i/track)%primes[j] == 0) {
            obtainKs(i, NsatKs, primes,  n, product*primes[j], track * primes[j], sum, count);
            obtainKs(i, NsatKs, primes, n, 1, track * primes[j], sum + product*primes[j], count + 1);
        }

    }

}

void manifestKs(int i, int * NsatKs, int product, int sum, int count) {

    if(product == 1) {
        if(i - sum + count <= size && (NsatKs[i - sum + count] == 0 || NsatKs[i - sum + count] > i))
            NsatKs[i - sum + count] = i;
        return;
    }

    // Can obviously optimize by making j start at the previous factor, since it inherently goes from 
    // smallest to largest, so the previous would be the smallest in this recursive stream.
    for(int j = 2; j <= product; j++) {

        if(product%j == 0) 
            manifestKs(i, NsatKs, product/ j, sum + j, count + 1);
        
    }

}

int solution(int * primes) {

    int answer = 0;
    int k = 1;

    int n = 0;
    // int sum;

    int * NsatKs  = (int*)calloc(size+1,sizeof(int));
    int * marker = (int*)calloc(2*size +1, sizeof(int));

    // To upper bound for our max k in bound of k <= 12000, that is 2 *k.
    for(int i = 4; i <= 2*size; i++)  {

        marker[i] = 0;

        if(!primes[i]) {

        // printf("%d\n",i );

        // sum = 0;

        // int * primeFactors = (int*)calloc((int)log2(i), sizeof(int));

        //     n = getPrimeFactors(primeFactors, primes, i);

        //     int * visited = (int*) calloc ( n, sizeof(int));

            //get lowest prime factorization with th emost amount of digits, i.e. the prime factorization.
            // this willl be the greatest k with the greatest value N. then jump forward.
            // set a while k < 12000.

            // getKs(NsatKs, primeFactors, i, 0, n, 0, 0,1,0, visited);

            // populateKs(primeFactors, NsatKs, n, i);

            // obtainKs(i, NsatKs, primeFactors, n, 1, 1, 0, 0);

            manifestKs(i, NsatKs, i, 0,0);

            // if(n + i - sum > k) {
            //     k = n + i - sum;
            //     // printf("%d %d\n", n,  i);

            //     answer += i;
            //     printf("%d %d %d\n", k, answer, i);
            // }


            // if(k >= 12000)
            //     return answer;
            // free(visited);
            // free(primeFactors);

        }

    }


    printf("start\n");

    for(int i = 2; i < size+1; i++) {
        // if(i<100)
        // printf("%d %d\n", i,NsatKs[i]);
        if(marker[NsatKs[i]] == 0) {
            if(primes[NsatKs[i]])
                printf("%d %d\n", i, NsatKs[i]);
            answer += NsatKs[i];
            marker[NsatKs[i]] = 1;
        }
    }

    free(NsatKs);
    free(marker);

    return answer;

}

int main () {

    int primes [2*size + 1];

    sieve(primes);

    printf("%d",solution(primes)); 

    // printf("here");


    return 0;
}