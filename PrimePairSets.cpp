#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

void mutableSieve (std::vector <bool> & sieve) {

    // auto start = std::chrono::high_resolution_clock::now();
    // int prev = sieve.size();
    for(int i = 0; i < 20000;i++) {
        sieve.push_back(true);
    }
    for(int i = 2;i*i< sieve.size();i++) {
        if(sieve[i]) {
            for(int j = i; i*j < sieve.size(); j++) {
                 sieve[i*j] = false;
            }
        }
    }
    // std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;
    // std::cout << "Time taken: " << duration.count() << " seconds." << std::endl;
}

int mulmod(int a, int b, int n) {
    int mod = 0;
    if(a < b) {
        while (a) {
            if(a & 1)
                mod = (mod%n + b%n)%n;
            b = (b%n + b%n) %n;
            a>>=1;
        }
        return mod%n;
    }
    while (b) {
        if(b & 1)
            mod = (mod%n + a%n)%n;
        a = ((a%n)*2)%n;
        b>>=1;
    }
    return mod%n;
}

int modpow(int a, int d, int n) {
    // int mod = 1;
    // for(int i = 0; i < d;i++) {
    //     mod = (mod * a%n) % n;
    // }
    // return mod;

    int mod = 1;
    while(d) {
        if(d & 1)
            mod = mulmod(mod,a,n);
        a = mulmod(a,a,n);
        d >>=1;
    }
    return mod;
}

// lets assume n, the maximum concatenation is less than 2^32, so ...
// let's try int (32 bit) before int64_t (64 bit) 
// => if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
bool isPrime (int n) {
    if(n%2 == 0 || n%3 == 0 || n % 5 == 0|| n % 7  == 0 || n % 11 == 0 || n % 13 == 0|| n % 17 == 0|| n % 19 == 0 || n%23 == 0)
        return false;
    bool probable = true;

    int a [3] = {2,6,61};
    int d = n-1;
    int s = 0;


    while(d%2 == 0) {
        d >>= 1;
        s++;
    }
    for(int i = 0; i < 3;i++) {
        if(!probable)
            return false;
        if(modpow(a[i],d, n) == 1)
            continue;
        else {
            probable = false;
            a[i] = modpow(a[i], d, n);
            for(int j = 0 ; j < s; j++) {
                if(a[i] == n- 1) {
                    probable = true;
                    break;
                }
                a[i] = mulmod(a[i],a[i],n);   
                // // we can create a new modpow method where (mod = (mod%n * a%n) % n;) - > (mod = (mod%n * a) % n;)
                // if(modpow(a[i],2,n) == -1)
                //     probable = true;
            }
        }
    }
    return probable;
}

bool leftRightPrime(int lr, int middle) {
    int l = lr*pow(10,floor(log10(middle)) + 1) + middle;

    // while(l >= sieve.size()) {
    //     mutableSieve(sieve);
    // }
    // if(!sieve[l])
    //     return false;
    if(!isPrime(l))
        return false;
    int r = middle*pow(10,floor(log10(lr)) + 1) + lr;
    // while(r >= sieve.size()) {
    //     mutableSieve(sieve);
    // }
    return (isPrime(r));
}

bool primePairSets(int array [5], int index) {
    for(int i = 0; i < index; i++) {
        if(!leftRightPrime(array[i], array[index]))
            return false;
    }
    return true;
}

// changed this to bool at the end to track the time.   
bool findPrimes(int solArr [5], int primeCap, int index, std::vector<bool> sieve, std::vector <int> &sums) {
    if(index == 5) {
        int sum = 0;
        for(int k = 0; k < 5; k++) {
            std::cout<<solArr[k]<<std::endl;
            sum += solArr[k];
        }
        sums.push_back(sum);
        return true;
    }
    else {
        for(int j = solArr[index-1] + 2; j < primeCap;j+=2) {
            // if(j== 1551)
            //     minSum = 2;

            // if(i == 19 && j == 31)
            //     std::cout<<"fd";
            if(j == 5);
            else if(sieve[j]) {
                solArr[index] = j;
                if(primePairSets(solArr, index))
                    if(findPrimes(solArr, primeCap, index+1, sieve, sums))
                        return true;
            }
        }
    }
    return false;
}

void solution() {

    int solArr [5] = {0};

    int index = 0;
    int primeCap= 10000;

    std::vector<int>sums;

    std::vector <bool> sieve;
    mutableSieve(sieve);

    auto start = std::chrono::high_resolution_clock::now();
    int prev = sieve.size();

    for(int i = 3; i < 20000 ;i++) {
        // if(i == 9999) {
        //     i = 2;
        //     primeCap = 4000;
        // }
        if(i== 5);
        else if(sieve[i]) {
            solArr[0] = i;
            index = 1;
            if(findPrimes(solArr, primeCap, index, sieve, sums)) {
                std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;
                std::cout << "Time taken: " << duration.count() << " seconds." << std::endl;
                break;
            }

        }
    }


    for(int i = 0; i < sums.size();i++) {
        std::cout<<sums[i]<<std::endl;
    }
}
 
int main() {
    // std::cout<<modpow(9,8, 351);
    // std::cout<<isPrime(505447);
    // std::cout<<modpow(8,9, 19);
    solution();
    // std::vector <bool> sieve;
    // mutableSieve(sieve);
    // std::cout<<sieve[19];

    return 0;
}   