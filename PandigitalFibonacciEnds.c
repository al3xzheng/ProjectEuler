#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define size 80000

// TO see solution, run and wait some (A lot of) time.

// I wanted to achieve my dreams today, and I took one step closer today by solving this
// The answer was in the golden ratio. The answer was in the math, rather than the algorithm; like always.

// I'm glad I created an efficient enough algorithm such that my brute force was successful, but wow, 
// I need to get better at math.
// I should've though mathematically in order to derive Binet's Formula. It would've probably taken the
// same amount of time, i.e. 3.5 weekdays + saturday + sunday.

// I'm happy that I nonetheless found a solution though. It takes around 2 mins to get the solution.

// Takeway: There's different archetypes of problems and it's my job to not only read& understand the problem,
// and be rigorous in my solution path. But I also need to be rigorous in my approach and striking method.

// This question should've yelled out formula / derived equation. Otherwise it would've just been brute force
// I tried to generate a solution for the first 9 digits algorithmically and I'm happy that I saw that it 
// wouldn't be plausible. Old me would've kept gunning for it and failed to achieve my dreams.

// So, My big picture viewing on a problem is improving. I pivotted from trying to algorithmically solving
// for the first 9 digits because I saw that it wasn't practical and unplausible. Though I failed to try
// to put pen to paper and solve this mathematically.

// Looking back, it was clearly an algebraic solution, not algorithmic. I should be able to discern that in 
// the future.
// From first glance it seemed too easy, but I got caught up with trying to algorithmically producing the 
// first ten digits and got lost in the sauce. I'm super glad that today I decided to achieve my dreams and
// I didn't watch any shi ping (content) and I solved this problem! In a brute force manner though ...

// Better days are ahead where I will be able to discern and rigorously break down how to approach a problem
// as well as the solution path!
// By this I mean that I'm Ok at rigorously going down a solution path, but I need to improve on rigorously
// selecting which solution path to go down.

// I need to learn how to see more mathematical, algebraic solution paths, rather than algorithmic. I like
// processes, but I need to get trick-y and find those mathematical tricks.

// Now on to understanding how to derive binet's formula for myself...

// tbh, i'm happy to see that I recognized that algorithmically generating just the first 9 digits
// was unplausible after erasing the whiteboard of my thinking in ML after the 2 kebabs doner day.

/*
4 7 6 2 8 3 7 5 5 
 496491 8 2 9 1 4 6 3 8 
 575474 7 5 2 4 2 1 9 1 
 2084671 8 2 7 7 3 8 5 1 
 2638082 4 5 6 8 1 7 3 9 
 3294681 5 8 7 4 1 6 8 2 
 368278

 And since k = 368278 had pandigital first 9 digits, it must have pandigital last 9 digits, since my code
 sums the first 9 and last 9 digits and sees returns true if the sum of every digit 1-9 is 2.

*/


// Used this resource for testing: https://planetmath.org/listoffibonaccinumbers
// Above resource was good to realize the error in how i put the carry in arr2 so when copying all the digits
// in arr1, I saw that the carry was unacceptably copied over.

// "Is the fibonacci sequence in this courtyard?" - Passerby walking down the ENV-HH path with 2 others.

// int isPandigital (int * array, int * array2, int start, int pandigital [10], int test [10]) {
//     memcpy(test, pandigital, 10 * sizeof(int));
//     for(int i = 0; i < 10; i++) {
//         test[array2[i]] += 1;
//         test[array[i+start]] += 1;
//     }
//     for(int i = 0; i < 10; i++) {
//         if(test[i] != 2)
//             return 0;
//     }

//     return 1;
// }


int isPandigital (int * array, int start, int pandigital [10], int test [10]) {
    memcpy(test, pandigital, 10 * sizeof(int));
    for(int i = start; i < start + 9; i++) {
        // printf("%d\n", i);
        test[array[i]] += 1;
        test[array[size-i+start - 1]] += 1;
    }
    // for(int i = size -1; i >= size - 9; i--) {
    //     test[array[i]] += 1;
    //     // test[array[size-i+start - 1]] += 1;
    // }
    for(int i = 1; i < 10; i++) {
        if(test[i] != 2)
            return 0;
    }
    return 1;
}

