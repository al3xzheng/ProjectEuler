//Trial #1
// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>

// bool isSquare(unsigned long long n) {
//     // r with int should work
//     unsigned long long r = (unsigned long long)sqrt(n);
//     return (r * r == n);
// }


// int solution() {

//     int max = 70;

//     int r = 0;
//     unsigned long long x = 0;
//     int D = 0;

//     for(int i = 2; i <= max; i++) {
//         r = (int)(sqrt(i));
//         if(r*r == i)
//             continue;
//         for(unsigned long long j = r + 1; ;j++) {
//             if((((j+1)%i)*((j-1)%i))%i == 0 && isSquare((j*j - 1)/i)){
//                 if(j > x) {
//                     x = j;
//                     D = i;
//                 }
//                 break;
//             }
//         }
//     }
//     printf("%d\n", x);
//     printf("%d", D);
//     return D;
// }

// int main() {
//     solution();
// }


// Trial #2

// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>

// bool isSquare(unsigned long long n) {
//     // r with int should work
//     unsigned long long r = (unsigned long long)sqrt(n);
//     return (r * r == n);
// }


// int solution() {

//     int sieve [1001];

//     for(int i = 0; i <1001;i++) {
//         sieve[i] = 1;
//     }
//     for(int i = 2; i < 1001; i++) {
//         if(sieve[i]) {
//             for(int j = i; i *j < 1001;j++) {
//                 sieve[i*j] = 0;
//             }
//         }
//     }


//     int max =61;

//     int r = 0;
//     unsigned long long x = 0;
//     unsigned long long X = 0;
//     int D = 0;

//     for(int i = 277; i <= 277; i++) {
//         if(sieve[i]) {
//             r = (int)(sqrt(i));
//             if(r*r == i)
//                 continue;
//             for(unsigned long long y = 1; ;y++) {
//                 // if((((j+1)%i)*((j-1)%i))%i == 0 && isSquare((j*j - 1)/i)){
//                 if(isSquare((i*y*y + 1))){
//                     x = (unsigned long long)sqrt(i*y*y + 1);
//                     printf("%lld, %d, %lld \n", x, i, y);
//                     if(x > X) {
//                         X = x;
//                         D = i;
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     printf("\n%lld\n", X);
//     printf("%d", D);
//     return D;
// }

// int main() {
//     solution();
// }

// //Trial #3

// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <gmp.h>

// // bool isSquare(unsigned long long n) {
// //     // r with int should work
// //     unsigned long long r = (unsigned long long)sqrt(n);
// //     return (r * r == n);
// // }


// int solution() {

//     // int sieve [1001];

//     // for(int i = 0; i <1001;i++) {
//     //     sieve[i] = 1;
//     // }
//     // for(int i = 2; i < 1001; i++) {
//     //     if(sieve[i]) {
//     //         for(int j = i; i *j < 1001;j++) {
//     //             sieve[i*j] = 0;
//     //         }
//     //     }
//     // }

//     // #ifdef __SIZEOF_INT128__
//     //     printf("here");
//     // #endif

//     int max =1000;

//     long r = 0;

//     __int128_t temp;
//     __int128_t X = 0;
//     __int128_t a, b;
//     __int128_t k;

//     int D = 0;

//     int m1 = 0, m2 = 0;

//     for(int i = 2; i <= max; i++) {
//         r = (int)(sqrt(i));
//         if(r*r == i)
//             continue;

//         m2 = 0;
        
//         if(abs((r+1)*(r+1) - i) <= abs(r*r - i)) {

//             a = r + 1;
//             b = 1;
//             k = (r+1)*(r+1) - i;

