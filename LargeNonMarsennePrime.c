#include <stdio.h>
#include <math.h>

long long solution () {

    int cycle = 7830457;
    long long n = 1;
    // long long lastTen;

    // while(n / 1000000000 == 0) {
    //     n *= 2;
    // }

    // long long start = n%10000000000;

    // n = (start*2)%10000000000;

    // while(n != start) {
    //     if(cycle == 17956)
    //         lastTen = n;
    //     n = (n*2)%10000000000;
    //     cycle++;
    // }

    while(cycle > 0) {
        n = (n * 2) % 10000000000;
        cycle--;
    }

    printf("%lld\n", n);
    // printf("%lld\n", cycle);

    // int section = 7830457/ cycle;
    // int bits = 7830457%cycle;

    // printf("%d", bits);

    long long sum = 0;
    int index = 0;

    while(n != 0) {
        sum = (sum + ((n%10)*28433)*(int)pow(10,index))%10000000000;
        index++;
        n /= 10;
    }

    return sum + 1;

}

int main () {

    printf("%lld", solution());
    return 0;

}