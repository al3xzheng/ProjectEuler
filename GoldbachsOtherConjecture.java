import java.util.ArrayList;

public class GoldbachsOtherConjecture {

    static ArrayList<Boolean> sieve = new ArrayList<Boolean>();

    static int digitalRoot(long N) {
        int dr = 0;
        while(N != 0) {
            dr += N% 10;
            N = N/10;
            if(N == 0 && dr > 9) {
                N  = dr;
                dr = 0;
            }
        }

        return dr;
    }

    static boolean isPerfectSquare (long N) {
        long l = N%10;
        if(l!= 1 && l!= 4 && l!= 5 && l!= 6 && l!= 9 && l!= 0)
            return false;
        if(digitalRoot(N) != 1 &&  digitalRoot(N) != 4 &&  digitalRoot(N) != 7 &&  digitalRoot(N) != 9)
            return false;
        long m = (long) Math.sqrt(N);
        return m*m == N;
        //babylonian method fails at large N.
    }
    
    static void mutableSieve () {
        int original_size = sieve.size();
        for(int i = original_size; i < original_size + 10000;i++) {
            sieve.add(true);
        }

        sieve.set(0, false);
        sieve.set(1, false);

        for(int i = 2; i*i < sieve.size(); i++) {
            if(sieve.get(i)) {
                for(int j = i; j * i < sieve.size(); j++ ) {
                    if(j*i >= original_size)
                        sieve.set(i*j, false);
                }
            }
        }
    }

    static int solution() {
        int n;
        boolean gb = false;
        for(n = 9; ; n+=2){
            if(n >= sieve.size())
                mutableSieve();
            if(!sieve.get(n)) {
                gb = false;
                for(int s = 2; s <= n- 2; s++) {
                    if(sieve.get(s) && (n - s) % 2 == 0 && isPerfectSquare((n - s)/2))
                        gb = true;
                }
                if(!gb)
                    return n;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(solution());
    }
}
