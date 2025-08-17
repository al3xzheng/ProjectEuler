#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

# define size 10000000
# define maxSize ((int)(log((size))/log(2)))

// Previously... A forward looking algorithm


// Actually goes n - 1, but since 1 000 000 / 10 000 000 isn't prime it's ok
void siever (bool sieve [], int * primeSize) {
    for(int i = 2; i < size;i++) {
        sieve[i] = true;
    }
    for(int i = 2; i < size;i++) {
        //bound to sqrt(size) ... will manually add here
        if(sieve[i] && i < 3163) {
            for(int j = i; i * j < size;j++) {
                sieve[i*j] = false;
            }
        }
    }
    int temp = 1;
    for(int i = 2; ;i++) {
        if(size/temp < i)
            break;
        if(sieve[i]) {
            temp *= i;
            *primeSize +=1;
        }
    }
}

bool isPermutation(int a, int b) {
    int * track = (int*)calloc(10, sizeof(int));
    while(a) {
        track[a%10]++;
        a/=10;
    }
    while(b){
        if(track[b%10]==0)
            return false;
        track[b%10]--;
        b/=10;
    }
    for(int i = 0; i<10;i++) {
        if(track[i] > 0)
            return false;
    }
    free(track);
    return true;
}

// int factorial(int a) {
//     if(a == 1)
//         return 1;
//     return a*factorial(a-1);
// }

// int choose (int a, int b) {
//     return factorial(a)/(factorial(b)*factorial(a-b));
// }

// int countRepeating(int unique[], bool sieve [], bool uniqueSieve [], int value, int uindex, int factor, bool flag, int original) {
//     // if(value == 30)
//     //     printf("here");
//     if(uindex == 1 && flag)
//         return 0;
//     if((uindex == 1 && factor > 1) || (uindex == 2 && value/unique[0] <= unique[1]))
//         return 0;

//     int k = 0;
//     int tot = 0;
//     int bound1 = 0;
//     int bound2 = 0;
//     int newf = 0;

//     int scale = uindex;
//     // if(value == 60) {
//     //     printf("here");
//     // }

//     if (flag){
//         int * a = (int*)malloc((uindex-1)*sizeof(int));
//         for(int t = 0; t < uindex - 1;t++) {
//             a[t] = unique[t+1];
//         }
//         tot += countRepeating(a, sieve, uniqueSieve, value, uindex - 1, 0, flag, original);
//     }

//     if(factor == 1) {
//         for(int i = 2; i< (int)ceil((float)value / unique[0]); i++) {
//             // printf("%d\n", i);
//             // if(i < 0) {
//             //     for (int n = 0 ; n  < uindex;n++) {
//             //         printf("Arr %d %d %d ", unique[n]);
//             //     }
//             // }
//             // if(unique[0] == 18);
//             //     printf("%d ", i);
//             if(sieve[i]) {
//                 if(i <= original && uniqueSieve[i])
//                     continue;
//                 if(uindex % scale == 0) {
//                     unique = (int*) realloc(unique, (uindex + 15)*sizeof(int));
//                     scale += 15;
//                     // int * temp = (int*)malloc((uindex + 18)*sizeof(int));
//                     // for(int h = 0 ; h < uindex; h++) {
//                     //     temp[h] = unique[h];
//                     // }
//                     // free(unique);
//                     // unique = temp;

//                 }

//                 unique[uindex] = i;
//                 uindex++;
//             }
//         }
//         // if(value == 96) {
//         //     // printf("Bounds: %d \n", value / unique[0] +1 );

//         //     for (int n = 0 ; n  < uindex;n++) {
//         //         printf(" | %d ", unique[n]);
//         //     }
//         //     printf("\n");

//         // }


//     }




//     for(int k = 1; k < uindex; k++) {

//         bound1 = (int)(ceil (log(value/(float)unique[k]) / log(unique[0]) ) );
//         if(pow(unique[0], bound1-1)*unique[k] == value)
//             bound1--;
//         // if(value == 12)
//         //     printf("paramount: %d", bound1);
//         // if(unique[0] == 3 && value == 420)
//         //     printf("Bound: %d", bound1);
//         newf = factor;
//         if(unique[k] <= original && uniqueSieve[unique[k]])
//             newf++;

