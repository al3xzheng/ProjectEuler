public class DigitFactorials {

    static int factorial (int N) {
        if(N == 0)
            return 1;
        return(N * factorial(N-1));
    }

    static int DigitFactorial (int N) {
        int sum = 0;
        while(N != 0) {
            sum += factorial(N%10);
            N /= 10;
        }
        return sum;
    }
    public static void main(String[] args) {
        int sum = 0;
        for(int i = 3; i <= 999999; i++) {
            if(DigitFactorial(i) == i)
                sum +=i;
        }
        System.out.println(sum);
    }
}
