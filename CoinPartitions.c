#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// The thing about this question is that it taught me the difference between implementing a process as your
// algorithm, which is clever, but a bit naive, versus creating an equation as your algorithm, which
// effectively encapsulates a whole process based off an equation which can be implemented more easily
// and faster.

// I implemented what I thought to be a very beautiful solution with a dynamic array of pyramid size
// and constant tracking of previous answer such that a P(n) could be calculated in one cycle of n,

// I'm not sure if I could've calculated the time complexity for this algorithm that would prove it to
// be too slow from the beginning, hence saving lots of time, but I learned a lot on the power of equations

// I don't think I could've found Euler's idea to this myself, hence I need to work on my skill of
// generating identities, equations, and infinite series/products.

// That's the problem. I don't think I could've came up with this pentagonal number solution without online 
// help. I need to learn to calculate time complexity to know when an algorithm wouldn't work, and then
// to consult online help.

// Never get frusterated or tilted or start thinking fast and miss some detail, and then miss the solution.
// I missed the detail of pentagonal numbers, integers + and -, as P(n-g_n).

// Very fun problem I got to try and implement. Came up with a good solution, but alas online aid was needed
// guaranteed. Had fun, learned the power of equations and formulas that I need to learn to implement.

// And learned that I need to THINK HARDER myself, should've realized my solution wouldn't have worked.

// long long sumsToN (int N, int max) {

// }

// long long sumsToN(int N, int value, int sum) {
//     if(sum > N)
//         return 0;
//     if(N == sum)
//         return 1;
//     long long answer = 0;
//     for(int i = value; i <= N-sum;i++) {
//         // printf(" %d ", sum);
//         answer += sumsToN(N, i, sum + i);

//     }
//     return answer;
// }

// Great initial try
// long long sumsToN (int N, int bound, long long * prevSums) {

//     if(bound == 1)
//         return 1;
    
//     long long sum = 0;

//     for(int n = N - bound; n < N; n++) {

//         if(2*n <= N) 
//             sum += prevSums[n];
        

//         else {
//             sum += sumsToN(n, N - n, prevSums);
//         }

//     }

//     return sum;
// } 

// Thought to be brilliant
// void getExceedingPartitions(int n, int bound, mpz_t **prevSums) {

//     mpz_t sum;
//     mpz_init(sum);

//     for(int i = bound; i > 0; i--) {

//         if(n <= 2*i) {

//             mpz_add(sum, sum, prevSums[n-i][0]);
//             // if( n == 4 && bound == 2)
//             //     printf("Internal test %d %d %d |\n", sum, n-i,i);
//         }
//         else {
//             mpz_add(sum, sum, prevSums[n-i][i]);
//         }

//     }
//     mpz_set(prevSums[n][bound], sum);
// }

// Mis-try of the pointer to pointer solution
// long long sumsToN (int N, int bound, int ** prevSums) {

//     if(bound == 1)
//         return 1;
    
//     long long sum = 0;

//     for(int n = N - bound; n < N; n++) {

//         if(2*n <= N) 
//             sum += prevSums[n][0];
        

//         else {
//             if(prevSums[n][bound] != 0)
//                 sum += prevSums[n][N-n];
//             else {
//                 prevSums[n][N-n] = 
//             }
//             sum += sumsToN(n, N - n, prevSums);
//         }

//     }

//     return sum;
// } 

// BS try
// long long sumsToN (int N, long long * prevSums) {

//     long long sum = 1;

//     for(int n = 1; n <= N/2; n++) {

//         if(2*n < N) 
//             sum += 2*prevSums[n];
        

//         else {
//             sum += prevSums[n];
//         }

//     }

//     return sum;
// } 

// int sumsToN(int N, int largest) {
//     if(N<0)
//         return 0;
//     if(N == 0)
//         return 1;
//     int answer = 0;
//     for(int i = largest; i>= 1;i--) {
//         answer += sumsToN(N-i,i);
//     }
//     return answer;
// }

// int solution () {

//     long long * prevSums = (long long*)malloc(1000*sizeof(long long));
//     prevSums[0] = 1;

//     long long sum = 0;


//     for(int i = 1; i < 100  ; i++) {
        
