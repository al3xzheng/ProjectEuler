import java.util.ArrayList;
import java.util.HashSet;

/**
 * PentagonNumbers
 */
public class PentagonNumbers {

    static ArrayList <Integer> nums = new ArrayList<Integer>();
    // static int n;

    // static boolean funcOne (int nj, int nk, int ni) {
    //     return 3*Math.pow(nk, 2) - nk - 3*Math.pow(nj, 2) - nj == 3*Math.pow(ni, 2) - ni;
    // }

    // static int ni(int nj, int nk) {
    //     return pentagonalNumber(nk)-pentagonalNumber(nj);

    // }

    // static int ni0(int nj, int nk) {
    //     return pentagonalNumber(nk)+pentagonalNumber(nj);
    // }

    // static int getInitialDifference (int nj, int nk) {
    //     return (int) (3*Math.pow(nk, 2) - nk - 3*Math.pow(nj, 2) + nj)/2;
    // }

    // static int getPattern (int nj, int nk, int i) {
    //     return (int) (3*Math.pow(nk + i, 2) - nk - 3*Math.pow(nj + i, 2) + nj)/2;
    // }

    // static int pentagonalNumber (int N) {
    //     return (int) N*(3*N-1)/2;
    // }

    // static void generatePentagonalNumbers (int N) {
    //     while(n < N) {
    //         PentagonalNumbers.add(pentagonalNumber(++n));
    //     }
    // }

    static boolean isPentagonal (int N) {
        int o = 1;
        int q = 1;
        while(N > o) {
            o += 3*q + 1;
            q++;
        }
        return N == o;
    }

    static int solution () {
        int o = 1;
        int a;
        int b;
        for(int i = 1; ; i ++) {
            o += 3*i+1;
            // System.out.println(o);
            nums.add(o);
            for(int j = 0; j < nums.size()-1; j++) {
                b = nums.get(j);
                a = o - b;
                // System.out.println(o + " "+ b);
                if(isPentagonal(a) && isPentagonal((int)Math.abs(a - b))) {
                    System.out.println(a + " "+ b);
                    return b-a;
                }
            }
        }
    }

    public static void main(String[] args) {

        System.out.println(solution());

        // int nk;
        // int nj;
        // int count;
        // System.out.println(isPentagonal(ni(7, 8)));
        // for(int i = 1; i < 10;i++) {
        //     nj = 1;
        //     nk = nj + i;
        //     count = 1; //for loop here after
        //     while(count != 0) {
        //         // System.out.println(pentagonalNumber(nk));
        //         if(isPentagonal(ni(nj, nk)) && isPentagonal(ni0(nj, nk))) {
        //             System.out.println(nk + " " + nj + " " + i);
        //             // System.out.println(pentagonalNumber(nk)-pentagonalNumber(nj));
        //             count--;
        //         }
        //         nj++;
        //         nk++;
        //     }
        //     // System.out.println("\n");
        
                    
    }
}