//         for(int q = 1; q < bound1; q++) {
//             bound2 = (int)(ceil(log(value/((float)pow(unique[0],q))) / log(unique[k])) ) ;
//             if(pow(unique[0], q)*pow(unique[k], bound2-1) == value)
//                 bound2--;



//             // if(unique[0] == 3 && value == 420)
//             //     printf("Bound: %d", bound2);
//             tot += (bound2 - 1)*newf;


//             for(int l = 1; l < bound2; l++) {
//                 // if(value == 1680 && (int)(pow(unique[0],q) * pow(unique[k],l)) == 175) {
//                 //     printf("\n ");
//                 //     for(int c = 0 ; c < uindex; c++) {
//                 //         printf("%d %d %d ", unique[c],q,l);
//                 //     }
//                 //     printf("\n ");
//                 // }
//                 // if(value == 420 && unique[0] == 3 && q == 4)
//                 //     printf("COWERW");
//                 // if((int)(pow(unique[0],q) * pow(unique[k],l)) == 405)
//                 //     printf("COWERW");
//                 if(value == 420)
//                     printf("(%d %d) %d [%d*%d]",q, l, (int)(pow(unique[0],q) * pow(unique[k],l)), newf,uindex);


//                 int * a = (int*)malloc((uindex-k)*sizeof(int));


//                 a[0] = (int)(pow(unique[0],q) * pow(unique[k],l));
//                 for(int t = k+1; t < uindex;t++) {
//                     a[t - k] = unique[t];
//                 }
//                 tot += countRepeating(a, sieve, uniqueSieve, value, uindex - k, newf, false, original);
//             }

//         }
//     }
//         // k = j + 1;
//         // while(k%uindex != j) {
//         //     // if(value == 60) {
//         //     //     printf("start %d ", (int)(ceil(log(value/unique[j]) / log(unique[k%uindex]))));
//         //     // }
//         //     if(k%uindex < j)
//         //         tot -=1;
//         //     else {
                
//             // }
//             // tot += (int)(ceil(log(value/unique[j]) / log(unique[k%uindex])))-1;
//         //     // k++;
//     //     // }
//     // if(value == 42)  
//     //     printf("%d ",(int)(pow(unique[j],q) * pow(unique[k],l)));  
//     // // if(value == 924)
//     // //     printf("\n%d %d\n", tot, value);

//     // if(value == 924)
//     //     printf("\n%d %d\n", tot, value);
//     // printf("\ntot: %d\t", tot);
//     // if(tot > value)
//     //     printf("tot: %d value: %d\n", tot, value);
//     return tot;
// }


