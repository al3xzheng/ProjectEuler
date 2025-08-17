#include <string>
#include <iostream>
#include <stdint.h>

//89 takes an unusually large 24 iterations. size errors => minimize iteration size
//(the most of any number under 10,000 that is known to resolve into a palindrome) to reach the palindrome 8813200023188.
//https://en.wikipedia.org/wiki/Lychrel_number

bool isPalindrome (long long x) {
    std::string n = std::to_string(x);
    int len = n.length();
    for(int i = 1 ; i<= n.length()/2 ; i++) {
        if(n[i-1] != n[len - i])
            return false;
    }
    return true;
}

int64_t reverse (long long n ) {
    int64_t reversed = 0;
    while (n != 0) {
        reversed *= 10;
        reversed += n%10;
        n/=10;
    }
    return reversed;
}

int solution () {
    int count = 0;
    int iter = 0;
    int64_t x = 0;
    for(int i = 196; i < 197;i++) {
        x = i;
        iter = 1;
        x += reverse(x);
        while(!isPalindrome(x) && iter < 50) {
            x += reverse(x);
            iter++;
        }
        if(iter == 50) {
            count++;
        }
    }
    return count;
}

int main() {
    //std::cout<<reverse(41247);
    std::cout<<solution();
    return 0;
}