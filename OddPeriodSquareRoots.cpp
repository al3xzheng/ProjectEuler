#include <iostream>
#include <cmath>

// made the correct assumption that c % a == 0 for all iterations based on precedence and intuition.
// Got it correct in 1 submission which is satisfying and comforting.
// took me a couple days to deduce the algorithm. Actually deduced it at work. See pdf.
// previous algorithm assumed that b0/"the original first divisor, c" = b. Was proved unfunctional and
// deduced error to produce correct algorithm from mistakes from 7,11,13.

int solution () {
    int n = 0;
    int period = 0;

    int a, b, c = 0;
    int b0 = 0;

    for(int i = 2; i <= 10000; i++) {
        if(sqrt(i) == floor(sqrt(i)))
            continue;
        
        period = 0;

        a = 1;
        b = floor(sqrt(i));
        c = i - b*b;

        while(a != c) {

            // for some reason the code didn't want to work if I didn't set a temporary to hold b as it messed up b <- f(b) when I wrote
            // b = f(b). I had to implement the b = f(b) step-wise which makes the code ugly but at the same time functional. 
            // can not be bothered to tilt and try to fix this issue right now.

            b0 = b;
            // b /= a;
            c /= a;

            b = (b+ floor(sqrt(i)))/c;
            b *= c;
            b = b - b0;
            a = c;

            // if((a * b) % divisor == 0)
            //     b = ((a * b  * c) / divisor) - a * b;
            // else {
            //     b = ((((a * b) / divisor) + 1) *c)  - a * b;
            // }

            c = (i - b*b);

            // if(c<0) {
            //     period = 0;
            //     while(c< 0) {
            //         a = 1;
            //         b = floor(sqrt(i));
            //         c = divisor;

            //         if((a * b) % divisor == 0)
            //             b = ((a * b  * c) / divisor) - a * b;
            //         else {
            //             b = ((((a * b) / divisor) + 1) *c)  - a * b;
            //         }

            //         b += iter * divisor;

            //         a = divisor;
            //         c = (i - b*b);
            //         iter++;
            //     }
                
            // }
            
            period++;
        }
        // std::cout<<period<<std::endl;
        if(period %2 == 0)
            n++;
    }
    return n;
}

int main () {
    std::cout<<solution();

    return 0;
}