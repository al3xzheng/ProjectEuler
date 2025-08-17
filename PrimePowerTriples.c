#include <stdio.h>
#include <math.h>

#define size 50000000

void sieve (int * nums) {

    for(int i = 2; i < size+1; i++) {
        nums[i] = 1;
    }

    for(int i = 2; i <= 7071;i++) {
        if(nums[i]) {

            for(int j = i; i*j < size+1;j++) {

                nums[i*j] = 0;

            }

        }
    }

}

int solution(int * nums, int * check) {

    int sum = 0;

    for(int i = 2; i <= sqrt(size-24);i++) {

        if(nums[i]) {

            for(int j = 2; j <= cbrt(size- i*i-16)  ; j++) {

                if(nums[j]) {

                    for(int k = 2; k <= sqrt(sqrt(size-i*i-j*j*j));k++) {

                        if(nums[k]) {

                            // printf("%d %d %d\n", i,j,k);

                            if(check[i*i + j*j*j + k*k*k*k] == 0) {
                                sum++;
                                check[i*i + j*j*j + k*k*k*k] = 1;
                            }

                        }

                    }

                }

            }

        }

    }

    return sum;


}

int main() {

    int * nums = (int*) malloc((size+1)*sizeof(int));
    int * check = (int*) calloc((size+1),sizeof(int));

    sieve(nums);

    printf("%d", solution(nums, check));

    return 0 ;
}