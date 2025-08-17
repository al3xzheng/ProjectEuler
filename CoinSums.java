/**
 * CoinSums
 */
public class CoinSums {

    static int [] divisors = {200,100,50,20, 10, 5, 2, 1};

    static int getNumCoins (int N, int index) {
        if(N == 0)
            return 1;
        if(index >= divisors.length) 
            return 0;
        int sum = 0;
        for(int i = 0; i <= N/divisors[index]; i++) {
            sum += getNumCoins(N - divisors[index]*i, index+1);
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(getNumCoins(200, 0));
    }
}