#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define loopSize 190

// RUN "gcc SquareRootDigitalExpansion.c -o test -lgmp -lm && ./test" in WSL

// Think HARDER. If the solution is wrong, don't get cocky, humble yourself, it is you who is wrong, not
// the answer. Can't believe I actually thought the question is wrong.

// The joy is in the process, not the destination, or solution. Think Harder, yourself, you can come up
// to the right conclusions, ALWAYS.

// What's the point of getting frsuterated and searching up for online help. This ruins the whole point of
// these questions.

// Debug your code and think. THe joy of these hard problems are that they are hard to solve, not solving
// them. It's the journey that leads to the best destination. Think harder and you can do it.

// CALM DOWN too.

// You think harder, now. Humble yourself and, if needed, calm calm yourself down 
// (take a 5 min breather if needed). Let's do this fun challenge.

// Learn algorithmic complexity, equations/formulas, and become that indepedent, calm, forward thinker.



// long long gcd (long long a, long long b) {

//     long long temp;

//     while(b!=0) {

//         temp = a;
//         a = b;
//         b = temp%b;

//     }

//     return a;

// }

void calculateDigitSum (int denominators [loopSize], int end, mpz_t sum) {

    // int sum = 0;

    mpz_t num, den, temp, digit;
    mpz_inits(num, den, temp, digit, NULL);

    mpz_set_ui(num, 1);
    // long long num = 1;

    mpz_set_ui(den, denominators[end]);
    // long long den = denominators[end];

    // long long gcf = 0;

    // using a temporary variable to swap 2 integers a, b since don't want to generate numbers higher than
    // a, b using xor or addition swapping.

    // long long temp;

    for(int i = end-1;i >= 0;i--) {

        mpz_addmul_ui(num, den, denominators[i]);
        // num += den*denominators[i];

        // gcf = gcd(num,den);

        // num/=gcf;
        // den/=gcf;

        if(i > 0) {
            mpz_set(temp, num);
            // temp = num;
            mpz_set(num, den);
            // num = den;
            mpz_set(den, temp);
            // den = temp;
        }

    }

    // gmp_printf("\nnum: %Zd den: %Zd | \n", num, den);

    //division algorithm to 100th digit.

    // int digit = 0;

    for(int i = 0 ; i< 100;i++) {

        if(mpz_cmp(num, den) >= 0) {
            mpz_fdiv_qr(digit, num, num, den);
            // digit = num/den;
            mpz_add(sum, sum, digit);
            // sum+= digit;
            // num -= digit*den;
        }

        mpz_mul_ui(num, num, 10);
        // num *= 10;


    }

    mpz_clears(num, den, temp, digit, NULL);

    // return sum;
}

void solution() {

    mpz_t sum, current1, current2;

    mpz_inits(sum, current1, current2, NULL);
    // int sum = 0;
    // int current = 0;

    int i, iO, a, b ,c;

    int index;

    int denominators[loopSize];

    for(int j = 2; j <= 100; j++) {

        i = (int)sqrt(j);

        if(j == i*i)
            continue;

        a = 1;
        b = i;
        c = j - i*i;

        denominators[0] = i;
        index = 1;

        while(a != c) {

            iO = ((b+i) * a)/c;
            denominators[index] = iO;

            index++;

            a = c/a;
            b = iO*a - b;
            c = j - b*b;


        }

        denominators[index] = b+i;
        index++;


        for(int q = index; q < loopSize; q++) {
            denominators[q] = denominators[(q-index)%(index-1)+ 1];
        }

        // for(int q = 0; q < 200; q++) {
        //     printf("%d", denominators[q]);
        // }

        mpz_set_ui(current1, 0);
        mpz_set_ui(current2, 0);

        calculateDigitSum(denominators, loopSize-2, current1);
        calculateDigitSum(denominators,loopSize-1, current2);

        if(mpz_cmp(current1, current2) == 0) {
            mpz_add(sum, sum, current1);
            gmp_printf("%d %Zd\n", j, current1);
        }
        else {
            printf("FAILED: %d", j);
        }

    }

    gmp_printf("\nAnswer: %Zd\n", sum);
}



int main () {

    // document my appraoch.

    solution();
    // printf("\n%d\n", solution());


    return 0;
}