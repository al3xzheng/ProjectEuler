#include <stdio.h>
#include <string.h>
#include <stdbool.h>

# define indexSize 5

// You can have an idea, a good idea, but there is a lot of skill and moreso idea generation, consideration, in executing the idea.

bool isAnagramAndUniqueAndWord (int i, int j) {

    // int dig [10] = {0};
    int place [indexSize];
    int index = indexSize - 1;

    // if(j != ((i/10000)% 10)*10000000 + (i/100000) * 10000 + (i%10000))
    //     return false;

    while (i > 0) {
        // if(dig[i%10] == 1)
        //     return false;
        // dig[i%10] += 1;
        place[index] = i% 10;
        index--;
        i /= 10;
    }
    // while (j > 0) {
    //     if(dig[j%10] == 0)
    //         return false;
    //     dig[j%10] -= 1;
    //     j /= 10;
    // }

    // reaction
    // for(int i = 0; i < 8;i++) {
    //     for(int j = i + 1; j < 8;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }
    // if(!(place[0] != place[1] && place[1] != place[2] && place[2] != place[3] && place[3] != place[4] && place[4] != place[5] && place[5] != place[6] && place[6] != place[7]))
    //     return false;
    //source
    // for(int i = 0; i < 6;i++) {
    //     for(int j = i + 1; j < 6;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }
    // if(!(place[0] != place[1] && place[1] != place[2] && place[2] != place[3] && place[3] != place[4] && place[4] != place[5]))
    //     return false;
    //centre
    // for(int i = 0; i < 5;i++) {
    //     for(int j = i + 1; j < 5;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }
    // if(place[1] != place[5])
    //     return false;
    // if(!(place[0] != place[1] && place[1] != place[2] && place[2] != place[3] && place[3] != place[4] && place[1] == place[5]))
    //     return false;
    // broad
    // for(int i = 0; i < 5;i++) {
    //     for(int j = i + 1; j < 5;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }
    // arise
    // for(int i = 0; i < 5;i++) {
    //     for(int j = i + 1; j < 5;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }
    //     for(int i = 0; i < 4;i++) {
    //     for(int j = i + 1; j < 4;j++) {
    //         if(place[i] == place[j])
    //             return false;
    //     }
    // }


    // reaction
    // return (j == (place[7] + place[6] * 10 + place[5] * 100 + place[4] * 1000 + place[2] * 10000 + place[1] * 100000 + place[0] * 1000000 + place[3] * 10000000) || j == (place[7] + place[6] * 10 + place[5] * 100 + place[4] * 1000 + place[0] * 10000 + place[3] * 100000 + place[2] * 1000000 + place[1] * 10000000));
    // source
    // return (j == (place[5] + place[0] * 10 + place[3] * 100 + place[2] * 1000 + place[1] * 10000 + place[4] * 100000));
    // centre
    // return (j == (place[3] + place[2] * 10 + place[1] * 100 + place[0] * 1000 + place[5] * 10000 + place[4] * 100000) || j == (place[1] + place[0] * 10 + place[5] * 100 + place[4] * 1000 + place[3] * 10000 + place[2] * 100000));
    // broad
    // return (j == (place[4] + place[1] * 10 + place[3] * 100 + place[2] * 1000 + place[0] * 10000) || j == (place[4] + place[2] * 10 + place[1] * 100 + place[3] * 1000 + place[0] * 10000));
     // arise
    // return (j == (place[4] + place[3] * 10 + place[2] * 100 + place[0] * 1000 + place[1] * 10000));
    // race
    // return (j == (place[3] + place[0] * 10 + place[1] * 100 + place[2] * 1000 ) || );   

    // return true;

}

int main() {

    FILE *inputFile;

    inputFile = fopen("./resources/anagramicsquares.txt", "r" );

    char ch;
    int length = 0;
    int max = 0;
    long long maxSquare = 0;

    int alphabet [26] = {0};
    int test [26];
    // There are 1785 words
    int lengths [1786];

    int index = 0;

    // int squares [9939];

    // for(int i = 1; i < 9939; i++) {

    //     squares[i] = i*i;

    // }

    // create numbers that abide by one, and create the next one automatically for scalability.
    // 6 unique: 333 - 993 (inc)
    // 8 unique 3514 - 9938 (inc)
    // 5 unique: 105 - 314
    // 4 unique: 33 -99

    // Answer: 18769 @ BOARD - > BROAD
    for(int i = 105; i < 315;i++) {
        for(int j = i + 1; j < 315; j++) {
            if(isAnagramAndUniqueAndWord(i*i,j*j)) {
                printf("%d %d\n", i*i, j*j);
            }
        }
    }


    while ((ch = fgetc(inputFile)) != EOF) {


        if(ch == 34) {
            // if(length > max) {
            //     max = length;
            // }
            for(int i = 0 ; i < 2;i++) {
                ch = fgetc(inputFile);
            }

            lengths[index] = length;
            index++;
            length = 0;
        }

        else {
            if(index == 246)
                printf("%c", ch);
            length++;
        }

    }
    
    // printf("%d", index);

    int maxLength = 0;
    int uniqueletters = 0;
    bool anagram;

    for(int i = 1; i < 1786; i++) { //1786
        
        inputFile = fopen("./resources/anagramicsquares.txt", "r" );

        index = 0;
        uniqueletters = 0;

        for(int j = 0 ; j < 26;j++) {
            alphabet[j] = 0;
        }

        // if(lengths[i-1] < maxLength)
        //     continue;

        while(index != i) {

            ch = fgetc(inputFile);

            if(ch == 34) {
                // if(length > max) {
                //     max = length;
                // }
                for(int l = 0 ; l < 2;l++) {
                    ch = fgetc(inputFile);
                }
                index += 1;
            }
            

            else if(index == i - 1) {

                // if(alphabet[ch-65] == 0)
                //     uniqueletters++;
                alphabet[ch-65] += 1;

            }

        }

        // if(i == 508)
        //     printf("%d", i);

        // if(uniqueletters > 10)
        //     continue;

        memcpy(test, alphabet, 26 * sizeof(int));
        anagram = (lengths[i-1]==lengths[i]);

        while ((ch = fgetc(inputFile)) != EOF) {


            if(anagram) {

                if(test[ch-65] > 0) {
                    test[ch-65] -= 1;
                }

                else {
                    anagram = false;
                    while ((ch = fgetc(inputFile)) != 34) {

                    }
                }

            }

            if(ch == 34) {


                if(anagram) {
                    printf("%d %d\n", i-1, index);
                    for(int k = 0 ; k < 26;k++) {
                        if(alphabet[k] > 0) {
                            printf("%c", k + 65);
                        }
                    }
                    printf("\n");
                }

                // if(length > max) {
                //     max = length;
                // }
                for(int l = 0 ; l < 2;l++) {
                    ch = fgetc(inputFile);
                }
                memcpy(test, alphabet, 26 * sizeof(int));
                index++;
                anagram = (lengths[i-1] == lengths[index]);
            }

        }

        fclose( inputFile );

    }

    printf("%d", max);


    return 0;
}