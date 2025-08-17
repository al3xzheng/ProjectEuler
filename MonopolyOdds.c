#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Monte Carlo Simulation. Learned the 5 sec meaning behind this terminology at work yesterday or 2 days ago.
// Realized I had to build a simulation when the results on the relative proportion each location
// can only be yielded as the number of plays approached infinity. Or estimated as n -> large. 
// Long story short.

// The crux is in determining the basis at which an ending location can be measured to. At first I thought
// it to be the the sums of the rolls on the die. This was realized to be implausible as one can roll
// something and end up somewhere different; jumpy. This meant I had to track the total ending locations 
// independently with reference to only the total number of locations went to.

// This is shown in going to "step"/n locations, and seeing of those n locations, how many are the most
// prominent. Again, to emphasize, this is an estimation, as n -> infinite, this becomes exact.

// The problem kind of revealed some of this "monte carlo"-esqueness when stating 
// " A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of 
// squares they advance in a clockwise direction. Without any further rules we would expect to visit each 
// square with equal probability: 2.5%."

// 3.5 h to finish + 1 h break in middle after 2 h. Suprisingly long given the triviality.

# define die 4

// can not declare 'steps' as a macro since it is an rvalue, not a modifiable l value.

int nextRailwayOrUtility(bool railway, int location) {

    if(location == 36) {
        if(railway)
            return 5;
        return 12;
    }
    if(location == 7) {
        if(railway)
            return 15;
        return 28;
    }
    if(location == 22) {
        if(railway)
            return 25;
        return 28;

    }

    return 0;

}

void populateCCAndCH (int cc [16], int ch [16]) {

    int markers [16];
    int random = 0;

    for(int i = 0 ; i < 16;i++) {
        markers[i] = 0;
    }

    for(int i = 0 ; i < 16 ; i ++) {

        random = rand() % 16;

        if(markers[random] == 0) {
            cc[i] = random;
            markers[random] = -1;
        }
        else {
            while(markers[random] != 0) {
                random = (random + 1) % 16;
            }
            cc[i] = random;
            markers[random] = -1;
        }

    }

    for(int i = 0 ; i < 16;i++) {
        markers[i] = 0;
    }

    for(int i = 0 ; i < 16 ; i ++) {

        random = rand() % 16;

        if(markers[random] == 0) {
            ch[i] = random;
            markers[random] = -1;
        }
        else {
            while(markers[random] != 0) {
                random = (random + 1) % 16;
            }
            ch[i] = random;
            markers[random] = -1;
        }

    }

}

void solution (int squares[]) {

    // maybe need to put this in the populate function above.
    srand(time(NULL));

    int cc [16];
    int ch [16];

    populateCCAndCH (cc, ch);   

    squares[0] = 1;

    int roll1 = 0, roll2 = 0, triple = 0;
    int steps = 1000000;

    // let the top of the deck start at the 0th index.
    int ccMarker = 0, chMarker = 0;

    int location = 0;

    while (steps > 0) {

        roll1 = rand() % die + 1;
        roll2 = rand() % die + 1;

        if(roll1 == roll2)
            triple++;
        else {
            triple = 0;
        }

        if(triple >= 3) {
            location = 10;
        }

        else {

            location += (roll1 + roll2);
            location = location%40;

            if(location == 30) {
                location = 10;
            }

            else if(location == 2 || location == 17 || location == 33) {

                if(cc[(ccMarker%16)] == 0) {
                    location = 0;
                }

                else if(cc[(ccMarker%16)] == 1) {
                    location = 10;
                }

                ccMarker++;
            }

            else if(location == 7 || location == 22 || location == 36) {

                if(ch[(chMarker%16)] == 0) {
                    location = 0;
                }

                else if(ch[(chMarker%16)] == 1) {
                    location = 10;
                }

                else if(ch[(chMarker%16)] == 2) {
                    location = 11;
                }

                else if(ch[(chMarker%16)] == 3) {
                    location = 24;
                }

                else if(ch[(chMarker%16)] == 4) {
                    location = 39;
                }

                else if(ch[(chMarker%16)] == 5) {
                    location = 5;
                }

                else if(ch[(chMarker%16)] == 9) {
                    location -=3;
                }

                else if (ch[(chMarker%16)] > 5 && ch[(chMarker%16)] < 9) {
                    location = nextRailwayOrUtility((ch[(chMarker%16)] == 6 || ch[(chMarker%16)] == 7), location);
                    if(location == 0)
                        printf("Bug here\n");
                }

                chMarker++;
            }
        
        }

        squares[location]++;
        
        steps--;

    }

}


int main() {

    int squares [40];

    for(int i = 0 ; i < 40 ; i++) {
        squares[i] = 0;
    }

    solution(squares);

    for(int i = 0 ; i < 40 ; i++) {
        printf("%d: %d\n", i, squares[i]);
    }

    return 0;
}