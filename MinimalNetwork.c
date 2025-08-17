#include <stdio.h>

// My takeaway is that I need to go over my code before submission, I accidentally included the -3 filler
// value for empty nodal connections. -3 from char/int value of '-' - 48. This is very frusterating
// since I had everything right, but still failed due to my lack of patience and care for my craft.

// I will take this mistake forward. I clinically tackled tihs problem but messed up at the lsat moment
// due to a carelessness ...

// Finish Strong!!!

// Happy that I basically did all the thinking of this in 1 day; yesterday I took some glances and generated
// some understanding of the question, but no ideas were generated, as far I a recall.

/*
My Breakdown:



*/

int solution (int matrix [40] [40], int track[40], int index, int network) {

    if(index == 40) {
        return network;
    }

    int min = __INT_MAX__;
    int node;

    for(int i = 0 ; i < index; i++) {
        for(int j = 0 ; j < 40; j++) {
            if(matrix[track[i]][j] > 0 && matrix[track[i]][j] < min) {
                node = j;
                min = matrix[track[i]][j];
            }
        }
    }
    // printf("%d ", node);
    for(int i = 0 ; i < index; i++) {
        matrix[track[i]][node] = -1;
        matrix[node][track[i]] = -1;
    }
    
    track[index] = node;

    return solution(matrix, track, index + 1, network + min);

}

int main () {

    FILE *inputFile;

    inputFile = fopen("./resources/network.txt", "r" );
    
    char ch;

    int number = 0;
    int index = 0;

    int matrix [40] [40];

    while ((ch = fgetc(inputFile)) != EOF) {

        if(ch == 44 || ch == 10) {
            // printf("%d ", number);
            matrix[index/40][index%40] = number;
            number = 0;
            index++;    
        }

        else {
            number *= 10;
            number += ch - 48;
        }


    }

    int track [40];

    // for(int i = 0; i < 40; i++) {
    //     track[i] = -1;
    // }

    // Starting point; starting node (from two nodes)

    // int min = __INT_MAX__;
    // int x, y;

    // for(int i = 0 ;i < 40; i++) {
    //     for(int j = 0 ; j < 40; j++) {
    //         if(matrix[i][j] < min) {
    //             min = matrix[i][j] ;
    //             x = i;
    //             y = j;
    //         }
    //     }
    // }

    // matrix[x][y] = -1;
    // matrix[y][x] = -1;

    // track[0] = x;
    // track[1] = y;

    track [0] = 35;

    int sum = 0;

    // Forgot to include the if statement in the first submission. Very frusterating, that I missed this.
    // Caught this on the second submission.
    for(int i = 0; i < 40; i++) {
        for(int j = i + 1; j < 40; j++) {
            if(matrix[i][j] > 0)
                sum += matrix[i][j];
        }
    }

    int minimizedNetworkSize = solution(matrix, track, 1, 0);

    printf("\n%d\n", sum);
    printf("%d\n", minimizedNetworkSize);
    printf("Answer: %d", sum - minimizedNetworkSize);

    // printf("\n%d", index);


    return 0;
}