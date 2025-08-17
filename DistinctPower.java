import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

/**
 * DistinctPower
 */
public class DistinctPower {

    // sieve works
    static boolean [] sieve (int N) {
        boolean [] primes = new boolean [N+1];
        for(int i = 0; i < N +1; i++) {
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i * i < N + 1;i++) {
            if(primes[i]) {
                for(int j = i; j * i < N + 1; j++) {
                    primes[j*i] = false;
                }
            }
        }
        return primes;
    }

    static boolean lessThan100 (int a, int b) {
        while(b>1) {
            a *=a;
            if(a > 100)
                return false;
            b--;
        }
        return true;
    }

    public static void main(String[] args) {
        int N = 100;
        boolean [] primes = sieve(N);
        HashMap <Integer, Integer> pairs= new HashMap<Integer, Integer>();
        //can use a o(root(n)) function to get number of factors - 2 (1 and n) as well.
        int duplicates = 0;
        for(int a = 2; a <= 100; a++) {
            for(int b = 4; b<=100; b++) {
                if(!primes[b]) {
                    for(int f =2; f <= b/2; f++) {
                        if(b%f == 0 && lessThan100(a, f)) {
                            // if(!pairs.containsKey(a) || (pairs.containsKey(a) && pairs.get(a) != f)) {
                            // System.out.println("test");
                                // pairs.put(a,f);
                                // pairs.put(f,a);
                            System.out.println(a + " " + b + "    " + Math.pow(a,f) + " " + b/f);
                            duplicates++;
                            // }
                        }
                    }
                }
            }
        }
        System.out.println(99*99-duplicates);

        // HashSet<Integer> existing = new HashSet<Integer>();
        // int sum = 0;
        // for(int i = 2; i <= 100; i++) {
        //     for(int j = 2; j <= 100; j++) {
        //         if(!existing.contains((long)Math.pow(i,j))) {
        //             sum++;
        //             existing.add((long)Math.pow(i,j));
        //         }
        //     }
        // }
        // System.out.println(sum);
    }
}
