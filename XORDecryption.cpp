#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

// i kind of cheated by first using an online source to get number of elements in the list first.

int xorDecrypytion (int a, int b, std::unordered_map <int,int> &memo) {
    int m = a*1000+b;
    if(memo.find(m) != memo.end()) {
        return memo[m];
    }
    std::vector <int> a1;
    std::vector <int> b1;
    std::vector <int> x;

    //LSB first
    while(a != 0 || b != 0 ) {
        a1.push_back(a%2);
        b1.push_back(b%2);
        a /=2;
        b /=2;
    }
    for(int i = 0;i < a1.size();i++) {
        x.push_back(a1[i] != b1[i]);
    }
    int ans = 0;
    for(int i = 0; i < x.size();i++) {
        if(x[i])
            ans += pow(2,i);
    }
    memo[m] = ans;
    return ans;
}

int solution() {

    std::ifstream input;
    input.open("resources/cipher.txt");

    std::string content;
    
    std::getline(input, content, '\0');

    input.close();

    std::stringstream ss(content);
    std::string item;
    int cipher [1455];
    int index = 0;

    while(std::getline(ss, item, ',')) {
        cipher[index] = std::stoi(item);
        index++;
    }

    // for(int i = 0; i < 1455;i++) {
    //     std::cout<<cipher[i];
    // }

    std::stringstream dec;
    int pw [3];
    int t = 0;

    std::unordered_map<int,int> memo;
    // dec << char(97);
    // dec << char(98);
    std::cout<<dec.str()<<std::endl;
    bool read = true;

    for(int i = 97; i <= 122;i++) {
        for(int j = 97;j<=122;j++) {
            for(int k = 97; k <= 122;k++) {
                pw[0] = i;
                pw[1] = j;
                pw[2] = k;
                dec.str(std::string());
                dec << i << j <<k;
                read = true;
                for(int l = 0; l < 1455;l++) {
                    t = xorDecrypytion(cipher[l], pw[l%3], memo);
                    if(t <= 122)
                        dec << char(t);
    	            else {
                        read = false;
                        break;
                    }
                }
                if (read)
                    std::cout<<dec.str()<<std::endl;
            }
        }
    }

    dec.str(std::string());
    pw[0] = 101;
    pw[1] = 120;
    pw[2] = 112;
    int sum = 0;
    for(int q = 0 ; q < 1455; q++) {
        sum += xorDecrypytion(cipher[q], pw[q%3], memo);
        dec << char(xorDecrypytion(cipher[q], pw[q%3], memo));
    }
    std::cout<<dec.str()<<std::endl;
    return sum;
}

int main() {
    std::cout<<solution();
    // std::cout<<"done";
}
