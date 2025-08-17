#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definitely my favourite problem so far. I liked how I didn't blindy submit the base algorithm solution
// and proved my solution and proved it.
// Since I effectively generated the solution from scratch and would have gotten it through my algorithm
// I had to use the base algorithm sequences as a way to double check my algorithm and make sure as a 
// test case. This proves that an algorithm for a base example is generally super important to
// moreso act as a foundation to work upon and as testcases, rather to actually generate the "solution"

// Super proud of myself of actually understanding the problem and solving it.

// I realized that due to the definition of an appropriate sequence that the "middle" term would essentially
// dictate a sequence.

/*
What I mean:
Since second_half - first_half - 1 = "middle", and we want to minimize the entire sum of the sequence as
our goal, then essentially we want to increase the sum of the first half, and decrease the sum of the second
half, this decreases the middle term. But we don't actually want to increase the sum of the first half, we
actually just want to keep it constant since, increasing it would increase the overall sum. Knowing this
is kind of useless actually. My algorithm didn't know this, it just chose numbers that would work lmao.

But that was my idea and I think it makes sense and is true. It's just that my idea wasn't proved since no
smaller sequences were found.

So based on my idea, we essentially set the sum constant for the first half, ideally it is 89, such that
it stays the same since an increase, or decrease, would cause an increase in the overall sum. 89 is the sum
of the first half from the algorithm. Since this yielded no solutions, the second option is to increase/decrease
it. At the end of the day, I couldn't tell whether to increase or decrease it, since the correct answer was
not yielded, but my intuition says to increase the sum, while still find such that "middle - k", doesn't
increase.

So this is a very complex question that actually shows that a brute force naive solution is the hidden solution

I'm excited to try my idea in the further problems to prove it.abort

I couldn't really explain my intuitoin properly. Part of it came from working outside in the ENV and HH
bench area. It's just that i understood how the arithmetic sequence works in that it is always increaisng
and I knew that the middle term is directly the difference between the upper-lower halves. Knowing this,
I built many relationships (and knowing the first term), the proved to be very fortuitous. And aiding me
in building a "brute force solution", that I would say is the best solution, that gave me the answer.

Basically, I understood the problem well enough such that I could build the parameters to solve this.
SOlving for A1, A2, from knowing the starting term and dummy (decreasing) "middle" values and knowing that
the sum for the first half should ideally stay constant. Then knowing the sum of the first half and the "middle"
value I could generate the numbers for the second half knowing its sum.
*/

#define n 7

bool populateDifferencesCheck (int difference, int index, bool start, int add, int sub, int set[n], int diff[39]) {

    if(!start && difference == 0 )
        return false;
    
    if(!start && (add == sub) && abs(difference) != set[index - 1] && difference < 39) {
        diff[abs(difference)] = 1;
    }

    if(index == n)
        return true;

    if(start) {
        if(!populateDifferencesCheck(set[index], index + 1, false, add + 1, sub, set, diff))
            return false;
        if(!populateDifferencesCheck(-1*set[index], index + 1,  false, add, sub + 1, set, diff))
            return false;
        if(!populateDifferencesCheck(difference, index + 1, true, add, sub, set, diff))
            return false;
    }

    else {
        if(!populateDifferencesCheck(difference + set[index], index + 1, false,add + 1, sub, set, diff))
            return false;
        if(!populateDifferencesCheck(difference - set[index], index + 1, false,add, sub + 1, set, diff))
            return false;
        if(!populateDifferencesCheck(difference, index + 1, false, add, sub, set, diff))
            return false;
    }

    return true;

}

void populateDifferences (int difference, int index, bool start, int add, int sub, int set[n], int diff[93]) {


    if(!start && (add == sub) && abs(difference) != set[index - 1] && difference < 93) {
        diff[abs(difference)] = 1;
    }

    if(index == n)
        return;

    if(start) {
        populateDifferences(set[index], index + 1, false, add + 1, sub, set, diff);
        populateDifferences(-1*set[index], index + 1,  false, add, sub + 1, set, diff);
        populateDifferences(difference, index + 1, true, add, sub, set, diff);
    }

    else {
        populateDifferences(difference + set[index], index + 1, false,add + 1, sub, set, diff);
        populateDifferences(difference - set[index], index + 1, false,add, sub + 1, set, diff);
        populateDifferences(difference, index + 1, false, add, sub, set, diff);
    }

}

void solution (int diff[39]) {

    int count = 0;

    int seq[7];
    seq[0] = 20;

    int K;

    for(int s = 100; s > 60 ;s--) {

        for(int c = 39; ; c--) {

            if(c<(s+3)/2)
                break;

            for(int i = s + 1 - c; i <= s/2 && i < c - 1; i++) {

                int j = s - i;

                // Use the critical information that I realized that the c is actually Sum_large - Sum_small - 1.
                // The fixed value is the 89 - Sum_small - may have to change that and go up with our (little)
                // headroom.

                // see what other fixed values I can change.
                // Note: realizing what constnat values I were using was criical in making those variables
                // and building a more flexible solution.
                K = s + 20 + c - 1;
                
                for (int k = c+ 1; k <= K/3 -1;k++) {
                    for(int l = k + 1; l <= (K - k)/2; l++) {
                        for(int q = l+1; q <= K -k -l; q++) {

                            if(q > l) {

                                seq[1] = i;
                                seq[2] = j;
                                seq[3] = c;
                                seq[4] = k;
                                seq[5] = l;
                                seq[6] = q;

                                if(populateDifferencesCheck(0, 0, true, 0, 0, seq, diff))
                                    printf("%d %d %d %d %d %d %d\n", 20, i, j, c, k, l ,q );
                                count++;
                            }

                        }
                    }
                }
            }
        }
    }

    printf("%d", count);

    // figure out the modulo k algorithm and its internals. We'll be using it, but it needs further
    // investigation.


}

int main () {

    // int set [n] = {11,17,20,22,23,24};
    // int set [n] = {11,18,19,20,22,25};
    int set [n] = {20, 31, 38, 39, 40, 42, 45};

    //set[1] + set[2] + set[3] + set[4] + set[5] - set[0] = 93
    int diff [39] = {0};

    // printf("%d", populateDifferencesCheck(0, 0, true, 0, 0, set, diff));


    // for(int i = 1 ; i < 93; i++) {
    //     if(diff[i] == 1)
    //         printf("%d ", i);
    // }

    solution(diff);


    return 0;
}