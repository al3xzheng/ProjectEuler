#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctime>

# define M 1818

// Simply did a binary search to determine the solution for M first exceeds 1 million to be 1818.


double solveForL (int l , int a, int b) {

    double x = (a*l)/(1.0*a+b);
    return sqrt(x*x + a*a) + sqrt((l-x)*(l-x) + b*b);

}

int solution1 (int numbers [100]) {

    // int M = 100;
    int sum = 0;
    int sides [3];

    double L;
    float min = 3*M;
    bool isInt;
    
    for(int i = 1; i <= M;i++) {

        for(int j = i; j <= M; j++) {

            for(int k = j; k <=M; k++) {

                // For a higher sided shape, I would store all the side values in an array, with size n
                // (# of sides) and iterate through with the necessary number of for-loops to get each 
                // necessary combination

                // For a cuboid, 1 for-loop iterated three times, with a 3-index array, will work.

                // Note that for a cuboid, potentially other shapes, for an a x b x c cuboid, the shortest
                // surface-path is the same if corner-to-corner in bottom surface and then back surface
                // for an a x b x c and a x c x b, since calculating x vs (a-x), which yields to same L.

                sides[0] = i;
                sides[1] = j;
                sides[2] = k;

                // if(i == 18 && j == 40 && k == 40)
                //     printf("here");

                min = 3*M;

                for(int q = 0; q < 3; q++) {

                    L = solveForL(sides[q],sides[(q+1)%3],sides[(q+2)%3]);

                    if(L < min) {
                        // printf("%f %d %d %d\n", solveForL(sides[q],sides[(q+1)%3],sides[(q+2)%3]),sides[q],sides[(q+1)%3],sides[(q+2)%3]);
                        min = L;
                    }
                    if(i == j && j== k)
                        break;
                }

                // printf("\n");

                if(min - (int) min == 0){
                    // printf("%f %d\n", solveForL(sides[0],sides[(1+1)%3],sides[(2+2)%3]),sides[0] + sides[(1+1)%3]+sides[(2+2)%3]);
                    printf("%f %d %d %d\n", solveForL(sides[2],sides[1],sides[0]),sides[2],sides[1],sides[0]);
                    int t = (round(solveForL(sides[2],sides[1],sides[0]))-sides[2]);
                    // if(sides[2] == 36 && sides[1] == 13) {
                    //     printf("hee%d", t);
                    //     sum += 0;
                    // }
                    if(t%2 == 0) {
                        t /= 2;
                        numbers[(int)sqrt(t*(t+sides[2]))]+= 1;
                        // if((int)sqrt(t*(t+sides[2])) == 8) {
                        //     printf("a eight his here %d", sides[2]);
                        // }
                    }
                    else {
                        numbers[(int)sqrt(t* (t+2*sides[2]))]++;
                        // if((int)sqrt(t* (t+2*sides[2])) == 6) {
                        //     printf("a six his here");
                        // }
                    }
                    if((int)sqrt(t* (t+sides[2])) == 3) {

                        // printf("333: \n%f %d %d %d\n", solveForL(sides[2],sides[1],sides[0]),sides[2],sides[1],sides[0]);

                    }
                    sum++;
                }

            }

        }

    }

    return sum;

}

bool isPrime (int n) {
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;

    for(int i = 3; i <= sqrt(n); i+=2) {

        if(n%i == 0)
            return false;

    }

    return true;

}

int sumPerDivision(int d, int i ) {

    if(d == 1)
        return 0;

    if((i*i)%d != 0)
        return 0;

    if(d >= i)
        return 0;

    if(i%2 == 0 && (i*i > d*(M+d)) || (i*i)/d-d <= i)
        return 0;


    if(i%2 == 1 && i*i > d*(2*M+d))
        return 0;  
            

    // figure out the in terger MINIMUM path sum. This seems to be for a<=b<=c, with a != b !=c. 
    // implement this trend with 
    // odds, it has ben implemented with evens.

    if(i%2 == 1 && i*i > d*(M+d)) {
        // printf("d: %d i: %d", d, i);
        if(i < (i*i)/d-d - i)
            return i/2;
        return ((i*i)/d -d - i + 1)/2;
    }

    int sum = 0;
    //figure out the divisoin. figure out the sqrt thing and creating divisions, may have to do the modulo

    // TODO: verify the 75^2 example and figure out the negative. it seems that the largest must be the
    // first value as shown in the ordering in the above solution. But not so clear.  Do an example.
    // no time right now
    if(i%2 == 0) {

        if(i < (i*i)/d-d - i)
            sum += i;
        
        else {
            sum += (i*i)/d -d - i +1;
        }

    }

    else {

        
        if(i < (i*i)/d-d - i) {
            sum += i + i/2;
        }
        
        else {
            sum += (i*i)/d -d - i +1;
            sum += ((i*i)/d -d - i+1)/2;
        }

    }

    // printf("% d %d %d %d %d sum:%d\n",d, (i*i)/d + d, (i*i)/d-d,i,i, sum);


    return sum;

}

