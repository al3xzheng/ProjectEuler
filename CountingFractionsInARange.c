#include <stdio.h>


// Decided to do the problem in this logical, but boring way.

// The Fun & interesting solution would be like in Counting Fractions.
// The beautiful recursive approach in Counting Fraction uses an array of prime factors and finds the totient
// of any number with respect to those prime factors. Even if the number is not a prime factorization of the
// numbers in the array

// You find the totient of the the (1/2) * N [denominator] value w.r.t. to the prime factors of N and then
// subtract the totient of the numerator : (1/3) * N w.r.t. to the prime factors of N (denominator) to
// obtain the number of coprime numbers w.r.t. the denominator within the desired range.
// This works since this algorithm doesn't require the use of the raw totient function. It is a beautiful
// recursive algorithm that finds the "totient" of N w.r.t. {PRMIE FACTORS}.



int hcf (int a, int b) {
    int temp = a;
    while(b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int solution() {

    int a, b;
    a = b = 0;

    int count = 0;

    for(int i = 2; i <=12000;i++) {
        a = i/3 + 1;
        if(i%2 == 0)
            b = i/2 - 1;
        else {
            b = i/2;
        }

        for(int j =a; j <= b;j++) {
            if(hcf(j, i) == 1)
                count++;
        }
    }

    return count;
}

int main () {

    printf("%d", solution());

    return 0;
}