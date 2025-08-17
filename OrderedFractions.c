#include <stdio.h>
#include <stdbool.h>

// void sieve(bool sieve []) {

//     for(int i = 2; i < 1000000; i++) {
//         sieve[i] = true;
//     }

//     for(int i = 2; i < 1000;i++) {

//         if(sieve[i]) {
//             for(int j = i; i*j<1000000;j++) {
//                 sieve[i*j] = false;
//             }
//         }

//     }

// }

bool isGreater1 (int a, int b) {
    return 7*a > b*3;
}

bool isGreater2 (int a, int b, int c, int d) {
    return b*c< a*d;
}

int HCF(int a, int b) {
    int temp = 0;
    while(b!=0) {
        temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

int solution () {

    int num = 3;
    int den = 8;

    int start = 0;

    // 
    for(int i = den + 1; i < 1000000 ; i++) {
        start = (i * 3)/7;
        // while(isGreater1(start,i)) {
        //     start--;
        // }
        if(isGreater2(start, i, num, den)) {
            if(HCF(start,i) == 1) {
                num = start;
                den = i;
                // printf("%d %d\n", num ,den);
                // break;
            }
            // start--;
        }
        
    }

    return num;
}



int main () {

    // bool sieve [1000000];

    printf("%d", solution());

    // printf("%d", HCF(17,34));

    return 0;
}