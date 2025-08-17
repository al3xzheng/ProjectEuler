import java.util.HashSet;

/**
 * QuadraticPrimes
 */
public class QuadraticPrimes {

    static boolean [] sieve (int N) {
        boolean [] primes = new boolean [N+1];
        for(int i = 0; i < N+1; i++) {
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;
        //sieve
        for(int i = 2; i * i < N + 1;i++) {
            if(primes[i]) {
                for(int j = i; i* j < N + 1;j++) {
                    primes[i*j] = false;
                }
            }
        }
        return primes;
    }
    
    static boolean isPrime (int N) {
        if(N%2 == 0 || N < 0)
            return false;
        for(int i = 3; i <= Math.sqrt(N); i+=2) {
            if(N%i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        
        HashSet <Integer> storedPrimes = new HashSet <Integer> ();
        int answer = 0;
        int N = 1000;
        boolean [] primes = sieve(N);
        int length = 0;
        int max = 0;
        int value;
        for (int i = -1000; i < N+1;i++) {
            if((i < 0 && primes[-i]) || (i>0 && primes[i])) {
                for(int j = -999; j < 1000; j++) {
                    length = 0;
                    value = (int)(Math.pow(length, 2)) + j* length + i;
                    while(storedPrimes.contains(value) || isPrime(value)) {
                        if(!storedPrimes.contains(value))
                            storedPrimes.add(value);
                        length++;
                        value = (int)(Math.pow(length, 2)) + j* length + i;
                    }
                    if(length > max) {
                        max = length;
                        answer = i*j;
                    }
                }
            }
            // System.out.println(i);
        }
        // length = 0;
        // value = (int)(Math.pow(length, 2)) + -999* length + 61;
        // while(storedPrimes.contains(value) || isPrime(value)) {
        //     if(!storedPrimes.contains(value))
        //         storedPrimes.add(value);
        //     length++;
        //     // System.out.println(value);
        //     System.out.println(value);
        //     value = (int)(Math.pow(length, 2)) + -999* length + 61;
        // }
        // pri
        System.out.println(answer);
    }

}

