#include <stdio.h>

#define L 50

// "Do I believe it though? No, I don't. But I don't have to believe it, if it's true."
// # If it's true, it's true.

// The approach entailed number of colinear sides with the x/y axes (horizontal or vertical lines).
// With two colinear sides, the triangle exists in a rectangle (/square). In this case 3 right triangles
// can exist in this rectangle. This was calculated to be 3*L*L. See note book.

// With 1,0 colinear sides, this was calculated by going through all possible triangles with a chosen
// point of 90 degrees. This was then multiplied by two to account for reflections across y = x,
// since we are dealing with the x-y axes.

// Took me too long to think about 0 colinear sides, and even 1 colinear side. Though I like my approach
// of colinearity with the x-y axes and tackled it to success! I knew I was right at the finale and told
// myself the header quote.

// Happy with my organized approach, I'm oversimplifying it, or making it seem trivial, but many 
// considerations and thoughts had to be made to assert this to be true, to some degree.
// Unhappy with how long it took me to realize 0 colinear sides. 
// Happy with realized that simply multiplying by two at the end is simple and true.

int numberOfTwoNonColinearSides () {

    int amount = 0;

    for(int i = 1; i <= L; i++) {
        for(int j = 1; j <= L; j++) {
            for(int k = i+1; k <= L;k++) {
                for(int l = 0; l <= j;l++) {

                    if(i*i + j*j + (k-i)*(k-i) + (j-l)*(j-l) == k*k + l*l) {
                        // printf("%d %d %d\n", i, j, k);
                        amount += 1;
                    }

                }
            }
        }
    }

    return 2*amount;

}

int main () {

    printf("%d\n", numberOfTwoNonColinearSides());

    int numberOfTwoColinearSides = 3*L*L;

    printf("ANSWER: %d", numberOfTwoNonColinearSides() + numberOfTwoColinearSides);




    return 0;
}