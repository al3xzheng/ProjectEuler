#include <stdio.h>


int sumPathsToN(int N, int largest) {
    if(N<0)
        return 0;
    if(N == 0)
        return 1;
    int answer = 0;
    for(int i = largest; i>= 1;i--) {
        answer += sumPathsToN(N-i,i);
    }
    return answer;
}

int main() {

    int n = 100;
    printf("%d", sumPathsToN(n,n-1));

    return 0;
}