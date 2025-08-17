#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// document how i debugged this issue very quickly but not thoughtfully to account for my lack of debugging
// mathematical thinking. Could]ve donne my mathematical thinking but just printed it out instead.

// 1. get a solution to this function calling
// 2. Verify the array creation and deletion (can be tricky)

void populateArithmeticExpressions(float nums[], int * consecutive, int size) {

    if(size == 1 && nums[0] > 0) {
        // printf("%f\n", nums[0]);
        if((nums[0] - (int)nums[0]) == 0)
            consecutive[(int)nums[0]] = 1;
        return;
    }

    for(int i = 0; i < size;i++) {

        float * smaller = (float*)malloc((size-1)*sizeof(float));

        for(int j = i+1;j < i + size; j++) {
            smaller[j - i - 1] = nums[j%size];
        }

        for(int j = 0; j < size-1; j++) {

            float * operation = (float*)malloc((size-1)*sizeof(float));
            memcpy(operation, smaller,(size-1)*sizeof(float));

            float rem = operation[j];

            operation[j] = rem + nums[i];
            populateArithmeticExpressions(operation, consecutive, size-1);
            operation[j] = rem - nums[i];
            populateArithmeticExpressions(operation, consecutive, size-1);
            operation[j] = rem * nums[i];
            populateArithmeticExpressions(operation, consecutive, size-1);
            if(nums[i] != 0) {
                operation[j] = rem/nums[i];
                populateArithmeticExpressions(operation, consecutive, size-1);
            }

            free(operation);

        }

        free(smaller);

    }

}

void solution () {

    int max = 0;
    int count = 0;
    int index = 0;

    float arr[4];

    for(int i = 9; i >= 3;i--) {

        arr[0] = i*1.0;

        for(int j = i - 1; j >= 2;j--) {

            arr[1] = j*1.0;

            for(int k = j - 1; k >= 1;k--) {

                arr[2] = k*1.0;

                for(int q = k - 1; q >= 0; q--) {

                    arr[3] = q*1.0;

                    index = 1;
                    count = 0;

                    int * consecutive = (int*)calloc(i*j*(k+1)*(q+1)+1, sizeof(int));

                    populateArithmeticExpressions(arr, consecutive, 4);

                    // printf("%d %d %d %d\n", q,k,j,i);


                    while(consecutive[index] == 1) {
                        // printf("%d\n", consecutive[index]);
                        count = index;
                        index++;
                    }

                    free(consecutive);

                    if(count > max) {
                        max = count;
                        printf("%d: %d %d %d %d\n", count, q,k,j,i);
                    }

                }


            }


        }


    }


}


int main () {

    // float test[4];
    // test[0]=4;

    // float x = 4/3;

    // printf("%f", x);

    solution();


    return 0;
}