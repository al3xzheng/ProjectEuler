# include <iostream>

using namespace std;

bool * genSieve () {
    static bool sieve [1000000];
    for(int i = 2; i < 1000000;i++) {
        sieve[i] = true;
    }
    for(int i = 2; i * i < 1000000; i++) {
        if(sieve[i]) {
            for(int j = i ; i * j < 1000000; j++) {
                sieve[i*j] = false;
            }
        }
    }
    return sieve;
}

int main () {
    bool * sieve1 = genSieve();
    int i;
    int maxPrime = 1;
    int sum = 0;
    int maxSum;
    int count = 0;
    int maxCount = 0;
    int start;
    // upper bound for k, finding/proving it would require a lot of thinking (nontrivial);
    for(int k = 2; k < 1000000;k++) {
        if(sieve1[k]) {
            // sum = 0;
            // count = 0;
            for(i = maxPrime + 1; sum < 1000000;i++) {
                if(sieve1[i]) {
                    sum+=i;
                    count++;
                    if(sum != 2 && sum > 0 && sum < 1000000 && sieve1[sum]) {
                        if(count > maxCount) {
                            start = k;
                            maxPrime = i;
                            maxCount = count;
                            maxSum = sum;
                            cout<<maxSum << " " << maxCount<< " " << maxPrime<< " " << k << endl;
                        }
                    }
                }
            }
            count = maxCount;
            sum = maxSum;
            for(int l = start; l <= k; l++) {
                if(sieve1[l]) {
                    count--;
                    sum -= l;
                }
            }

        }
    }
    cout<<"done?";
}