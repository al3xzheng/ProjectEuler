/**
 * ChampernownesConstant
 */
public class ChampernownesConstant {

    // static int Nthdigit (int N) {
    //     int x = 9;
    //     N -= 9;
    //     int n = 2;
    //     while(N > n*Math.pow(10, n)) {
    //         N -= n*Math.pow(10, n);
    //         // x += n*Math.pow(10, n);
    //         n++;
    //     }
    //     int y;
    //     if(N%2 == 0) {
    //         y = 10*N / (int)(n*Math.pow(10, n-1))
    //     }
    //     int y = 10*N / (int)(n*Math.pow(10, n-1));

    // }

    static int getnthDigit (int N, int n) {
        int ans = N%10;
        while( n > 0) {
            N /= 10;
            ans = N%10;
            n--;
        }
        return ans;
    }

    public static void main(String[] args) {
        int digit = 0;
        int exp = 0;
        int ans = 1;
        for(int i = 1; i <= 1000000; i++) {
            digit += (int)Math.log10(i) + 1;
            // System.out.println(digit);
            if(digit >= (int)Math.pow(10, exp)){
                ans *= getnthDigit(i, (digit - (int)Math.pow(10, exp)));
                exp++;
            }
        }
        System.out.println(ans);
    }
}