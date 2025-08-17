#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    if(i == -1 || i == bound || j == -1 || j == bound)
        return;

    if(!array[i][j].visited) {
        array[i][j].sum = prevSum + array[i][j].num;
        array[i][j].visited = true;
        if(i == bound - 1 && j == bound - 1)
            return;
        solution(array, i+1,j, prevSum + array[i][j].num);
        solution(array, i, j+1, prevSum + array[i][j].num);
        solution(array, i-1, j, prevSum + array[i][j].num);
        solution(array, i, j-1, prevSum + array[i][j].num);
    }

    else if(prevSum + array[i][j].num < array[i][j].sum) {
        array[i][j].sum = prevSum + array[i][j].num;
        if(i == bound - 1 && j == bound - 1)
            return;
        solution(array, i+1,j, prevSum + array[i][j].num);
        solution(array, i, j+1, prevSum + array[i][j].num);
        solution(array, i-1, j, prevSum + array[i][j].num);
        solution(array, i, j-1, prevSum + array[i][j].num);
    }

    return;
    
}

int main() {

    struct Node array [80][80];

    populateArray(array);

    solution(array, 0, 0, 0);

    printf("%d", array[79][79].sum);

    return 0;
}