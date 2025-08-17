# include <cmath>
# include <iostream>
# include <string.h>

//1:44

void getDigits(int (&digits) [10], int n) {
    while(n) {
        digits[n%10] += 1;
        n /= 10;
    }
}

bool verify ( int digits [10], int n) {
    while(n) {
        if(digits[n%10] == 0)
            return false;
        digits[n%10] -= 1;
        n /= 10;
    }
    return true;
}

void copy1(int (&dummy) [10], int (&digits) [10]) {
    for(int i =0; i < 10;i++) {
        dummy[i] = digits[i];
    }
}

int solution() {
    int digits [10] = {0};
    int dummy [10] = {0};
    bool valid;

    for(int i = 0; ;i++) {
        for(int j = pow(10, i); j <= floor(pow(10, i+1)/6);j++) {
            memset(digits, 0, sizeof(digits));
            getDigits(digits, j);
            valid = true;

            for(int k = 2; k <=6;k++) {
                copy1(dummy,digits);
                if(!verify(dummy, k*j)) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                return j; 
            }
            
        }
    }
    return -1;
}

int main () {
    std::cout<<solution();
    return 0;
}