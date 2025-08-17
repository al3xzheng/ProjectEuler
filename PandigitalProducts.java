import java.util.HashSet;

public class PandigitalProducts {

    static boolean isPandigital (int a, int b, int product) {
        HashSet <Integer> digits = new HashSet <Integer> ();
        int dig;
        while(product != 0) {
            dig = product%10;
            // System.out.println(dig);
            if(dig == 0 || digits.contains((dig)))
                return false;
            digits.add(dig);
            product /= 10;
            if(product == 0) {
                if(a != 0) {
                    product = a;
                    a = 0;
                }
                else {
                    product = b;
                    b = 0;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        HashSet <Integer> pandigitalproducts = new HashSet <Integer> ();
        int sum = 0;
        int product = 0;
        int b;
        for(int a = 1; a <= 4; a++) {
            b = 5-a;
            for(int i = (int) Math.pow(10, a-1); i < (int) Math.pow(10, a); i++) {
                for(int j = (int) Math.pow(10, b-1); j < (int) Math.pow(10, b); j++) {
                    product = i*j;
                    if(isPandigital(i, j, product) && !pandigitalproducts.contains(product)) {
                        pandigitalproducts.add(product);
                        System.out.println(i + " " + j + " " + product);
                        sum += product;
                    }
                }
            }
        }

        System.out.println(sum);

        // System.out.println(isPandigital(39, 186, 7254));

    }
}
