#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


// int squareDigits(int i){

//     int sum = 0;

//     while(i) {
//         sum += (i%10)*(i%10);
//         i/=10;
//     }

//     return sum;

// }

bool terminatingSumOfSquares(int memo[], int i, bool * isEightyNine) {

    if(memo[i] == 1)
        return true;

    if(i != 1 && i != 89) {
        memo[i] = 1;
        int sum = 0;
        int temp = i;
        while(temp) {
            sum += (temp%10)*(temp%10);
            temp/=10;
        }
        terminatingSumOfSquares(memo, sum, isEightyNine);
    }
    if(i == 1)
        *isEightyNine = false;
    if(!*isEightyNine)
        memo[i] = 0;
    return * isEightyNine;

}

int main () {

    clock_t begin = clock();

    int sum = 0;
    int temp;
    int count;
    bool isEightNine;

    int memo[568];
    for(int i = 2; i < 568;i++) {
        memo[i] = 0;
    }

    for(int i = 2; i <= 10000000; i++) {

        isEightNine = true;

        temp = i;
        count = 0;
        while(temp) {
            count += (temp%10)*(temp%10);
            temp/=10;
        }

        sum += terminatingSumOfSquares(memo, count, &isEightNine);

    }

    printf("%d\n", sum);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%f",time_spent);

    return 0;
}