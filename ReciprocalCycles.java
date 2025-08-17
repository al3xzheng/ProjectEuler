import java.util.HashMap;

public class ReciprocalCycles {

    static int getRecurringCycleLength (int n) { // n from >=2
        // Used the fact that if the divisor becomes the same, the cycle must be repeating as then the exact prior sequence would follow again.
        HashMap<Integer, Integer> divisorLocation = new HashMap <Integer, Integer> ();
        int divisor = 10;
        int index = 0;
        while(divisor != 0) {
            if(divisorLocation.containsKey(divisor))
                return index - divisorLocation.get(divisor);
            divisorLocation.put(divisor, index);
            divisor = (divisor%n) *10;
            index++;
        }
        return 0;
    }

    public static void main(String[] args) {
        final long startTime = System.currentTimeMillis();
        // System.out.println(getRecurringCycleLength(11));
        int d = 0;
        int length;
        int max = 0;
        for(int i = 2; i < 1000; i++) {
            length = getRecurringCycleLength(i);
            if(length > max) {
                max = length;
                d = i;
            }
        }
        System.out.println(d);
        System.out.println(max);
        System.out.println(System.currentTimeMillis()- startTime);
    }
}
