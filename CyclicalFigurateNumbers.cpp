#include <iostream>
#include <unordered_set>
#include <cmath>

bool findCyclic (int number, int set, int sets [6][90], std::unordered_set <int> nums, int original) {
    if(nums.find(number) != nums.end())
        return false;
    nums.insert(set);
    nums.insert(number);
    if(nums.size() == 12) {
        if(number % 100 != original)
            return false;
        for (const auto& elem : nums) 
            std::cout << elem << ' ';
        std::cout<<std::endl;
        return true;        
    }
    for(int i = 1; i < 6;i++) {
        if(nums.find(i) == nums.end() && sets[i][(number%100) - 10] != 0) {
            int iter = (floor(log10(sets[i][(number%100) - 10])) + 1) / 2;
            for(int j = 0 ; j < iter;j++) {
                if(findCyclic((number%100) *100 + (sets[i][(number%100) - 10] /(int(pow(100, j)))) %100, i, sets, nums, original))
                    return true;
            }
        }
    }
    return false;
}
// This question really grew my love for computational mathematics. It's about faith in your code and debugging that issue knowing
// that the problem/issue is something new and to something to be explored.
// The issue is not something wrong with your current code or something to aimlessly doublecheck, but to be creative.
// Especially in the realm of recursion (which is my realm, but something I'm actually not to experience in), this 
// visualization and search for the problem by visualizing stream and branches was amazing.

// Found the issue that in recursion, one should basically not touch (i.e. pass by reference) ,unless certain, the arguments.
// as things may get sneakily edited and seemingly seem like nothing is wrong.
// If you edit things unknowingly this basically removes the siphoning process that is recursion of making your answer realized
// by removing possible streams!
// So happy I found this error and then debugged properly, again, to correct my dumb typo by not malding!

// Issue: I was editing sets in the recursive function to obtain the possible last two digits for a given first two digits and removing
// these after they have been searched.
// BUT, cannot touch these as if this search fails, the next search which one of which will succeed may rely on this search later,
// so by removing previously searched ones (which fail, as if success, then success), it eliminates the possibility of researching through
// these necessary opportunities.

void solution() {

    // can trivially get the upper and lower bounds of n for each formula from quadratic formula calculator and verifying
    // we can calculate equations trivially, let's just check manually, it is faster than calculating the bounds for each equation, like
    // what i did for the minimum lower and maximum upper bounds of n for all equations :( ...

    int n1, n2;
    n1 = n2 = 1;
    int bounds1, bounds2;
    bounds1 = bounds2 = 1;
    while(bounds2 < 10000) {
        if(bounds1 < 1000) {
            bounds1 += 6*n1 + 1;
            n1++;
        }
        bounds2 += n2 + 1;
        n2++;
    }

    int val = 0;
    int sets [6][90] = {0};

    for(int i = n1-1; i < n2;i++) {
        val = (i*i + i)/2;
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[0][val/100 -10] = sets[0][val/100 - 10] * 100 + val % 100;
        val = (i*i);
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[1][val/100 - 10] = sets[1][val/100 - 10] * 100 + val % 100;
        val = (3*i*i - i)/2;
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[2][val/100 - 10] = sets[2][val/100 - 10] * 100 + val % 100;
        val = (2*i*i - i);
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[3][val/100 - 10] = sets[3][val/100 - 10] * 100 + val % 100;
        val = (5*i*i - 3*i)/2;
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[4][val/100 - 10] = sets[4][val/100 - 10] * 100 + val % 100;
        val = (3*i*i - 2*i);
        if(val > 999 && val < 10000 && (val % 100) > 9)
            sets[5][val/100 - 10] = sets[5][val/100 - 10] * 100 + val % 100;
    }

    std::unordered_set <int> nums;

    for(int i = 0; i < 90;i++) {
        if(sets[0][i] != 0) {
            findCyclic((i+10)*100 + sets[0][i]% 100, 0, sets, nums, i+10);
            sets[0][i] /= 100;
            i--;
        }
    }

}

int main() {
    solution();
    // std::cout<<floor(log10(8));
    return 0;
}