void find (int prev, bool sieve[], int track[], int index, int value, int primeSize, float * max, int * answer) {

    if(value != 1) {

        // for(int i = 0 ; i < 19 ; i ++) {
        //     printf("%d ", track[i]);
        // }

        // printf(" %d |", value);
    
        // int tot = 0; //can put this on the heap if stack memory overflow.

        if(value ==87109)
            printf("here");

        int * unique = (int*)calloc(primeSize, sizeof(int));
        int uindex = 0;
        int extra = 1;
        for(int i = 0; i < maxSize; i++) {
            // printf("%d ", track[i]);
            if(track[i] == 0) {
                // printf("%d", 1);
                // if(uindex == 2 && i == 2)
                //     tot += 1;
                break;
            }
            else if(i < maxSize - 1 && track[i] == track[i+1]) {
                // printf("%d", 3);
                extra *= track[i];
                continue;
            }
            else {
                // printf("%d", 4);
                // tot += (value-1)/track[i];  //SAME AS value/track[i] ... then subtract N(unique)
                unique[uindex] = track[i]; 
                uindex++;
            }
        }
        // if(value == 210) {
        //     printf("this value: %d %d\n", value, tot);
        // }

        // for(int i = 0 ; i < maxSize ; i ++) {
        //     printf("%d ", track[i]);
        // }
        // printf("max total: %d\n", tot);
        // if(value == 630)
        //     printf("%d prev", tot);
        // printf(" uindex: %d ",uindex);
        // if(uindex > 1) {
        //     bool * uniqueSieve = (bool*)calloc((unique[uindex-1] + 1),sizeof(bool));
            
        //     for(int w = 0 ; w < uindex;w++) {
        //         uniqueSieve[unique[w]] = true;
        //     }
        //     tot -= countRepeating(unique,sieve, uniqueSieve, value, uindex, 0, true, unique[uindex-1]);
        //     free(uniqueSieve);
        //     // uniqueSieve = nullptr; optional since uniqueSieve is in the scope.
        // }
        

        // printf("%dhere\n", tot);

        double ratio = 1.0;
        int totient = 1;
        for(int i = 0 ; i < uindex; i++) {
            totient *= unique[i]-1;
            ratio *= (1.0*unique[i])/(unique[i]-1);
        }
        free(unique);


        if(isPermutation(value, extra*totient)) {
            if(ratio < *max) {
                printf("%d %d %f\n", value, extra*totient, ratio);
                *max = ratio;
                *answer = value;
            }
        }
        // (value*1.0)/(value-1-tot); //can put this on the heap if stack memory overflow.

        // printf("%d %d %f\n", value, extra*totient, ratio);

        // if(ratio < 0)
        // if(value == 210)
        //     printf(" 210: %d ratio: %f value: %d\n", tot, ratio, value);
        // // }
        // if(ratio < 0) {
        //     // printf("%d %d\n", value, tot);
        // }
        // printf(" %f\n", ratio);


        // if(ratio > *max){
        //     // printf("%f %d \n", ratio, value);
        //     *max = ratio;
        //     // printf("%d\n", value);
        //     *answer = value;
        // }


    }
    // A singular prime value n can not have a totient value that is a permutation of n, since totient(n) = n-1.

    for(int i = prev; i < size;i++) {
        if(sieve[i]) {
            // if(i = 5)
            //     printf("hello");
            // printf("%d", i);
            track[index] = i;
            int * a = (int*) calloc(maxSize,sizeof(int));
            memcpy(a,track, maxSize*sizeof(int));
            if(size / value < i)
                return;
            find(i, sieve, a, index + 1, value * i, primeSize, max, answer);
        }
    }

    // for(int i = prev; i >= 2;i--) {
    //     if(sieve[i]) {
    //         // if(i = 5)
    //         //     printf("hello");
    //         // printf("%d", i);
    //         track[index] = i;
    //         int * a = (int*) calloc(maxSize,sizeof(int));
    //         memcpy(a,track, maxSize*sizeof(int));
    //         if(size / value >= i)
    //             find(i, sieve, a, index + 1, value * i, primeSize);
    //     }
    // }

    // for(int i = prev; i <= size/2;i++) {
    //     if(sieve[i]) {
    //         // if(i = 5)
    //         //     printf("hello");
    //         // printf("%d", i);
    //         track[index] = i;
    //         int * a = (int*) calloc(maxSize,sizeof(int));
    //         memcpy(a,track, maxSize*sizeof(int));
    //         if(size/ value < i)
    //             return false;
    //         if(find(i, sieve, a, index + 1, value * i, max, answer))
    //             return true;
    //     }
    // }
    // printf("%d", max);
}

int main() {

    // printf("%d\n",(int) floor (510510/5.539388));

    // bool sieve [1000];
    bool * sieve = (bool*) malloc(10000000*sizeof(bool));

    int primeSize = 0;

    siever(sieve, &primeSize);

    // printf("%d", primeSize);

    int track [maxSize] = {0};

    float Max = 10;
    int answer = 0;

    // for(int i = 0 ; i < 19 ; i ++) {
    //     printf("%d ", sieve[i]);
    // }
    // printf("\n");

    find(2, sieve, track, 0, 1, primeSize, &Max, &answer);

    printf("%d", answer);
    return 0;
}