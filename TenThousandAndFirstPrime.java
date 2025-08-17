import java.util.ArrayList;

/**
 * TenThousandAndFirstPrime
 */
public class TenThousandAndFirstPrime {

    static boolean isPrime (int N) {
        if(N%2 == 0)
            return false;
        for(int i = 3; i <= (int)Math.ceil(Math.sqrt(N));i+=2 ) {
            if(N%i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        ArrayList <Integer> primes = new ArrayList<Integer>();
        primes.add(2);
        for(int i = 3; primes.size() < 10001; i+=2) {
            if(isPrime(i))
                primes.add(i);
        }
        System.out.println(primes.get(primes.size()-1));
    }
}