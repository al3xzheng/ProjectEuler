#include <stdio.h>

# define min 2
# define max 99
// # define solutionParameter 2

// Think a bit more about the cases and possibilities and scenarios, very basic right now.
// Uncover new cases and verify cases!

// Need to consider how a large checkout would work since there's some issues right now with assuming
// a large checkout works on i - De = 0 + k.

// Need to verify large checkouts with bullseye D25 = 50
// consider crafted test cases mentally.

int solution () {

    int k;
    int l;
    int count1, count2;

    int total = 0;

    // for(int o = 99; o <= 99; o++) {

    for(int i = min; i <= max; i++) {

        for(int j = 2; j <= 42;j +=2) {

            if(j == 42)
                j = 50;

            k = i - j;

            // if(k>=100)
            //     continue;

            if(k < 0)
                break;
            
            if(k == 0)
                total += 1;
            
            else {
                total += (k<=20 || k == 25) + ((k <= 40 || k == 50) && k%2 == 0) + (k<= 60 && k%3 == 0);
            }

            for(int q = 1; q <= k / 2; q++) {

                count1 = (q<=20 || q == 25) + ((q <= 40 || q == 50) && q%2 == 0) + (q<= 60 && q%3 == 0);
                l = k - q;
                if(l == q) {
                    total += (count1*(count1 + 1))/2;
                }
                else {
                    count2 = (l<=20 || l == 25) + ((l <= 40 || l == 50) && l%2 == 0) + (l<= 60 && l%3 == 0);
                    total += count1 * count2;
                }


            }

        }

    }

    // }

    


    return total;

}

int main () {

    printf("%d %d", solution(), 42336 - solution());

    return 0;
}