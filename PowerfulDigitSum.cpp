#include <iostream>
#include <vector>

// originally got the sum of all digital sums of a^b, where a,b < 100 and a,b of the natural numbers: 3282177
// but the answer actually wants the maximum digital sum of a^b for all a,b, of natural numbers and < 100.
// If I would've known this, i would've started from a,b = 99 and went down, but in the end same process, as I don't think
// i would mathematically try to find a cutoff point, although it would be very plausible and frankly easy. answer: a = 99, b = 95.

int digitalSum (int a, int b) {
    std::vector <int> sum;
    std::vector <int> add;
    int carry = 0;
    int inter = 0;

    int n = a;
    while(n!=0) {
        sum.push_back(n%10);
        n/=10;
    }

    for(int i = 0; i < b-1;i++) {
        add = sum;
        for (int o = 0; o < a-1;o++) {
            carry = 0;
            for(int j = 0; j < sum.size();j++) {
                if(j== add.size())
                    add.push_back(0);
                inter = sum[j] + add[j] + carry;
                sum [j] = inter%10;
                carry = inter/10;
            }
            if(carry > 0) {
                sum.push_back(carry);
            }

        }
    }

    int digitalsum = 0;

    for(int i =0; i < sum.size();i++) {
        digitalsum += sum[i];
    }
    return digitalsum;
}

int solution () {
    int sum = 0;
    int inter = 0;
    for(int a = 2; a <100;a++) {
        if(a%10 == 0) ;
        else {
            for(int b = 1; b < 100; b++) {
                inter = digitalSum(a,b);
                if(inter > sum) {
                    sum = inter;
                    std::cout<<a << " " << b <<std::endl;
                }
            }
        }
    }
    return sum;
}


int main() {
    // std::vector <int> sum;
    // sum.push_back(2);
    // std::cout<<digitalSum(2,12);
    std::cout<<solution();
    return 0;
}