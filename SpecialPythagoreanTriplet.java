/**
 * SpecialPythagoreanTriplet
 */
public class SpecialPythagoreanTriplet {

    static boolean isSquare(int a) {
        return (int)(Math.sqrt(a)) == Math.sqrt(a);
    }

    public static void main(String[] args) {
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000;j++) {
                int csquared = i*i + j*j;
                if(isSquare(csquared) && (i + j + Math.sqrt(csquared)) == 1000)
                    System.out.println("i: " + i + " j: " + j);
            }
        }
    }
}