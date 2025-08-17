#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Sometimes thinking algorithmically, i.e. naively, can provide a new way of thinking that you previously
// did not explore. Rather than thinking intuitively, practically, to getting what you want, sometimes
// thinking naively, or in a brute force way, is actually more practical in that it provides
// a completely new approach.

// Sometimes it is not the code that is explored off the idea / algorithm. But that the algorithm is 
// explored from the ways a solution can actually be realized.
// This provides an entirely new way of thinking.

#define bound 80

struct Node {
    int num;
    int sum;
    bool visited;
};

void populateArray(struct Node array[80][80]) {

    FILE *inputFile;

    inputFile = fopen("./resources/matrix.txt", "r" );

    int value = 0;
    int index = 0;

    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {

        if(ch> 47 && ch < 58) {
            value*=10;
            value += ch - 48;
        }

        else if(ch == 44 || ch == 10) {
            struct Node * newNode = (struct Node*) calloc(1, sizeof(struct Node));
            newNode->num = value;
            array[index/80][index%80] = *newNode;
            value = 0;
            index++;
        }

    }
    struct Node * newNode = (struct Node*) calloc(1, sizeof(struct Node));
    newNode->num = value;
    array[index/80][index%80] = *newNode;

    fclose( inputFile );

}

void solution (struct Node array [bound][bound], int i, int j, int prevSum) {
    if(i == bound || j == bound)
        return;

    if(!array[i][j].visited) {
        array[i][j].sum = prevSum + array[i][j].num;
        array[i][j].visited = true;
        solution(array, i+1,j, prevSum + array[i][j].num);
        solution(array, i, j+1, prevSum + array[i][j].num);
    }

    else if(prevSum + array[i][j].num < array[i][j].sum) {
        array[i][j].sum = prevSum + array[i][j].num;
        solution(array, i+1,j, prevSum + array[i][j].num);
        solution(array, i, j+1, prevSum + array[i][j].num);
    }

    return;
    
}

int main() {

    struct Node array [80][80];

    populateArray(array);

    // for(int i = 0 ; i < 80 ; i++) {
    //     for(int j = 0 ; j < 80 ; j++) {
    //         printf(" %d ", array[i][j].num);
    //     }
    //     printf("\n");
    // }

    solution(array, 0, 0, 0);

    printf("%d", array[79][79].sum);

    return 0;
}