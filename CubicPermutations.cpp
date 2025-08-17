#include <iostream>
#include <cstdint>
#include <math.h>
#include <unordered_map>
#include <vector>
// just int64_t and brute force it. the higher the number of digits the higher chance of cubic permutations, so 2^64 is infered to work
// just write a function to verify same digits, if 2^64 doesn't work use vector-int.

// code-ization algorithm of generating codes of digits, fairly simple and optimistic algorithm which works since
// "the higher the number of digits the higher chance of cubic permutations", so code-izing is valid.

int64_t digitsCode (int64_t i) {
    int64_t value = i*i*i;

    int digits[10] = {0};

    while(value) {
        digits[value % 10] += 1;
        value /= 10;
    }

    int64_t code = 1;

    for (int i = 0 ; i < 10 ; i ++) {
        if(digits[i] != 0)
            code *= pow(10, floor(log10(digits[i])) + 1);
        else {
            code *= 10;
        }
        code += digits[i];

    }
    return code;
}

int64_t solution () {

    std::unordered_map <int64_t, int> codePair;
    std::unordered_map <int64_t, std::vector <int>> numberPair;

    int64_t code = 0;

    for(int64_t i = 1; ; i++) {

        code = digitsCode(i);
        // std::cout<<code<< " " << i <<std::endl;

        // std::cout<<code<<std::endl;
        // numberPair[code] *= pow(10, floor(log10(i)) + 1);
        // numberPair[code] += i;
        // if(numberPair.find(code) == numberPair.end())
        numberPair[code].push_back(i);
        codePair[code] += 1;
        if(codePair[code] == 5) {
            std::cout<<code<<std::endl;
            for(int k = 0 ; k < numberPair[code].size();k++) {
                std::cout<<numberPair[code][k]<<std::endl;
            }
            return numberPair[code][0];
        }
    }
    return 0;
}

int main() {
    // the answer is the cube, not the cube root LMAO, i solved it this morning, found 5027, went to the outdoors, came back
    // optimized my code, and realized i was correct and submitted the cube. Was confused this morning.
    std::cout<<solution();

    return 0;
}