import java.util.HashMap;

public class AmicableNumbers {
    static HashMap <Integer, Integer> pairs= new HashMap <Integer, Integer> ();

    static int getSumOfFactors (int N) {
        int sum = 0;
        if(N>1)
            sum = 1;
        for(int i = 2; i <= N/2; i++) {
            if(N%i ==0)
                sum +=i;
        }
        return sum;
    }

    static int getAmicablePairsSum (int N) {
        int sum = 0;
        int numFactors = getSumOfFactors(N);
        if(pairs.containsKey(numFactors) && pairs.get(numFactors) == N)
            sum+= N + numFactors;
        else {
            pairs.put(N, numFactors);
        }
        return sum;
    }

    public static void main(String[] args) {
        int sum = 0;
        for (int i = 1; i <= 10000; i++) {
            sum += getAmicablePairsSum(i);
        }
        System.out.println(sum);
        // System.out.println(getSumOfFactors(1));
    }
}
