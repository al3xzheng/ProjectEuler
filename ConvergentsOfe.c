#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// must be some overflow

void subtract (int * a, int *b) {
    int end = -1;
    for(int i = 0 ; i < sizeof(b)/sizeof(int); i ++) {

        if(*(a+i) == -1) {
            *(a + i) = 9;
            *(a + i + 1) -=1;
            end = -1;
        }
        if(*(a+i) >= *(b+i)) {
            if(*(a+i) == *(b+i) && end == -1) {
                end = i;
            }
            else {
                end =-1;
            }
            *(a +i) = *(a +i) - *(b +i);
        }
        else {
            *(a +i) = *(a +i) + 10 - *(b +i);
            *(a + i + 1) -= 1;
            end = -1;
        }
    }
    if(end == -1)
        a = (int*)realloc(a, end);
}

bool larger (int * a, int * b) {
    if(sizeof(a) > sizeof(b))
        return true;
    if(sizeof(a) == sizeof(b)) {
        for(int i = sizeof(a)/sizeof(int) - 1; i >= 0 ;i--) {
            if(*(a+i) == *(b+i)) {
                if(i == 0)
                    return true;
                continue;
            }
            if(*(a+i) > *(b+i))
                return true;
            return false;
        }
    }
    return false;
}


int moddivide (int * a, int * b) {
    int n = 0;
    while (larger(a,b)) {
        subtract(a,b);
        n++;
    }
    return n;
}


void mod(int * a, int * b) {
    int sizeb = sizeof(b)/sizeof(int), sizea = 0;
    int f = 0;
    int *t1;
    while (larger(a,b)) {
        sizea = sizeof(a)/sizeof(int);
        free(t1);
        t1 = (int*)malloc(sizea-sizeb);
        for(int i = sizeb; i < sizea; i++ ) {
            *(t1 + i - sizeb ) = *(a+i);
        }
        if(larger(t1,b)) {
            // f = divide(t1,b);
            // memcpy(t2, b, sizeof(b));
            // multiply(t2, f);
            // subtract(t1, t2);
            moddivide(t1,b);
            a = (int*)realloc(a, sizeb + sizeof(t1)/sizeof(int));
            for(int i = sizeb; i< sizeof(a)/sizeof(int);i++) {
                *(a+i) = *(t1 + i - sizeb);
            }
        }
        else { 
            t1 = (int*)realloc(t1, sizea-sizeb + 1);
            for(int i = sizea-sizeb;i >= 1 ;i--) {
                *(t1 + i) = *(t1 + i - 1);
            }
            *(t1) = *(a + sizeb - 1);
            moddivide(t1,b);
            // multiply(b, f);
            // subtract(t1, b);
            a = (int*)realloc(a, sizeb - 1 + sizeof(t1)/sizeof(int));
            for(int i = sizeb -1; i< sizeof(a)/sizeof(int);i++) {
                *(a+i) = *(t1 + i - (sizeb -1));
            }
        }
    }
    int * temp = a;
    a = b;
    b = temp;
}

void gcd (int * a, int * b) {
    while (sizeof(b) > 0) {
        mod(a,b);
    }
    // return a;
}

void multiply (int * a, int n, int sizen, int sized) {
    int c = 0;
    int size = sizen;
    for (int i = 0; i < size; i++) {
        *(a +i) = (n**(a+i) + c) % 10;
        c = (n**(a+i) + c)/10;
        if(i == size - 1 && c !=0) {
            a = (int*)realloc(a, size + 1);
            *(a + size) = c;
        }
    }
}

void add (int * a, int * b) {
    int c = 0;
    int size = 0;
    if(sizeof(b) > sizeof(a)) {
        size = sizeof(a)/sizeof(int);
        for(int i = 0; i < size; i++) {
            *(a+i) = (*(a+i) + *(b+i) + c)%10;
            c = (*(a+i) + *(b+i) + c)/10;
            if(c !=0 && i == size-1) {
                a = (int*)realloc(a, size + 1);
                *(a+size) = c;
            }
        }
    }
    else {
        size = sizeof(b)/sizeof(int);
        for(int i = 0; i < size; i++) {
            *(b+i) = (*(b+i) + *(a+i) + c)%10;
            c = (*(b+i) + *(a+i) + c)/10;
            if(c !=0 && i == size-1) {
                b = (int*)realloc(b, size + 1);
                *(b+size) = c;
            }
        }
    }
}