//             while(k != 1) {
//                 // printf("%lld %lld %lld \n", (long long)a, (long long)i, (long long)b);
//                 //printf("h\n",k );
//                 for(int j = r + 1; ;j++) {
//                     if((a%abs(k) + (((b%abs(k))*(j%abs(k)))%abs(k))) % abs(k) == 0) {
//                         m1 = j;
//                         break;
//                     }
//                 }
//                 for(int j = r; j >= 0 ;j--) {
//                     if((a%abs(k) + (((b%abs(k))*(j%abs(k)))%abs(k))) % abs(k) == 0) {
//                         m2 = j;
//                         break;
//                     }
//                 }
//                 if(m2 != 0 && abs(m2*m2 - i) < abs(m1*m1 - i)) {
//                     temp = a;
//                     a = (a*m2 + b*i) / abs(k);
//                     b = (temp + b * m2)/abs(k);
//                     k = (m2*m2 - i)/k;
//                 }
//                 else {
//                     temp = a;
//                     a = (a*m1 + b*i) / abs(k);
//                     b = (temp + b * m1)/abs(k);
//                     k = (m1*m1 - i)/k;
//                 }
//                 // for(int m = r+1; ;m++) {
//                 //     if(m*m - i < (2*r + 2 - m)*(2*r + 2 - m) - i) {
//                 //         if((a + b* m) % k == 0) {
//                 //             temp = a;
//                 //             a = (a*m + b*i) / abs(k);
//                 //             b = (temp + b * m)/abs(k);
//                 //             k = (m*m - i)/k;
//                 //             break;
//                 //         }
//                 //     }
//                 //     else if((2*r + 2 - m) > 0 && (a + b* (2*r + 2 - m)) % k == 0) {
//                 //         temp = a;
//                 //         a = (a*(2*r + 2 - m) + b*i) / abs(k);
//                 //         b = (temp + b * (2*r + 2 - m))/abs(k);
//                 //         k = ((2*r + 2 - m)*(2*r + 2 - m) - i)/k;
//                 //         break;

//                 //     }
//                 // }
//             }
//         }

//         else {

//             a = r;
//             b = 1;
//             k = r*r - i;

//             while(k != 1) {
//                 // printf("%lld %lld %lld \n", (long long)a, (long long)i, (long long)b);
//                 //printf("g\n",k );
//                 for(int j = r; ;j++) {
//                     if((a%abs(k) + (((b%abs(k))*(j%abs(k)))%abs(k))) % abs(k) == 0) {
//                         m1 = j;
//                         break;
//                     }
//                 }
//                 for(int j = r -1; j >= 0 ;j--) {
//                     if((a%abs(k) + (((b%abs(k))*(j%abs(k)))%abs(k))) % abs(k) == 0) {
//                         m2 = j;
//                         break;
//                     }
//                 }
//                 if(m2 != 0 && abs(m2*m2 - i) < abs(m1*m1 - i)) {
//                     temp = a;
//                     a = (a*m2 + b*i) / abs(k);
//                     b = (temp + b * m2)/abs(k);
//                     k = (m2*m2 - i)/k;
//                 }
//                 else {
//                     temp = a;
//                     a = (a*m1 + b*i) / abs(k);
//                     b = (temp + b * m1)/abs(k);
//                     k = (m1*m1 - i)/k;
//                 }
//                 // for(int m = r; ;m++) {
//                 //     if(m*m - i < (2*r - m)*(2*r - m) - i) {
//                 //         if((a + b* m) % k == 0) {
//                 //             temp = a;
//                 //             a = (a*m + b*i) / abs(k);
//                 //             b = (temp + b * m)/abs(k);
//                 //             k = (m*m - i)/k;
//                 //             break;
//                 //         }
//                 //     }
//                 //     else if((2*r - m) > 0 && (a + b* (2*r - m)) % k == 0) {
//                 //         temp = a;
//                 //         a = (a*(2*r - m) + b*i) / abs(k);
//                 //         b = (temp + b * (2*r - m))/abs(k);
//                 //         k = ((2*r - m)*(2*r - m) - i)/k;
//                 //         break;
//                 //     }
//                 // }
//             }

//         }
//         // printf("%d\n", i);
//         printf("%lld %lld %lld \n", (unsigned long long) a, i, (unsigned long long) b);

//         if(a > X) {
//             printf("%dfdfd\n", i);
//             X = a;
//             D = i;
//         } 
//     }
//     printf("\n%lld\n", X);
//     printf("\n%d\n", D);
//     return D;
// }

// int main() {
//     solution();
// }

//Trial #4

// Run in WSL: WSL -> gcc DiophantineEquation.c -o test -lgmp -lm -> ./test 
// GMP only works in Linux Distributions

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <gmp.h>

// bool isSquare(unsigned long long n) {
//     // r with int should work
//     unsigned long long r = (unsigned long long)sqrt(n);
//     return (r * r == n);
// }


