#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

// void mutableMethod(std::vector <bool> &sieve) {
//     for(int i = 0; i < 100000; i++) {
//         sieve.push_back(true);
//     }
//     for(int i = 2; i * i <sieve.size();i++) {
//         if(sieve[i]) {
//             for(int j = i;j*i< sieve.size();j++) {
//                 sieve[i*j] = false;
//             }
//         }
//     }
// }

bool isPrime(int64_t t) {
    for(int i =2; i <= floor(sqrt(t));i++) {
        if(t % i == 0)
            return false;
    }
    return true;
}

int solution() {
    // std::vector <bool> sieve;
    // mutableMethod(sieve);
    int n = 0;
    int64_t val = 0;
    for(long long i = 3;  ;i+=2) {
        for(long long j = 1; j <= 3;j++) {
            val = i*i-j*(i-1);
            n+= isPrime(val);
        }
        // std::cout<<n/((2.0*i)-1)<<std::endl;
        if(n/((2.0*i)-1) < 0.1)
            return i;
    }  
    return 0;
}

int main() {
    std::cout<<solution();
    return 0;
}