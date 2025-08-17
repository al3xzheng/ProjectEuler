#include <stdio.h>
#include <math.h>

int solution () {

    // 1 to 1999. 1999 is the upper bound since its "# of squares" value is the closest to 2 million.
    // Actuallly shared distance/closeness with 2000. So we take 1999.
    int lengthsToNumSquares [2000];

    for(int i = 1; i < 2000;i++) {

        // don't need to break it up and check which part of i or i + 1 is even and divide through first
        // and then multiply to avoid overflow, since i is 2000 <<.
        lengthsToNumSquares[i] = (i*(i+1))/2;

    }

    int distToTwoMill;
    int j;
    int min = __INT_MAX__;
    int answer;

    for(int i = 1; i < 2000; i++) {

        distToTwoMill = __INT_MAX__;

        // Upper bound for j.
        // Takes n^2 + n = x to be n^2 = x, such that determining n will be an overestimate (j is n)
        // since x - n < x.
        j = (int) sqrt(4000000/lengthsToNumSquares[i]);

        while(abs((lengthsToNumSquares[i] * lengthsToNumSquares[j]) - 2000000) < distToTwoMill) {

            distToTwoMill = abs(lengthsToNumSquares[i] * lengthsToNumSquares[j] - 2000000);
            if(distToTwoMill < min) {
                min = distToTwoMill;
                printf("%d %d %d\n", i, j, distToTwoMill);
                answer = i * j;
            }
            j--;

            if(j == 0)
                break;
            
        }

    }

    return answer;

}


int main () {

    printf("\n%d\n", solution());

    return 0;
}