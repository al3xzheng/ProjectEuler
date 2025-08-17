#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Wow this took way too long.

// The right test / debug output selection is critical in debugging and saving a myriad of precious time.
// Knowing what information to retrieve in testing is critical.

// Keep It Simple, Stupid. You can always add complexity to your advantage; but removing complexity is
// always in your disadvantage. Keeping it simple means knowing what will work. Implementing what will
// work and repeating this process until the optimal solution is achieved.

// My weakness is in calculating time complexity since because of that, I overcomplicated the problem...

// bool SuDokuCube (int array [9][9], int ** solveSudoku, int * zerosInCube, int * cubicDigits, int start, int track, int numZeros, int startingCube) {

//     if(start == numZeros) {

//         if(start == 4) {
//             for(int k = 0 ; k < 9;k++) {
//                 printf("%d ", array[k/3][3 + k%3]);
//             }
//         }


//         start = 0;
//         track = 0;

//         int min = 10;

//         int fill [9] = {0};
//         int markTaken [10] = {0};

//         for(int i = 0; i < 9;i++) {
//             numZeros = 0;
//             for(int j = 0; j < 9;j++) {
//                 if(array[(i/3)*3 + j/3][(i%3)*3 + j%3] == 0) {
//                     numZeros++;
//                     fill[j] = 1;
//                 }
//                 else {
//                     markTaken[array[(i/3)*3 + j/3][(i%3)*3 + j%3]] = 1;
//                 }
//             }   
//             if(numZeros > 0 && numZeros < min) {
//                 min = numZeros;
//                 startingCube = i;
//                 memcpy(zerosInCube, fill, 9*sizeof(int));
//                 memcpy(cubicDigits, markTaken, 10*sizeof(int));
//             }
//             for(int k = 0; k < 9 ; k++) {
//                 fill[k] = 0;
//                 markTaken[k] = 0;
//             }
//             markTaken[9] = 0;
//         }

//         if(min == 10)
//             return true;

//         numZeros = min;
        
//         for(int i = 0; i < numZeros; i++) {
//             memcpy(solveSudoku[i], cubicDigits, 10 * sizeof(int));
//         }


//         // set up a void recursive function that populates the zeros of a 3x3 in the thought-of algorithm
//         // taking in the inddex, which square we're solving, and goes through all possible numbers
//         // and then to the next.

//         // This function can have an if statement that, inside has the code above which characterizes a
//         // new 3x3 to be solved. It can be a function, maybe? Will be hard to return some array.

//         // We're going to need that recursive function that populates the array, figure out how to integrate
//         // the above with it. some recursive conditional statement.

//         int index = 0;

//         // get unusable numbers in solveSudoku array. will need a tracker array.

//         // problem here.
//         for(int i = 0 ; i < 9; i++) {
//             if(zerosInCube[i] == 1) {

//                 for(int j = 0 ; j < 9 ; j++) {

//                     solveSudoku[index][array[j][(startingCube%3) *3 + i%3]] = 1;
//                     solveSudoku[index][array[(startingCube/3)*3 + i/3][j]] = 1;

//                 }
//                 index++;
//             }
//         }

//     }

//     // for(int i = 0;  i < 10 ; i++) {
//     //     printf("%d ", solveSudoku[1][i]);
//     // }


    

//     // setup recursive statement and conditional that calls the above block and indicates the base case.
//     // hint: something to do with minZeros in a pointer, start, as sub-base case and when 
//     //    if(min == 0)
//     //   return true; as the final base case.
    
//     for(int i = track; i < 9;i++) {

//         if(zerosInCube[i] == 1) {

//             for(int j = 1; j < 10; j++) {

//                 if(solveSudoku[start][j] == 0 && cubicDigits[j] == 0) {
//                     array[(startingCube/3) * 3 + i/3][(startingCube%3)*3 + i % 3] = j;
//                     cubicDigits[j] = 1;
//                     // printf("cube: %d digit: %d", i, j);
//                     if(!SuDokuCube(array, solveSudoku, zerosInCube, cubicDigits, start + 1, i + 1, numZeros, startingCube)) {
//                         array[(startingCube/3) * 3 + i/3][(startingCube%3)*3 + i % 3] = 0;
//                         cubicDigits[j] = 0;
//                     }
//                     // SuDokuCube(array, solveSudoku, zerosInCube, cubicDigits, start + 1, track + 1, numZeros, startingCube);
//                 }

//             }
//             // if(i ==0) {
//             //     for(int q = 0; q < 10; q++) {
//             //         printf("%d ", cubicDigits[q]);
//             //     }
//             // }
//             return false;

//         }
        
//     }

//     return true;
// }

bool SuDokuCube (int array[9][9], int ** digits, int start) {

    if(start == 81)
        return true;
    

    int cube;
    // int begin;

    while (array[start/9][start%9] != 0) {
        start++;
    }

    if(start >= 81)
        return true;
    // printf("\n");

    // printf("%d ", start);
    // if(start == 8)
    //     printf("tp");

    cube =(start/27) *3 + (start%9)/3;


    // if(i == 0) {
    //     for(int q = 0;  q < 10 ; q++) {
    //         printf("%d ", digits[0][q]);
    //     }
    // }

    for(int k = 0 ; k < 10;k++) {
        digits[start][k] = 0;
    }


    for(int k = 0 ; k < 9; k++) {

        digits[start][array[start/9][k]] = 1;
        digits[start][array[k][start%9]] = 1;
        digits[start][array[(cube/3)*3 + k/3][(cube%3)*3 + k%3]] = 1;
    }

    for(int j = 1; j < 10;j++) {


        if(digits[start][j] == 0) {
            array[start/9][start%9] = j;
            // printf("after: %d ", start);
            // begin = begin +1;
            // printf("%d: %d   ", start, j);
            if(!SuDokuCube(array, digits, start+1)) 
                array[start/9][start%9] = 0;
            else {
                return true;
            }
            
        }
    }

    if(array[start/9][start%9] == 0)
        return false;

    return true;

}

int main() {

    FILE *inputFile;

    inputFile = fopen("./resources/sudoku.txt", "r" );

    // int * solveSudoku [9];
    // for(int i = 0; i < 9; i++) {
    //     solveSudoku[i] = (int*)calloc(10,sizeof(int));
    // }

    // int zerosInCube [9];
    // int cubicDigits [10];

    int array[9][9];
    char ch;
    int sum = 0;
    int index = 0;  

    int * digits [81];
    for(int i = 0 ; i < 81; i++) {
        digits[i] = (int*)calloc(10, sizeof(int));
    }

    while ((ch = fgetc(inputFile)) != EOF) {

        if(index == 0) {
            for(int i = 0 ; i < 8 ;i++) {
                ch = fgetc(inputFile);
            }
        }

        if(index%9 == 0)
            ch = fgetc(inputFile);

        array[index/9][index%9] = ch - 48;
        index++;

        if(index == 81) {
            index = 0;
            SuDokuCube(array, digits, 0);
            sum += array[0][0]*100 + array[0][1]*10 + array[0][2];
            printf("%d\n", sum);
        }

    }

    printf("\n Solution: %d", sum);
    

    fclose( inputFile );


    return 0;
}