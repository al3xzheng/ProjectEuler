/**
 * DigitCancellingFractions
 */
public class DigitCancellingFractions {

    public static void main(String[] args) {
        //non-trivial implies that the removed digits are not  rectilinear of each other, trivial implies the removed digits are rectilinear
        //on top of each other since the can just be trivially added or removed.

        //idea for each value 1-9, place them in the diagonal non trivial location (2, since two diagonals), and run through the digits 1-9 for
        //the 2 remainging non canceled out diagonals. Get values and divided and see if the non-canceled out digits equal, i.e., not the original
        //digit chosen to be canceled out.

        //problem, how can I make sure repeated solutions aren't repeated? hashset can work?
        // The problem is that it can't be if either num or den is in the hashset since, one number can be in 2 non-trivial solutions
        // => maybe hasmap (x,y) + (y,x), but there's probably a better solution for this with just some mathematical calculations.

        //maybe solutions can't be reapeated since fractions must be less than 1.

        //consider 0s after
        double product = 1.0;
        for(double i = 1; i <= 9; i++) {
            //cancelling out is from top-left to bottom-right
            for(double j = 1; j <=9; j++) {
                for(double k = i + 1; k <= 9; k++) {
                    if(((i*10 + j) / (k*10 + i) == j/k)) {
                        System.out.println((i*10 + j) + " " + (k*10 + i) + " " + j/k);
                        product *= j/k;
                    }
                }
            }
            //cancelling out is from top-right to bottom-left
            for(double j = 1; j <=i; j++) {
                for(double k = 1; k <= 9; k++) {
                    if(i!=j || (j == i && k > i)) {
                        if((j*10 + i) / (i*10 + k) == j/k) {
                            System.out.println((j*10 + i) + " " + (i*10 + k) + " " + j/k);
                            product *= j/k;
                        }
                    }
                }
            }
        }
        System.out.println(product);
    }
}