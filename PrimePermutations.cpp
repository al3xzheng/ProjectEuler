#include <unordered_set>
#include <iostream>

using namespace std;

bool isPermutation (int x, int y) {
    int digits [10] = {0,0,0,0,0,0,0,0,0,0};
    while(x) {
        digits[x%10]++;
        x/=10;
    }
    while(y) {
        if(digits[y%10] == 0)
            return false;
        digits[y%10]--;
        y/=10;
    }
    return true;
}

bool* genSieve() {
    static bool sieve [10000];
    for(int i = 2; i < 10000; i++) {
        sieve[i] = true;
    }
    for(int i = 2; i * i < 10000; i++) {
        if(sieve[i]) {
            for(int j = i; i * j < 10000; j++) {
                sieve[i*j] = false;
            }
        }
    }
    return sieve;
}

int main () {
    bool * sieve = genSieve();
    for(int i = 1001; i < 10000; i++) {
        if (sieve[i]) { 
            for(int j = i + 1; (2*j - i) < 10000; j++) {
                if(sieve[j] && sieve[2 * j - i]) {
                    // cout<<i << " " << j << " " << 2 * j - i << " "<<endl;
                    if(isPermutation(i,j) && isPermutation(j,2* j - i))
                        cout<<i << " " << j << " " << i + 2*(j-i)<<endl; 
                }
            }
        }
    }
    return 0;
}