int solution() {

    // int sieve [1001];

    // for(int i = 0; i <1001;i++) {
    //     sieve[i] = 1;
    // }
    // for(int i = 2; i < 1001; i++) {
    //     if(sieve[i]) {
    //         for(int j = i; i *j < 1001;j++) {
    //             sieve[i*j] = 0;
    //         }
    //     }
    // }

    // #ifdef __SIZEOF_INT128__
    //     printf("here");
    // #endif

    int max = 1000;

    int r = 0;

    mpz_t temp, k1, X, a, b, k;
    mpz_inits(temp, k1, X, a, b, k, NULL);

    int D = 0;

    int m1 = 0, m2 = 0;

    for(long i = 2; i <= max; i++) {
        r = (long)(sqrt(i));
        if(r*r == i)
            continue;

        m2 = 0;
        
        if(abs((r+1)*(r+1) - i) <= abs(r*r - i)) {
            mpz_set_si(a, r+1);
            mpz_set_si(b, 1);
            mpz_set_si(k, (r+1)*(r+1) - i);

            while(mpz_cmp_si(k, 1) != 0) {
                // gmp_printf("%Zd %d %Zd \n", a, i, b);
                //printf("h\n",k );

                mpz_set(k1, k);
                mpz_abs(k1, k1);

                for(unsigned long j = r + 1; ;j++) {
                    mpz_set(temp, a);
                    mpz_addmul_ui(temp, b, j);
                    mpz_fdiv_r(temp, temp, k1);
                    if(mpz_cmp_ui(temp, 0) == 0) { // search up what a macro is.
                        m1 = j;
                        break;
                    }
                }
                for(unsigned long j = r; j >= 0 ;j--) {
                    mpz_set(temp, a);
                    mpz_addmul_ui(temp, b, j);
                    mpz_fdiv_r(temp, temp, k1);
                    if(mpz_cmp_ui(temp, 0) == 0) {
                        m2 = j;
                        break;
                    }
                }
                if(abs(m2*m2 - i) < abs(m1*m1 - i)) {

                    mpz_set(temp, a);

                    mpz_mul_si (a, a, m2); // could potentially be a cause of error
                    mpz_addmul_ui (a, b, i);
                    mpz_fdiv_q(a, a, k1);

                    mpz_addmul_ui(temp, b, m2);
                    mpz_fdiv_q(temp, temp, k1);
                    mpz_set(b, temp);

                    mpz_set_si(temp, m2*m2 - i);
                    mpz_fdiv_q(k, temp, k);
                }
                else {

                    mpz_set(temp, a);

                    mpz_mul_si (a, a, m1); // could potentially be a cause of error
                    mpz_addmul_ui (a, b, i);
                    mpz_fdiv_q(a, a, k1);

                    mpz_addmul_ui(temp, b, m1);
                    mpz_fdiv_q(temp, temp, k1);
                    mpz_set(b, temp);

                    mpz_set_si(temp, m1*m1 - i);
                    mpz_fdiv_q(k, temp, k);

                }
                // for(int m = r+1; ;m++) {
                //     if(m*m - i < (2*r + 2 - m)*(2*r + 2 - m) - i) {
                //         if((a + b* m) % k == 0) {
                //             temp = a;
                //             a = (a*m + b*i) / abs(k);
                //             b = (temp + b * m)/abs(k);
                //             k = (m*m - i)/k;
                //             break;
                //         }
                //     }
                //     else if((2*r + 2 - m) > 0 && (a + b* (2*r + 2 - m)) % k == 0) {
                //         temp = a;
                //         a = (a*(2*r + 2 - m) + b*i) / abs(k);
                //         b = (temp + b * (2*r + 2 - m))/abs(k);
                //         k = ((2*r + 2 - m)*(2*r + 2 - m) - i)/k;
                //         break;

                //     }
                // }
            }
        }

        else {

            mpz_set_si(a, r);
            mpz_set_si(b, 1);
            mpz_set_si(k, r*r - i);

            while(mpz_cmp_si(k, 1) != 0) {
                // gmp_printf("%Zd %d %Zd \n", a, i, b);

                mpz_set(k1, k);
                mpz_abs(k1, k1);
                // printf("%lld %lld %lld \n", (long long)a, (long long)i, (long long)b);
                //printf("g\n",k );
                for(long j = r; ;j++) {
                    mpz_set(temp, a);
                    mpz_addmul_ui(temp, b, j);
                    mpz_fdiv_r(temp, temp, k1);
                    if(mpz_cmp_ui(temp, 0) == 0) { // search up what a macro is.
                        m1 = j;
                        break;
                    }
                }
                for(long j = r -1; j >= 0 ;j--) {
                    mpz_set(temp, a);
                    mpz_addmul_ui(temp, b, j);
                    mpz_fdiv_r(temp, temp, k1);
                    if(mpz_cmp_ui(temp, 0) == 0) { // search up what a macro is.
                        m2 = j;
                        break;
                    }
                }
                if(abs(m2*m2 - i) < abs(m1*m1 - i)) {

                    mpz_set(temp, a);

                    mpz_mul_si (a, a, m2); // could potentially be a cause of error
                    mpz_addmul_ui (a, b, i);
                    mpz_fdiv_q(a, a, k1);

                    mpz_addmul_ui(temp, b, m2);
                    mpz_fdiv_q(temp, temp, k1);
                    mpz_set(b, temp);

                    mpz_set_si(temp, m2*m2 - i);
                    mpz_fdiv_q(k, temp, k);
                }
                else {
                    mpz_set(temp, a);

                    mpz_mul_si (a, a, m1); // could potentially be a cause of error
                    mpz_addmul_ui (a, b, i);
                    mpz_fdiv_q(a, a, k1);

                    mpz_addmul_ui(temp, b, m1);
                    mpz_fdiv_q(temp, temp, k1);
                    mpz_set(b, temp);

                    mpz_set_si(temp, m1*m1 - i);
                    mpz_fdiv_q(k, temp, k);
                }
                // for(int m = r; ;m++) {
                //     if(m*m - i < (2*r - m)*(2*r - m) - i) {
                //         if((a + b* m) % k == 0) {
                //             temp = a;
                //             a = (a*m + b*i) / abs(k);
                //             b = (temp + b * m)/abs(k);
                //             k = (m*m - i)/k;
                //             break;
                //         }
                //     }
                //     else if((2*r - m) > 0 && (a + b* (2*r - m)) % k == 0) {
                //         temp = a;
                //         a = (a*(2*r - m) + b*i) / abs(k);
                //         b = (temp + b * (2*r - m))/abs(k);
                //         k = ((2*r - m)*(2*r - m) - i)/k;
                //         break;
                //     }
                // }
            }

        }
        // printf("%d\n", i);

        // mpz_out_str(stdout, 10, a);
        // printf(" ");
        // printf("%ld ", i);
        // mpz_out_str(stdout, 10, b);
        // printf(" \n");

        gmp_printf("%Zd %d %Zd \n", a, i, b);

        if(mpz_cmp(a, X) > 0) {
            // printf("%ld\n", i);
            mpz_set(X, a);
            D = i;
        } 
    }
    mpz_clears(temp, a, b, k, X, k1, NULL);
    // mpz_out_str(stdout, 10, X);
    printf("\n%d\n", D);
    return D;
}

