# include <cmath>
# include <iostream>

//56:20

int solution() {
    int count = 0;
    long double product;
    for(int i = 23; i <=100;i++) {
        for(int j = 1; j <= (i/2); j++) {
            product = 1.0;
            for(int k = i; k > j;k--) {
                product = (product*k)/(k-j);
            }
            if((product / 3628800) > 0.2755732) {
                count += 2*(i/2 - j) + 1;
                if(i%2 == 1)
                    count++;
                j = i/2;
            }
        }
    }
    return count;
}

int main() {
    std::cout<<solution();
}