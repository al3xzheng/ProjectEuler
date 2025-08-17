#include <stdio.h>
#include <stdbool.h>

bool isOriginContainment (int xy [6]) {

    double m, b;

    if(xy[2] - xy[0] == 0); 

    else {
        m = 1.0* (xy[3] - xy[1]) / (xy[2] - xy[0]);
        b = xy[3] - m*xy[2];

        if(m * xy[4] + b < xy[5]) {
            if(b > 0)
                return false;
        }

        else if(b <= 0)
            return false;
    }

    if(xy[4] - xy[2] == 0); 

    else {
        m = 1.0*(xy[3] - xy[5]) / (xy[2] - xy[4]);
        b = xy[3] - m*xy[2];

        if(m * xy[0] + b < xy[1]) {
            if(b > 0)
                return false;
        }

        else if(b <= 0)
            return false;
    }

    if(xy[0] - xy[4] == 0);

    else {

        m = 1.0*(xy[1] - xy[5]) / (xy[0] - xy[4]);
        b = xy[5] - m*xy[4];

        if(m * xy[2] + b < xy[3]) {
            if(b > 0)
                return false;
        }

        else if(b <= 0)
            return false;
    }

    // Y Comparisons

    // if((y[4]-y[2]) == 0)
    //     printf("infinite %d\n", (1.0*(y[5]-y[3]))/(y[4]-y[2]));
    // double b = y[5] - ((1.0*(y[5]-y[3]))/(y[4]-y[2]))*y[4];



    // if (y[4] > y[2] && !( b > 0))
    //     return false;
    // if (y[2] > y[4] && !( b > 0))
    //     return false;   
    
    // b = y[3] - ((1.0*(y[3]-y[1]))/(y[2]-y[0]))*y[2];
    
    // if (! (b < 0))
    //     return false;

    // b = y[5] - ((1.0*(y[5]-y[1]))/(y[4]-y[0]))*y[4];

    // if(y[4] > y[0] && !(b > 0))
    //     return false;
    
    // if(y[4] < y[0] && !(b < 0))
    //     return false;

    // X Comparisons
    // b = x[4]  - x[5]/ ((1.0*(x[5]-x[3]))/(x[4]-x[2]));

    // if(!(b>0))
    //     return false;

    // b = x[0] - x[1] / ((1.0*(x[1]-x[3]))/(x[0]-x[2]));

    // if(!(b<0))
    //     return false;

    // b = x[4] - x[5] / ((1.0*(x[5]-x[1]))/(x[0]-x[4]));

    // if(x[5] > x[1] && (!(b > 0)))
    //     return false;

    // if (x[5] > x[1] && (!(b< 0))) 
    //     return false;

    // x-intercept is just -intercept divided by - slope. Very trivial. Just sort out the x-y  functions + sort,
    // double check thesemessy brackets after implementation,
    
    return true;

}

// void changePositions(int xy[6], int a, int b) {

//     int temp;

//     temp = xy[a];
//     xy[a] = xy[b];
//     xy[b] = temp;

//     temp = xy[a + 1];
//     xy[a + 1] = xy[b + 1];
//     xy[b+ 1] = temp;

// }

int main () {

    FILE *inputFile;

    inputFile = fopen("./resources/triangles102.txt", "r" );

    char ch;

    int x [6];
    int y [6];
    // int y [3];
    int number = 0;
    int index = 0;
    int negative = 0;

    int temp;

    int answer = 0;

    while ((ch = fgetc(inputFile)) != EOF) {

        if (ch == 44 || ch == 10) {

            if(negative)
                number *= -1;

            // printf("%d ", number);
            if(index%2 == 1)
                x[index%6 - 1] = number;
            else {
                x[index % 6 + 1] = number;
            }
            y[index%6] = number;

            // if(index % 6 > 1) {

            //     if((index%6)%2 == 1) {
            //         temp = index;
            //         while(y[temp%6] < y[temp%6 - 2]) {
            //             changePositions(y, index%6-3, index%6-1);
            //             temp -= 2;
            //         }   
            //     }

            //     else {
            //         temp = index;
            //         while(x[temp%6] < x[temp%6 - 2]) {
            //             changePositions(x, index%6-2, index%6);
            //             temp -= 2;
            //         }
            //     }

            // }

            if(index %6 == 5) {
                // if(x[0] == x[2] || x[2] == x[4] || x[4]== x[0])
                    // printf("infinite slope");
                if(isOriginContainment(y) && isOriginContainment(x)) {
                    printf("%d\n", index);
                    answer += 1;
                }
            }

            index++;
            number = 0;
            negative = 0;
        }

        else if(ch == 45)
            negative = 1;

        else {
            number *= 10;
            number += ch - 48;
        }


    }

    // printf("%d", index);

    fclose (inputFile);

    printf("%d", answer);

    return 0;
}