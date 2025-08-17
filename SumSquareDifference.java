public class SumSquareDifference {

    static int sumofSquares(int N, int exponent) {
        if(N==0)
            return 0;
        int sum = 0;
        for(int i=N; i>=1;i--) {
            if(i%2 == 1)
                sum += i*i;
        }
        return sum*(int)Math.pow(2, 2*exponent) + sumofSquares(N/2, exponent + 1);
    }

    static int SquareOfSums(double N) {
        return (int)Math.pow((N+1)*N/2,2);
    }

    public static void main(String[] args) {
        System.out.println(sumofSquares(100, 0));
        System.out.println(sumofSquares(100, 0)-SquareOfSums(100));
    }
}