void divide (int * a, int * b) {
    int * c;
    int sizeb = sizeof(b)/sizeof(int), sizea = 0;
    int f = 0;
    int *t1;
    while (larger(a,b)) {
        sizea = sizeof(a)/sizeof(int);
        free(t1);
        t1 = (int*)malloc(sizea-sizeb);
        for(int i = sizeb; i < sizea; i++ ) {
            *(t1 + i - sizeb ) = *(a+i);
        }
        if(larger(t1,b)) {
            // f = divide(t1,b);
            // memcpy(t2, b, sizeof(b));
            // multiply(t2, f);
            // subtract(t1, t2);
            f = moddivide(t1,b);
            a = (int*)realloc(a, sizeb + sizeof(t1)/sizeof(int));
            for(int i = sizeb; i< sizeof(a)/sizeof(int);i++) {
                *(a+i) = *(t1 + i - sizeb);
            }
        }
        else { 
            t1 = (int*)realloc(t1, sizea-sizeb + 1);
            for(int i = sizea-sizeb;i >= 1 ;i--) {
                *(t1 + i) = *(t1 + i - 1);
            }
            *(t1) = *(a + sizeb - 1);
            f = moddivide(t1,b);
            // multiply(b, f);
            // subtract(t1, b);
            a = (int*)realloc(a, sizeb - 1 + sizeof(t1)/sizeof(int));
            for(int i = sizeb -1; i< sizeof(a)/sizeof(int);i++) {
                *(a+i) = *(t1 + i - (sizeb -1));
            }
        }
        c = (int*)realloc(c, sizeof(c)/sizeof(int) + 1);
        *(c+ sizeof(c)/sizeof(int) - 1) = f;
    }
    int temp = 0;
    for(int i = 0 ; i < sizeof(c)/sizeof(int)/2; i++) {
        temp = *(c+i);
        *(c+i) = *(c + sizeof(c)/sizeof(int) - i - 1);
        *(c + sizeof(c)/sizeof(int) - i - 1) = temp;
    }
    a = c;
}

void addFractions(int a, int * num, int * den, int * sizen, int  * sized) {
    int *n = (int*)malloc(*sizen * sizeof(int));
    int *d = (int*)malloc(*sized * sizeof(den));
    memcpy(n, den, *sized * sizeof(int));
    multiply(n, a, *sizen, *sized);
    add(n,num);
    memcpy(d, den, sizeof(den));
    memcpy(num,n, sizeof(n));
    gcd(n, d);
    divide(num, n);
    divide(den, n);
}

void solution() {

    int sizen = 1, sized = 0;

    int max = 14;

    int * num = (int*)malloc(4);
    *num = 1;
    int * den = (int*)malloc(sizeof(int));
    *den = 0;

    int * temp;
    int q = 0;

    if(max % 3 == 2)
        q = 2* (max/3 + 1);
    else {
        q = 1;
    }
    // den = (int*)realloc(den, 2*sizeof(int));


    while(q != 0) {
        den = (int*)realloc(den, ((sizeof(den)/sizeof(int)) + 1)*sizeof(int));
        *(den + sizeof(den)/sizeof(int) - 1) = q%10;
        q/=10;
        sized++;
    }

    for(int i = max-1; i >= 0; i--) {
        if(i == 0)
            addFractions(2, num, den, sizen, sized);
        else if(i%3 == 2) {
            addFractions(2* (i/3 + 1), num, den);
        }
        else {
            addFractions(1, num, den);
        }
        if(i != 0) {
            num = temp;
            num = den;
            den = temp;
            // num = num ^den;
            // den = num ^den;
            // num = den ^ num;
        }


        // num = num + den;
        // den = num - den;
        // num = num - den;

        // invert; swap a,b using addition or xor trick.
    }

    // printf("%lld\n", num);

    int sum = 0;
    for(int i = 0 ; i < sizeof(num)/sizeof(int);i++) {
        printf("%d", *(num + i));
        sum += *(num + i);
    }
    // while (num != 0) {
    //     sum += num % 10;
    //     num /= 10;
    // }

    printf("\n%d", sum);


}

int main () {
    solution();
    return 0;
}