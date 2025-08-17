#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define size 10

// A clear mind is the most important thing when doing math and problem solving.

bool isPair(int * firstCube, int * secondCube) {

    if(!((firstCube[0] && secondCube[1]) || (firstCube[1] && secondCube[0])))
        return false;
    if(!((firstCube[0] && secondCube[4]) || (firstCube[4]&& secondCube[0])))
        return false;
    // if(!((firstCube[0] > 0 && (secondCube[9] > 0) || secondCube[6] > 0) || ((firstCube[9] > 0 || firstCube[6] > 0) && secondCube[0] > 0)))
    //     return false;
    if(!((firstCube[0] && (secondCube[6] || secondCube[9])) || ((firstCube[6] || firstCube[9]) && secondCube[0])))
        return false;
    // if(!((firstCube[1] > 0 && (secondCube[6] > 0 || secondCube[9] > 0)) || ((firstCube[6] > 0 || firstCube[9] > 0) && secondCube[1] > 0)))
    //     return false;
    if(!((firstCube[1] && (secondCube[6] || secondCube[9])) || ((firstCube[6] || firstCube[9]) && secondCube[1])))
        return false;
    if(!((firstCube[2] && secondCube[5]) || (firstCube[5] && secondCube[2])))
        return false;
    // if(!((firstCube[3] > 0 && (secondCube[6] > 0 || secondCube[9] > 0)) || ((firstCube[6] > 0 || firstCube[9] > 0) && secondCube[3] > 0)))
    //     return false;
    if(!((firstCube[3] && (secondCube[6] || secondCube[9])) || ((firstCube[6] || firstCube[9]) && secondCube[3])))
        return false;
    // if(!((firstCube[4] > 0 && (secondCube[6] > 0 || secondCube[9] > 0)) || ((firstCube[6] > 0 || firstCube[9] > 0) && secondCube[4] > 0)))
    //     return false;
    if(!((firstCube[4] && (secondCube[6] || secondCube[9])) || ((firstCube[6] || firstCube[9]) && secondCube[4])))
        return false;
    if(!((firstCube[1] && secondCube[8]) || (firstCube[8] && secondCube[1])))
        return false;
    // for(int i = 0;i<10;i++) {
    //     printf("%d ", firstCube[i]);
    // }
    // printf("   ");
    // for(int i = 0;i<10;i++) {
    //     printf("%d ", secondCube[i]);
    // }
    // printf("\n");
    return true;
}


int generateSecondCubes (int * firstCube, int * array, int index, int prev) {

    int sum = 0;

    if(index == 6) {
        return isPair (firstCube, array);
    }

    for(int i = prev; i < size ; i++) {

        // if(i >= firstCube[i]) {

        int * newCube = (int *)malloc(size * sizeof(int));
        memcpy(newCube, array, size*sizeof(int));

        newCube[i] = 1;

        // if(i == 6)
        //     sum += generateSecondCubes(firstCube, newCube, index + 1, i);
        // else {
        sum += generateSecondCubes(firstCube, newCube, index + 1, i+1);
        // }

        // sum += generateSecondCubes(firstCube, newCube, index + 1, i+1);

        free(newCube);

        // }

        

    }

    return sum;

}

int generateFirstCubes (int * array,  int index, int prev) {

    int sum = 0;

    if(index == 6) {
        int * dummyCube = (int*) calloc (size, sizeof(int));
        sum = generateSecondCubes(array, dummyCube, 0, 0);
        free(dummyCube);
        return sum;
    }

    for(int i = prev ; i < size; i++) {

        int * newCube = (int *)malloc(size * sizeof(int));
        memcpy(newCube, array, size*sizeof(int));

        newCube[i] = 1;
        // if(i == 6)
        //     sum += generateFirstCubes(newCube, index + 1, i);
        // else {
        sum += generateFirstCubes(newCube, index + 1, i+1);
        // }
        // sum += generateFirstCubes(newCube, index + 1, i+1);

        free(newCube);

    }

    return sum;

}


int solution () {

    int * cube1 = (int*) calloc(size, sizeof(int));

    int answer = generateFirstCubes(cube1, 0, 0);

    free(cube1);

    return answer/2;

}

int main () {

    printf("%d", solution());

    return 0;
}