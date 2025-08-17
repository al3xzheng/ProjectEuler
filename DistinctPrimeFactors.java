import java.util.ArrayList;

public class DistinctPrimeFactors {

    static ArrayList <Boolean> sieve = new ArrayList <Boolean>();

    static void mutableSieve() {
        int original_size = sieve.size();
        for(int i = original_size; i < original_size + 100000; i++) {
            sieve.add(true);
        }

        sieve.set(0, false);
        sieve.set(1, false);

        for(int i  = 2; i * i < sieve.size(); i++) {
            if(sieve.get(i)) {
                for(int j = i; j * i < sieve.size(); j++) {
                    if(i*j >= original_size)
                        sieve.set(i*j, false);
                }
            }
        }
    }

    static boolean fourPrimeFactors (int i) {
        int factors = 0;
        for(int j = 2; j<= i/2;j++) {
            if(sieve.get(j) && i%j == 0)
                factors++;
        }
        return factors == 4;
    }

    static int solution() {
        for(int i = 18; ;i++) {
            if(i+3 >= sieve.size())
                mutableSieve();
            if(!sieve.get(i) && !sieve.get(i+1) && !sieve.get(i+2) && !sieve.get(i+3)) {
                // System.out.println(i);
                if(fourPrimeFactors(i) && fourPrimeFactors(i+1) && fourPrimeFactors(i+2) && fourPrimeFactors(i+3))
                    return i;
            }
        }
    }
    

    public static void main(String[] args) {
        System.out.println("sol: " + solution());
    }
}
