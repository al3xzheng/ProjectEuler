public class Digit5thPowers {

    static int [] FifthPowers = new int [10];

    static int getPowerSum (int N) {
        int sum = 0;
        while(N != 0) {
            sum += FifthPowers[N%10];
            N /= 10;
        }
        return sum;
    }
    public static void main(String[] args) {
        int sum = 0;
        for(int i = 1; i < 10; i++) {
            FifthPowers[i] = (int)Math.pow(i, 5);
        }
        for(int i = 10; i < 354294; i++) {
            if(getPowerSum(i) == i)
                sum += i;
        }
        System.out.println(sum);
    }
}
