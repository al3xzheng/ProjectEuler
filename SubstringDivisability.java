import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashSet;

public class SubstringDivisability {
    /**
     * InnerSubstringDivisability
     */
    
    static boolean isPandigital (int N) {
        HashSet<Integer> nums = new HashSet<Integer>();
        while(N!=0) {
            if(nums.contains(N%10))
                return false;
            nums.add(N%10);
            N/=10;
        }
        return true;
    }

    static int firstTwo (int N, int index) {
        return N / (int) Math.pow(10, 6-index);
    }

    static long getFinal (long N) {
        HashSet<Long> nums = new HashSet<Long>();
        for(long i = 0 ; i <=9;i++) {
            nums.add(i);
        }
        long c = N;
        while(c !=0) {
            if(nums.contains(c%10))
                nums.remove(c%10);
            c /= 10;
        }
        if(nums.size() > 1)
            return 0;
        for (long i : nums) {
            return i * 1000000000 + N;
        }
        return 0;
    }

    public static void main(String[] args) {
        final long start1 = System.currentTimeMillis();
        ArrayList<Integer> array1 = new ArrayList<Integer>();
        ArrayList<Integer> array2 = new ArrayList<Integer>();
        int [] divisors = {2,3,5,7,11};
        int [] start = {12, 12, 15, 14, 132};
        int index = 4;
        for(int i = 17; i <= 987; i +=17) {
            if(isPandigital(i))
                array1.add(i);
        }
        for(int i = 13; i <= 987; i+=13) {
            if(isPandigital(i)) {
                for(int j = 0; j < array1.size() - 1; j++) {
                    if(i%100 == array1.get(j)/10)
                        array2.add(i*10 + array1.get(j)%10);
                }
            }
        }
        while(index >= 0) {
            if(index % 2 == 1) {
                array2.clear();
                for(int i = start[index]; i <= 987; i+=divisors[index]) {
                    if(isPandigital(i)) {
                        for(int j = 0; j < array1.size() - 1; j++) {
                            if(i%100 == firstTwo(array1.get(j), index)) {
                                array2.add(i*((int)Math.pow(10, 6-index)) + array1.get(j)%((int)Math.pow(10, 6-index)));
                                // System.out.println(i*10 + array1.get(j)%10);
                            }
                        }
                    }
                }
            }
            else {
                array1.clear();
                for(int i = start[index]; i <= 987; i+=divisors[index]) {
                    if(isPandigital(i)) {
                        for(int j = 0; j < array2.size() - 1; j++) {
                            if(i%100 == firstTwo(array2.get(j), index)) {
                                array1.add(i*((int)Math.pow(10, 6-index)) + array2.get(j)%((int)Math.pow(10, 6-index)));
                                // System.out.println(i*10 + array2.get(j)%10);
                            }
                        }
                    }
                }
            }
            index--;
        }
        long ans = 0;
        for (int i = 0; i < array1.size(); i++) {
            if(isPandigital(array1.get(i))) {
                ans += getFinal(array1.get(i));
                System.out.println(getFinal(array1.get(i)));
            }
        }
        System.out.println("\n" + ans);

        final long end = System.currentTimeMillis();
        System.out.print(end-start1);
    }
}
