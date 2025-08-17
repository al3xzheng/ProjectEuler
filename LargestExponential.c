#include <stdio.h>
#include <float.h>
#include <math.h>

int main () {

    FILE *inputFile;

    // printf("%f\n", DBL_MAX);

    inputFile = fopen("./resources/base_exp.txt", "r" );
    
    char ch;

    int number = 0;
    int exponent = 0;
    int lineNumber = 1;
    int maxLine;
    // int max = 0;

    double logarithm;
    double maxExponent = 0;

    while ((ch = fgetc(inputFile)) != EOF) {

        if(ch == 44) {

            while ((ch = fgetc(inputFile)) != 10) {
                exponent *= 10;
                exponent += ch -48;
            }

            logarithm = exponent / (log10(999665) / log10(number));
            
            if(logarithm > maxExponent) {
                maxExponent = logarithm;
                maxLine = lineNumber;
                printf("%d\n", maxLine);
            }

            if(lineNumber == 1)
                printf("%llf\n", logarithm);

            lineNumber++;
            exponent = 0;
            number = 0;

        }


        // if(ch == 10) {

        //     // if(log(999665)/ )
        //     // if(number > max) {
        //     //     max = number;
        //     // }
        //     // printf("%d\n", number);
        //     number = 0;
        // }

        else {
            number *= 10;
            number += ch-48;
        }

    }

    fclose(inputFile);

    printf("%llf\n", maxExponent);
    printf("%d", maxLine);

    return 0;
}