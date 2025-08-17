/**
 * LongestCollatzSequence
 */
import java.util.HashMap;
public class LongestCollatzSequence {

    static HashMap<Long, Long> collatzLengths = new HashMap<Long, Long>();

    static long collatzLength (long N) {
        long n = N;
        long length = 0;
        while(N != 1) {
            if(collatzLengths.containsKey(N)) {
                length+=collatzLengths.get(N);
                N = 1;
            }
            else {
                if(N%2== 0) 
                    N /= 2;
                else {
                    N = 3*N + 1;
                }
                length++;
            }
        }
        collatzLengths.put(n, length);
        return length;
    }

    public static void main(String[] args) {
        long chainLength = 0L;
        long currentLength;
        int startingNumber = 1;
        for(int i = 1; i < 1000000; i++) {
            currentLength = collatzLength(i);
            if(currentLength > chainLength) {
                chainLength = currentLength;
                startingNumber = i;
            }
            // System.out.println(chainLength);
        }
        System.out.println(startingNumber);
        System.out.println(chainLength);
    }
}