#include <stdio.h>
#include <stdlib.h>

int computeFactorial(int n, int * factorial) {
    int sum = 0;

    while(n) {
        sum += factorial[n%10];
        n /= 10;
    }
    return sum;
}

int cyclicLength (int * hash, int* factorial, int n , int index, int * start) {

    if(hash[n] == 0) {
        hash[n] = -1*index;
        hash[n] = cyclicLength(hash, factorial, computeFactorial(n, factorial), index + 1, start);
        if(index < *start)
            hash[n] += 1;
        // This was kind of my crux: before it was: hash[n] += index - *start;, but the next value would
        // already be updated.
        return hash[n];
    }
    if(hash[n] < 0) {
        *start = hash[n] * -1;
        return index + hash[n];
    }
    *start = index;
    return hash[n];
}

int solution(int * hash, int * factorial) {

    int start = 0;
    int ans = 0;

    for(int i = 1; i < 1000000; i++) {
        start = 0;
        if(i == 69)
            printf("%d %d\n", i, cyclicLength(hash, factorial, i, 1, &start));
        if(cyclicLength(hash, factorial, i, 1, &start) == 60)
            ans++;

    }
    return ans;

}

int main () {

    int * hash = (int*) calloc(3000000,sizeof(int));
    int factorial [10] = {1,1,2,6,24,120,720,5040,40320, 362880};

    printf("%d", solution(hash, factorial));

    return 0;
}

// The simple Idea:

// First let's prove why every starting number will get stuck in some loop:

// We know a digit d will produce the addend d! = d * (d-1)!. This implies that a sum of factorial addends
// for a number n will only be greater to another number n_1
// if n_1 has digits [0,9] lesser than in value than n_0 but in higher quantity
// or digits [0,9] higher in value but in a lower quantity.

// We simply must prove that the recurring sum of factorials of the digits for any starting number does
// not diverge.

// For the cycle to diverge, the existing digits must have values greater than the previous 
// cycle or have values equal to the previous cycle but with a higher quanity of digits. Note a decrease from
// 5 to 4 underweighs an increase from 7 to 8.

// Consider a number n with only digit d appearing a times. the factorial addend would be d!.
// For the next su

// What we know: we know that for the cycle to diverge each sum must have an appropriate increase
// in digit value. An appropriate increase in digit quantity is not possible.

// That is, an increase in quantity of digits less than the current digit values in order to facilitate
// recurring increase is not possible. d! = d * (d-1)! . d! < (d-1) * 10^0 + (d-1) * 10^1 + (d-1) * 10^2 + 
// ... + (d-1) * 10^k. 

// We must prove an appropriate increase in digit value can not always occur. This is proved by the base-10
// decimal system of digit values from [0,9].

// We must prove that the number of digits will stop increasing some point.
// There will not be a guaranteed increase in digit pass 1 million since 9! = 362880. 
// Cannot facilitate the infinite increase in the amount of digits for this cycle to diverge.

// Therefore Converges.