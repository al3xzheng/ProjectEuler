#include <stdio.h>

# define size 12

int factorial (int x) {
    if(x == 1 || x == 0)
        return 1;
    return x * factorial(x-1);
}

int choose (int a, int b) {
    return factorial(a) / (factorial(b) * factorial(a-b));
}

int generateN (int n) {

    int N = 0;

    for(int i = 2; i <= n ; i ++) {
        for(int j = 1; j <= i / 2; j++) {
            if(2*j == i) {
                N += (choose(n, j) * choose(n-j,i-j))/ 2;
            }
            else {
                N += choose(n, j) * choose(n-j,i-j);
            }
        }
    }

    return N;

}

int sumEqualityTestable(int index, int count, int first, int n, int marker, int array [size]) {
    // printf("%d\n", count);

    // for(int i = 0 ; i < size;i++) {
    //     printf("%d", array[i]);
    // }
    // printf("\n");

    if(count == n) {

        if(first == 0) {

            int track1 = 0;
            int track2 = 0;
            int sum = 0;

            for(int i = 0; i < n; i++) {
                while(array[track1] != marker) {
                    track1++;
                }
                while(array[track2] != 0) {
                    track2++;
                }
                if(track1 > track2)
                    sum += 1;
                else {
                    sum -= 1;
                }
                track1++;
                track2++;
            }
            if(sum > -1*n && sum < n) {
                // for(int i = 0 ; i < size;i++) {
                //     printf("%d", array[i]);
                // }
                // printf("\n");

                return 1;
            }
            return 0;
        }

        else {
            count = 0;
            index = 0;
            first = 0;
        }
        
    }

    if(index == size)
        return 0;

    int sum = 0;

    // configure the upper bound with size for the marker.
    for(int i = index; i < size; i++) {
        if(array[i] == -1) {
            array[i] = first;
            sum += sumEqualityTestable(i + 1, count + 1, first, n, marker, array);
            array[i] = -1;
        }
    }

    return sum;
    
}

int numTested (int n, int array [size]) {

    int num = 0;

    for(int i = 2; i <= n/2 ; i++) {

        if(2*i == n) {
            array[0] = 0;
            num += sumEqualityTestable(1, 1, 0, i, -1, array);
            // index starts at 1 for this one
            // !first  
        }
        else {

            // for(int i = 0 ; i < size;i++) {
            //     printf("%d", array[i]);
            // }
            // printf("\n");
            num += (sumEqualityTestable(0,0, 1, i, 1, array))/2;
        }

    }

    return num;

}


int main () {

    int n = size;

    // Generates total amount of subset pairs
    printf("%d\n", generateN(n));

    int array[size];

    for(int i = 0 ; i < size;i++) {
        array[i] = -1;
    }

    printf("%d", numTested(n, array));



    return 0;
}