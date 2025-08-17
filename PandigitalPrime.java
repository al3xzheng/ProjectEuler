public class PandigitalPrime {

    static boolean isPandigital(int N) {
        int digits = (int)Math.log10(N) + 1;

        for(int i = 1; i <= digits; i++)
            if(!contains(N,i))
                return false;
        return true;
    }

    static boolean []  noZeroSieve (int N) {
        boolean [] sieve = new boolean [N+1];
        for(int i = 2; i < N + 1; i++) {
            sieve[i] = true;
        }

        for(int i = 2; i*i < N + 1; i++) {
            if(sieve[i]) {
                for(int j = i; j*i < N +1; j++) {
                    sieve[i*j] = false;
                }
            }
        }
        return sieve;
    }

    static boolean contains (int N, int c) {
        while(N != 0) {
            if(N%10 == c)
                return true;
            N/=10;
        }
        return false;
    }

    public static void main(String[] args) {
        boolean [] ans = noZeroSieve(999999999);

        for(int i = ans.length -1; i > 0; i--) {
            if(ans[i] && !contains(i, 0) && isPandigital(i)) {
                System.out.println(i);
                break;
            }
        }
    }
}