//         sum = sumsToN(i, i,prevSums);
//         printf("%d %lld\n", i,sum);
//         prevSums[i] = sum;
//         if(sum % 1000 == 0)
//             return i;
//     }

//     // printf("Testing %lld", sumsToN(7,2, prevSums));


//     return 0;
// }

// int solution () {

//     long long ** prevSums = (long long**)malloc(10000*sizeof(long long*));

//     long long zero [1] = {1};
//     prevSums[0] = zero;

//     long long sum = 0;


//     for(int i = 1; i< 10000; i++) {

//         sum = 0;
        
//         long long * temp = (long long*)calloc(i, sizeof(long long));
//         prevSums[i] = temp;

//         for(int j = 1; j < i; j++) {

//             prevSums[i][j] = getExceedingPartitions(i, j, prevSums);

//         }

//         for(int j = 0; j < i;j++) {
//             if(2*j <= i)
//                 sum += prevSums[j][0];
//             else {
//                 sum += prevSums[j][i-j];
//             }
//             // if( i == 6)
//             //     printf(" %d ", sum);
//         }
//         // if( i == 6)
//         //     printf(" end ");

//         prevSums[i][0] = sum;


//         // sum = sumsToN(i, i, prevSums);
//         printf("%d %lld\n", i,sum);

//         if(sum % 1000000 == 0)
//             return i;
//     }

//     // printf("tests %lld", prevSums[2][0]);
//     // printf("Testing %lld", sumsToN(7,2, prevSums));

//     return 0;
// }

// int solution () {

//     mpz_t ** prevSums = (mpz_t**)malloc(10000*sizeof(mpz_t*));

//     mpz_t zero [1];

//     mpz_init (zero[0]);
//     mpz_set_ui(zero[0], 1);

//     prevSums[0] = zero;

//     mpz_t sum;
//     mpz_init (sum); // set to 0.

//     for(int i = 1; i< 10000; i++) {

//         mpz_set_ui(sum,0);
        
//         mpz_t * temp = (mpz_t*)malloc(i * sizeof(mpz_t));

//         for(int s = 0 ; s < i ; s++) {
//             mpz_init(temp[s]);
//         }

//         prevSums[i] = temp;

//         for(int j = 1; j < i; j++) {

//             getExceedingPartitions( i, j, prevSums);

//         }

//         for(int j = 0; j < i;j++) {
//             if(2*j <= i)
//                 mpz_add(sum,sum,prevSums[j][0]);
//             else {
//                 mpz_add(sum,sum,prevSums[j][i-j]);
//             }
//             // if( i == 6)
//             //     printf(" %d ", sum);
//         }
//         // if( i == 6)
//         //     printf(" end ");

//         mpz_set(prevSums[i][0], sum);


//         // sum = sumsToN(i, i, prevSums);
//         gmp_printf("%d %Zd ", i,sum);
//         printf("R: %ld \n", mpz_fdiv_r_ui(sum, sum, 1000000));

//         if(mpz_cmp_ui(sum, 0) == 0)
//             return i;
//     }

//     // printf("tests %lld", prevSums[2][0]);
//     // printf("Testing %lld", sumsToN(7,2, prevSums));

//     return 0;
// }


// https://en.wikipedia.org/wiki/Pentagonal_number_theorem Took <30 minutes with the online help, after
// reading for 1 hour or so...

int pentagonal (int k) {
    return (k*(3*k-1))/2;
}

int solution () {

    int * partitions = (int*)malloc(100000*sizeof(int));

    partitions[0] = 1;

    int sum = 0;
    int j = 0;

    for(int i  = 1; ; i++) {

        sum = 0;

        j = 1;

        while(i - pentagonal(j) >= 0) {

            if(j% 2 == 0)
                sum = (sum - partitions[i - pentagonal(j)]) % 1000000;
            else {
                sum = (sum + partitions[i - pentagonal(j)]) % 1000000;
            }
            
            if(j < 0)
                j = (j*-1) + 1;
            else {
                j *= -1;
            }

        }

        partitions[i] = sum;

        if(sum == 0)
            return i;


    }



}

//  gcc CoinPartitions.c -o test -lgmp THEN ./test in WSL

int main() {
    // solution();
    printf("\n%d\n", solution());

    return 0;
}