int main() {
    solution();
}

// Learning the Chakravala method was actually non-trivial now that I think of it. The method is beautiful and a wonder to think about how
// it was formed. Learning it was fun. I'm satisfied that I used my intuition and a mathematician's proof to deduce that the chakravala
// method will end eventually. Actually, yeah it was mostly the mathematician who proved it. I trusted it since it made intuitive sense.
// It is just now that I remembered how he proved it though. I implemented the Chakravala method since I presumed it would be considerably
// faster than Continued fractions. Also I remember a mathematician said it was fast in the wiki page.

// I learned A LOT on GCC, Linux, C, OSes, and large number implementation (such as the GMP libary).

// Almost forgot. Super happy that I realized that it was that the numbers were too large, greater than a, b > 2^64. 
// Hence decision to implement large numbers, and use the GMP library.
// Intuition was correct. But now looking back, it had to have been the only option. Tried to implement __int128, which only works on
// targets able to hold 128 bit ints, which my PC can't. Hence a pivot to a library.
// Installling GMP was a hastle, but figured it out, check my documentation. Converting my C code to GMP was also stressful, but
// quite joyous. Super happy to see that it worked and super happy to have debugged, like forgetting to ABS for both if/else.

// Super satisfied that I solved it the way I wanted to and that my intuition was correct. Slow but not stucK!

// Again, my intuition was that the largest a,b exceed 2^64, hence the negative values when printing the long long of these large a,b.
// But it really wasn't so clear to me as a beginner. Thanks to God, I solved this after my online Alpha class. Thanks God for the power
// and strength and knowledge to solve this!