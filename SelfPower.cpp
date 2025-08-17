#include <iostream>
using namespace std;

int gcd(int a, int b, int *x, int *y) { 
    if (a == 0)     { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
    int x1, y1;
    int gcd1 = gcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1;   
    return gcd1; 
} 

unsigned long long mulmod(unsigned long long a, unsigned long long b, signed long long c, unsigned long long M) {
    c = abs(c);
    unsigned long long result = 0;
    while(b) {
        if(b&1)
            result = (result + a) % M;
        a = (2*a) % M;
        b >>= 1;
    }
    a = result;
    result = 0;
    while(c) {
        if(c&1)
            result = (result+a) % M;
        a = (2*a) % M;
        c >>= 1;
    }
    return result;
}

unsigned long long modpow (unsigned long long b, unsigned long long e, unsigned long long M) {
    unsigned long long sum = 1;
    while(e > 0) {
        if(e & 1)
            sum = (sum * b) % M;
        b = (b*b) % M;
        e >>= 1;
    }
    return sum;
}

unsigned long long solution (unsigned long long m) {
    unsigned long long sum = 0;
    for(unsigned long long i = 1; i <= 1000;i++) {
        sum += modpow(i,i, m) % m;
    }
    return sum % m;
}

int main() {
    int x,y;
    cout<<gcd(1024, 9765625, &x, &y)<<endl;
    cout<<x << " "<<y<<endl;
    long long a = solution(1024);
    long long b = solution(9765625);
    cout<<a << " "<<b<<endl; 
    // cout<<(mulmod(1024, b, x, 10000000000)-mulmod(9765625, a, y, 10000000000)) % 10000000000<<endl;
    cout<<((1024 * b * x )+ (9765625 * a * y)) % 10000000000;

    // MODULO DOES NOT WORK ON NEGATIVE NUMBERS IN C++, HENCE MY TURMOIL AND ANGUISH!! 
    // THANKFULLY LEARNED A LOT ON MODULO CONGRUENCE!!

    // long long ans = 1024 * b * x;
    // long long ans = 9765625 * a * y;
    // long long ans1 = mulmod(1024, b, x, 10000000000);
    // long long ans2 = mulmod(9765625, a, y, 10000000000);
    // cout<< ans1 << " " << ans2 <<endl;
    // cout<<ans1-ans2<<endl;
    // long long ans3 = (1024 * b * x) % 10000000000;
    // long long ans4 = (9765625 * a * y)  % 10000000000;
    // cout<<ans3 << " " << ans4<<endl;
    // cout<<(ans3+ans4)%10000000000;


}