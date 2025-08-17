# include <iostream>
# include <vector>
# include <cmath>
# include <map>

//3:31 timer

void mutableSieve (std::vector<bool> &sieve) {
    int size = sieve.size();
    for(int i = size; i < size + 100000; i++) {
        sieve.push_back(true);
    }

    sieve[0] = false;

    for(int i = 2; i * i < sieve.size(); i++) {
        if(sieve.at(i)) {
            for(int j = i; j * i < sieve.size(); j++) {
                if(i*j >= size)
                    sieve.at(i*j) = false;
            }
        }
    }
}

int numDigits (int n) {
    int sum = 0;
    while(n != 0) {
        n /= 10;
        sum ++;
    }
    return sum;
}

void toBinary(bool * o, int i, int dig) {
    int index = dig - 1;
    while(i != 0) {
        o[index] = i % 2;
        i /= 2;
        index--;
    }
    for(int j = 0; j <= index; j++) {
        o[j] = 0;
    }
}

int solution () {

    std::vector<bool> sieve;

    for(int i = 1;;i++) {

        if(i >= sieve.size()) {
            i--;        
            mutableSieve(sieve);
            continue;
        }

        else if(sieve[i]) {

            int x = i;

            int check = -1;
            bool verify = true;

            int count = 0;
            int dig = numDigits(i);
            int * n = new int [dig];

            for(int l = dig -1; l >= 0; l--) {
                n[l] = x%10;
                x /= 10;
            }

            bool * o = new bool [dig];

            int num = 0;

            for(int l = 1; l < pow(2,dig);l++) {
                //std::cout<<"index: " << l <<std::endl;
                toBinary(o, l, dig);
                if(o[dig-1] == 0) {
                    count = 0;
                    num = 0;
                    check = -1;
                    verify = true;
                    for(int j = 0; j < 10; j++) {
                        num = 0;
                        for(int k = 0; k < dig; k++) {
                            if(o[k] == 1) {
                                if(j == 0 && k == 0)
                                    break;
                                else {
                                    num += j * pow(10, dig - k - 1);
                                }
                            }
                            else {
                                num += n[k] * pow(10, dig - k - 1);
                            }
                        }
                        while(num > sieve.size()) {
                            mutableSieve(sieve);
                        }
                        //std::cout<<num<<std::endl;
                        if(sieve[num])
                            count++;
                    }
                    if(count == 8) {
                        for(int y = 0; y < dig; y++) {
                            if(o[y]) {
                                if (check < 0)
                                    check = n[y];
                                else if (check != n[y]) {
                                    verify = false;
                                }
                            }
                        }
                        if(verify)
                            return i;
                    }
                }
            }
        }
    }
    return 0;
}

int main () {
    std::cout<<solution();
    //return 0;
}