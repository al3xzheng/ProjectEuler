#include <stdio.h>
#include <stdbool.h>

bool populateDifferencesCheck (int difference, int index, bool start, int n, int add, int sub, int set[12]) {

    // Think more on where this should go and concretely decide how the n interaction should go; should it
    // finish it off?

    if(!start && difference == 0 )
        return false;
    
    if(add > sub && difference < 0)
        return false;

    if(add < sub && difference > 0)
        return false;

    // The below is just to test for valid starting elements of a set used in the previous question.
    // if(!start && (add == sub) && abs(difference) != set[index - 1] && difference < 39) {
    //     diff[abs(difference)] = 1;
    // }

    if(index == n)
        return true;
    
    if(start) {
        if(!populateDifferencesCheck(set[index], index + 1, false, n, add + 1, sub, set))
            return false;
        if(!populateDifferencesCheck(-1*set[index], index + 1,  false, n, add, sub + 1, set))
            return false;
        if(!populateDifferencesCheck(difference, index + 1, true, n, add, sub, set))
            return false;
    }

    else {
        if(!populateDifferencesCheck(difference + set[index], index + 1, false,n,add + 1, sub, set))
            return false;
        if(!populateDifferencesCheck(difference - set[index], index + 1, false,n,add, sub + 1, set))
            return false;
        if(!populateDifferencesCheck(difference, index + 1, false, n,add, sub, set))
            return false;
    }

    return true;

}

int main () {

    FILE *inputFile;

    inputFile = fopen("./resources/sets.txt", "r" );
    
    char ch;

    int sum = 0;
    int answer = 0;

    int set [12];

    int number = 0;
    int n = 0;
    int line = 1;

    while ((ch = fgetc(inputFile)) != EOF) {

        if(ch == 44) {
            set[n] = number;
            sum += number;
            number = 0;
            n++;
        }

        else if(ch == 10) {
            set[n] = number;
            sum += number;

            // for(int i = 0;i <= n;i++) {
            //     printf("%d ", set[i]);
            // }
            // printf("\n");
            // if(n > 0 && set[n] == set[n-1]) {
            //     while((ch = fgetc(inputFile)) != 10) {}
            // }
            // else {
            n++;
            if(populateDifferencesCheck(0, 0, true, n,0,0, set)) {
                answer += sum;
                printf("%d: %d\n", line, sum);
            }
            // }
            n = 0;
            sum = 0;
            number = 0;
            line++;
        }

        else {
            number *= 10;
            number += ch - 48;
        }

    }

    printf("Answer: %d\n", answer);


    return 0;
}