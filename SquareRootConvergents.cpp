#include <vector>
#include <iostream>

//153

std::vector <int> add (std::vector <int> a, std::vector <int> b) {
    int carry = 0;
    int inter = 0;
    if(a.size() > b.size()) {
        for(int i = 0; i < a.size(); i++) {
            if(i == b.size())
                b.push_back(0);
            inter = a[i] + b[i] + carry;
            a[i] = inter%10;
            carry = inter/10;
        }
        if(carry > 0) {
            a.push_back(carry);
        }
        return a;
    }
    for(int i = 0; i < b.size(); i++) {
        if(i == a.size())
            a.push_back(0);
        inter = a[i] + b[i] + carry;
        a[i] = inter%10;
        carry = inter/10;
    }
    if(carry > 0) {
        a.push_back(carry);
    }
    return a;
}

// int maxDigits (std::vector <int> a, std::vector <int> b) {
//     if(a.size() > b.size())
//         return a.size();
//     return b.size();
// }

int solution () {
    std::vector <int> numerator;
    numerator.push_back(3);
    std::vector <int> denominator;
    denominator.push_back(2);

    std::vector <int> store;

    int count = 0;

    for(int i = 1 ; i < 1000;i++) {
        store = denominator;
        denominator = add(numerator, denominator);
        numerator = add(add(store,store),numerator);

        if(numerator.size() > denominator.size())
            count++;

    }
    return count;
}

int main () {
    std::cout<<solution();
}