int createDivisions (int primes [], int exponents[], int index, int x, int start, int value) {

    if(start == index)
        return 0;

    int sum = 0;

    for(int j = 0; j <= 2*exponents[start]; j++ ) {
        if(value != 1 && j == 0)
            sum += createDivisions(primes, exponents, index, x, start+1, value * round(pow(primes[start],j)));
    
        else if(value * round(pow(primes[start],j)) < x) {
            // if(x == 6)
            //     printf("here:%f", round(pow(primes[start],j)));
            sum += sumPerDivision(value * round(pow(primes[start],j)),x);
            sum += createDivisions(primes, exponents, index, x, start+1, value * round(pow(primes[start],j)));
        }
        else {
            break;
        }

    }

    return sum;

    // int sum = 0;

    // for(int i = 0 ; i < index ;i++) {

    //     for(int j = 1 ; j <= 2*exponents[i];j++) {

    //         if((int)pow(primes[i], j) >= x)
    //             break;

    //         sum += sumPerDivision((int)pow(primes[i], j), x);

    //         for(int k = i+1; k < index ;k++) {

    //             for(int q = 1; q <= 2*exponents[k]; q++) {

    //                 if((int)pow(primes[i], j)*(int)pow(primes[k], q) >= x)
    //                     break;

    //                 sum += sumPerDivision((int)(pow(primes[i], j)*pow(primes[k],q)), x);
    //             }
    //         }
    //     }
    // }

    // return sum;

}

// TODO: compare the sums with the real prev solution.
int solution () {

    int sum = 0;
    int sum1 = 0;

    int index = 0;
    int tracker = 1;
    int exponent = 0;

    for(int i = 2; i < (int) 2.25* M ; i++) {

        int * primes = (int*)calloc(ceil(log2(i)), sizeof(int));
        int * exponents = (int*)calloc(ceil(log2(i)), sizeof(int));

        tracker = i;
        index = 0;
        exponent = 0;

        // sum1 = 0;

        if(i*i -1 <= M) {
            sum += i;
            // sum1 += i;
            if(i%2 == 1)  {
                // sum1 += i/2;
                sum += i/2;
            }
        }

        // last problem of getting the primes where the M < i*i /2 < 2M, 5,7,3. in here. 
        if(i%2 == 1 && i*i - 1 > M && i*i-1 <= 2*M) {
            // sum1 += i/2;
            sum += i/2;
        }

        if(!isPrime(i)) {

            for(int j = 2; ; j++) {

                if(isPrime(j) && tracker % j == 0) {
                    exponent = 0;
                    primes[index] = j;
                    while(tracker % j == 0) {
                        tracker/= j;
                        exponent++;
                    }
                    exponents[index] = exponent;
                    index++;
                }

                if(tracker == 1)
                    break;

            }

            sum += createDivisions(primes, exponents, index, i, 0, 1);
            // sum1 += createDivisions(primes, exponents, index, i,0,1);

        }

        // if(sum1>0) {
        //     // printf("%d %d\n", i, sum1);
        // }

        free(primes);
        free(exponents);

    }

    return sum;

}

int main () {

    clock_t begin = clock();

    int sum = 0;

    // for(int i = 100; i >= 1;i--) {

    //     sum += (i*(i+1))/2;

    // }
    // int numbers [170];
    // for(int i = 0 ; i < 170;i++) {
    //     numbers[i] = 0;
    // }
    // printf("%d\n", solution1(numbers));

    printf("%d\n", solution());
    // // printf("%f", solveForL(6,3,5));+

    double time_spent = (double)(clock() - begin)/ CLOCKS_PER_SEC;

    printf("%f", time_spent);

    for(int i = 0 ; i < 170;i++) {
        if(!numbers[i] == 0) {
            printf("%d %d\n", i , numbers[i]);
            sum += numbers[i];
        }
    }

    printf("%d\n", sum);



}