/**
 * LargestPalindromeProduct
 */
import java.util.ArrayList;
public class LargestPalindromeProduct {

    static boolean isProductOfTwo3DigitNumbers (int N) {
        for(int i = 999; i>=100;i--) {
            if(N%i == 0 && N/i >= 100 && N/i <= 999) {
                System.out.println(i);
                return true;
            }
        }
        return false;
    }
    
    static boolean isPalindrome(int K) {
        int k = 0;
        int form = K;
        while(form != 0) {
            k = k*10 + form%10;
            form /= 10;
        }
        return (k==K);
    }
    
    static ArrayList<Integer> palindromeNumbers (int n) {
        ArrayList<Integer> palindromes = new ArrayList<Integer>();
        for (int i = n; i >=100000;i--) {
            if(isPalindrome(i)) 
                palindromes.add(i);
        }
        return palindromes;
    }
    
    public static void main(String[] args) {
        ArrayList<Integer> palindromes = palindromeNumbers(997799);
        System.out.println(palindromes.size());
        for(int j = 0; j < palindromes.size();j++) {
            if(isProductOfTwo3DigitNumbers(palindromes.get(j)))
                System.out.println(palindromes.get(j));
        }
        System.out.println("hello");
    }
 }


