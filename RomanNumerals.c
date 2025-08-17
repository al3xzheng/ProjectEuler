#include <stdio.h>

// notes:
// 4 by IV has less digits than IIII
// 9 by IX has less digits than VIIII and can support 'another' V

/*

    Only one I, X, and C can be used as the leading numeral in part of a subtractive pair.
    I can only be placed before V and X, for 4 and 9, optimally.
    X can only be placed before L and C, for 40 and 90, optimally
    C can only be placed before D and M, for 400 and 900. optimally.

    The thing to consider is the fact that only V, L, D can appear (excluding from subtractive pairs).
    After analysis, this is trivial, since the fact that these can only appear once is necessary for
    efficient numbering.


*/
//  D, L, and V can each only appear once. Prefixes of 5: 5, 50, 500.

//I = 1
//V = 5
//X = 10
//L = 50
//C = 100
//D = 500
//M = 1000


int solution() {

    FILE *inputFile;

    inputFile = fopen("./resources/roman.txt", "r" );

    char ch, prevCh = 48;

    int numChars = 0;
    int value = 0;
    int count = 0;
    int temp;

    int answer = 0;

    while ((ch = fgetc(inputFile)) != EOF) {

        if(ch != 10)
            printf("%c", ch);

        if(ch == 10) {
            printf("\n");


            temp = value;

            count = 0;

            count += value / 1000;
            value = value % 1000;
            if(value / 100 == 9 || value / 100 == 4)
                count +=2;
            else if(value >= 100) {
                if(value >= 500) {
                    count ++;
                    value -= 500;
                }
                count += value / 100;
            }
            value = value % 100;
            if(value / 10 == 9 || value / 10 == 4)
                count +=2;
            else if(value >= 10){
                if(value >= 50) {
                    count++;
                    value -= 50;
                }
                count += value / 10;
            }
            value = value % 10;
            if(value == 9 || value == 4)
                count +=2;
            else {
                if(value >= 5) {
                    count++;
                    value -= 5;
                }
                count += value;
            }

            printf("%d %d\n", temp, count);

            answer += numChars - count;

            prevCh = 'A';
            numChars = 0;
            value = 0;
        }

        else if (ch > 65) {

            if(ch == 'M'){
                if(prevCh == 'C')
                    value += 800;
                else {
                    value += 1000;
                }
            }
            if(ch == 'D') {
                if(prevCh == 'C')
                    value += 300;
                else {
                    value += 500;
                }
            }
            if(ch == 'C') {
                if(prevCh == 'X')
                    value += 80;
                else {
                    value += 100;
                }
            }
            if(ch == 'L') {
                if(prevCh == 'X')
                    value += 30;
                else {
                    value += 50;
                }
            }
            if(ch == 'X') {
                if(prevCh == 'I')
                    value += 8;
                else {
                    value += 10;
                }
            }
            if(ch == 'V') {
                if(prevCh == 'I')
                    value += 3;
                else {
                    value += 5;
                }
            }
            if(ch == 'I')
                value += 1;
            
            
            prevCh = ch;
            numChars++;
        }

    }

    count = 0;

    count += value / 1000;
    value = value % 1000;
    if(value / 100 == 9 || value / 100 == 4)
        count +=2;
    else if(value >= 100) {
        if(value >= 500) {
            count ++;
            value -= 500;
        }
        count += value / 100;
    }
    value = value % 100;
    if(value / 10 == 9 || value / 10 == 4)
        count +=2;
    else if(value >= 10){
        if(value >= 50) {
            count++;
            value -= 50;
        }
        count += value / 10;
    }
    value = value % 10;
    if(value == 9 || value == 4)
        count +=2;
    else {
        if(value >= 5) {
            count++;
            value -= 5;
        }
        count += value;
    }

    printf("%d %d\n", temp, count);

    answer += numChars - count;

    fclose( inputFile );

    return answer;
}

int main () {

    printf("%d", solution());

    return 0;
}