import java.util.HashSet;
import java.util.Set;

// AS I SUSPECTED, I DIDN'T HAVE TO USE LONG, BUT WAS SCARED AND USED IT TO SAVE (PERSONAL) TIME, BUT LOSE TIME EFFICIENCY.

public class NonAbundantSums {
    static Set<Long> abundantNumbers = new HashSet<Long>();
    
    static boolean isAbundant (long N) {
        long sum = 1;
        for(long i = 2; i <= N/2; i++) {
            if(N%i == 0)
                sum +=i;
        }
        return sum > N;
    }

    static boolean isNonAbundantSum (long N) {
        for(long i : abundantNumbers) {
            if(N%i == 0 || abundantNumbers.contains((N-i)))
                return false;
        }
        return true;
    }

    static long sumNonAbundantSum (long max) {
        long sum = 0;
        for(long i = 1; i < max; i++) {
            if(isNonAbundantSum(i))
                sum += i;
            if(isAbundant(i))
                abundantNumbers.add(i);
        }
        return sum;
    }

    public static void main(String[] args) {
        // for(int i = 0; i< 31; i++) {
        //     if(isAbundant(i))
        //         System.out.println(i);
        // }
        System.out.println(sumNonAbundantSum(28123));
    }
}
