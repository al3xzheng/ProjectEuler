#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// From the example with digits 1 - 6, the trend of sequencing such that the largest outer numbers see lower number in the -gon ring
// in order to match the sums yielded a solution on paper. This solution turned out to be the answer. I didn't want to guess an
// answer and get it wrong or be unrigorous. I wanted to be rigorous and also to challenge myself to learn, which I did.
// The algorithm is a recursive-based factorial alg., it is brute forced, but OK in these cases. The digit 10 will give the smallest
// value in the overall solution string, hence 0 was used. Implies values 9 -> 0 were used to sort through to generate the max string
// value. Pretty nice learnings on factorial implementation, stack/heap, boost::static_array, and memory allocation. Great thinkings Fun.

// Had some dumb mistakes of messing up the if statement for the sum comparison and the end bound (for 6).

bool findLargestConcatenation(int tracking [10], int concat [10], int index) {
    if(index == 10) {
        for(int i = 0;i < 10;i++) {
            if(concat[i] == 0) {
                concat[i] = 10;
                break;
            }
        }
        // for(int i = 0 ; i < 10 ; i++) {
        //     printf("%d ", concat[i]);
        // }
        // printf("\n");
        int sum = concat[0] + concat[1] + concat[2];
        if(concat[0] < concat[3] && concat[0] < concat[5] && concat[0] < concat[7] && concat[0] < concat[9]) {
            if(sum == concat[3] + concat[2] + concat[4] && sum == concat[4] + concat[5] + concat[6] && sum == concat[6] + concat[7] + concat[8] && sum == concat[1] + concat[8] + concat[9]) {
                for(int i = 0 ; i < 10 ; i++) {
                    printf("%d ", concat[i]);
                }
                printf("\n");
                return true;
            } 
            else {
                return false;
            }
        }
    }
    for (int i = 9; i >=0;i--) {
        if(tracking[i] != -1) {
            concat[index] =  i;
            tracking[i] = -1;
            int * a = (int*) malloc (10 * sizeof(int));
            int * b = (int*) malloc (10 *sizeof(int));
            memcpy (a, tracking, 10* sizeof(int));
            tracking[i] = 0;
            memcpy (b, concat, 10 * sizeof(int));
            if(findLargestConcatenation(a,b, index + 1))
                return true;
        }
    }
    return false;
}

int main() {
    int tracking [10] = {0,0,0,0,0,0,0,0,0,0};
    int concat [10] = {0,0,0,0,0,0,0,0,0,0};
    findLargestConcatenation(tracking, concat, 0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// bool findLargestConcatenation(int tracking [7], int concat [6], int index) {
//     if(index == 6) {
//         // for(int i = 0;i < 7;i++) {
//         //     if(concat[i] == 0) {
//         //         concat[i] = 10;
//         //         break;
//         //     }
//         // }
//         // for(int i = 0 ; i < 6 ; i++) {
//         //     printf("%d ", concat[i]);
//         // }
//         // printf("\n");
//         int sum = concat[0] + concat[1] + concat[2];
//         // if(sum == concat[3] + concat[2] + concat[4] && sum == concat[4] + concat[5] + concat[6] && sum == concat[6] + concat[7] + concat[8] && sum == concat[2] + concat[8] + concat[0]) {
//         if(concat[0] < concat[3] && concat[0] < concat[5]) {
//             if(sum == concat[3] + concat[2] + concat[4] && sum == concat[4] + concat[5] + concat[1]) {
//                 for(int i = 0 ; i < 6 ; i++) {
//                     printf("%d ", concat[i]);
//                 }
//                 printf("\n");
//                 return true;
//             } 
//         }
//         else {
//             return false;
//         }
//     }
//     for (int i = 6; i >0;i--) {
//         if(tracking[i] != -1) {
//             concat[index] =  i;
//             tracking[i] = -1;
//             int * a = (int*) malloc (7 * sizeof(int));
//             int * b = (int*) malloc (6 *sizeof(int));
//             memcpy (a, tracking, 7* sizeof(int));
//             tracking[i] = 0;
//             memcpy (b, concat, 6 * sizeof(int));
//             if(findLargestConcatenation(a,b, index + 1))
//                 return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int tracking [7] = {0,0,0,0,0,0,0};
//     int concat [6] = {0,0,0,0,0,0};
//     findLargestConcatenation(tracking, concat, 0);
// }