// int pandigitalFibonacciEnds(int k, int size, int byTen, int * test, int pandigital [10], int first10prev1[16], int first10prev2 [16], int last10prev1[10], int last10prev2 [10]) {

//     if(isPandigital(first10prev2, last10prev2, !byTen, pandigital, test))
//         return k;
    
//     int temp;
//     int sum;

//     //last 10
//     for(int i = 9; i >= 0;i++) {
//         temp = last10prev2[i];
//         sum = (last10prev1[i] + last10prev2[i]);
//         last10prev2[i] = sum%10;
//         if(i > 0)
//             last10prev2[i] += sum/10;
//         last10prev1[i] = temp;
//     }

//     if(!byTen)
//         first10prev2[0] = 0;

//     // figure out the indexing situation

//     //First 10
//     for(int i = 0; i < size-1;i++) {
//         temp = first10prev2[i + !byTen];
//         sum = (first10prev1[i] + first10prev2[i+1]);
//         first10prev2[i+1] = sum%10;
//         first10prev2[i] += sum/10;
//         first10prev1[i] = temp;
//     }

//     while(first10prev1[size -1] + first10prev2[size - 1] == 9) {
//         size--;
//     }

//     return pandigitalFibonacciEnds(k + 1, size - 1,first10prev2[0], test, pandigital, first10prev1, first10prev2, last10prev1, last10prev2);

// 

int pandigitalFibonnaciEndss(int k, int * arr1, int * arr2, int start, int pandigital [10], int test [10]) {

    // if(k == 51) {
    //     // for(int i = size-1; i >= size-9; i--) {
    //     //     printf("%d ", arr2[i]);
    //     // }
    //     for(int i = start; i < size; i++) {
    //         printf("%d ", arr2[i]);
    //     }
    // }
    // printf("%d:%d ", k, start);

    int temp, sum;

    while (1) {

        // printf("%d:%d ", k, start);

        if(start < size - 8 && isPandigital(arr2, start, pandigital, test)){
            // printf("%d\n",k);
             for(int i = start; i < start + 9; i++) {
                printf("%d %d", arr2[i]);
                // printf("%d", arr2[size-i+start - 1]);
            }
            printf("\n %d", k);
            // return k;
        }

        // for(int i = start; i < size; )

        for(int i = size - 1; i >= 0;i--) {
            if(i == 0) {
                printf(" i = 0%d", k);
                return -1;
            }
            temp = arr2[i];
            sum = (arr1[i] + arr2[i]);
            if(arr1[i] + arr2[i] == 0 && i < start) {
                start = i + 1;
                break;
            }
            arr2[i] = sum%10;
            arr1[i-1] += sum/10;
            arr1[i] = temp;

        }

        k+=1;

    }

    
    return -1;
    // return pandigitalFibonnaciEndss(k+1, arr1, arr2, start, pandigital, test);

}

int main () {

    // int last10prev1 [10] = {0,0,0,0,0,0,0,0,0,1};
    // int last10prev2 [10] = {0,0,0,0,0,0,0,0,0,1};

    // int size = 20000;

    int * first10prev1 = (int*)calloc(size, sizeof(int));
    // int first10prev1 [size] = {0};
    first10prev1 [size - 1] = 1;
    // int first10prev2 [size] = {0};
    int * first10prev2 = (int*)calloc(size, sizeof(int));
    first10prev2 [size - 1] = 1;
    int pandigital [10] = {0};

    int test [10];

    printf("%d", pandigitalFibonnaciEndss(2, first10prev1, first10prev2, size-1, pandigital, test));
    // pandigitalFibonnaciEndss(2, first10prev1, first10prev2, size, pandigital, test);
    return 0;
}