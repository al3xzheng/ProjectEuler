import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

/**
 * CodedTriangleNumbers
 */
public class CodedTriangleNumbers {

    static ArrayList<Integer> triangleNumbers = new ArrayList<Integer>();
    static int n = 1;

    static int nthTriangleNumber (int w) {
        return (w*(w+1)) / 2;
    }

    static boolean fillTriangleNumbers (int p) {
        n++;
        int t = nthTriangleNumber(n);
        triangleNumbers.add(t);
        while(p > t) {
            n++;
            t = nthTriangleNumber(n);
            triangleNumbers.add(t);
        }
        return p == t;
    }

    static int sumOfLetters (String str) {
        int sum = 0;
        for(int i = 0; i < str.length(); i++) {
            sum += str.charAt(i) - 64;
        }
        return sum;
    }

    static boolean binarySearch(int q, ArrayList<Integer> nums) {
        int low  = 0;
        int high = nums.size()-1;
        int middleVal;
        int middle;
        while(low < high) {
            middle = (high + low)/2;
            middleVal = nums.get(middle);
            if(middleVal == q)
                return true;
            if(middleVal > q)
                high = middle-1;
            else {
                low = middle + 1;
            }
        }
        return q == nums.get(low);
    }

    public static void main(String[] args) throws IOException {
        final long startTime = System.currentTimeMillis();
        String words = new String(Files.readAllBytes(Paths.get("C:/Users/Alex/Documents/ProblemSolving/Project Euler/resources/words.txt")));
        String [] array = words.substring(1,words.length() - 1).split("\",\"");
        int ans = 0;
        int p;
        triangleNumbers.add(1);
        for(String i: array) {
            p = sumOfLetters(i);
            if(p > triangleNumbers.get(triangleNumbers.size()-1)) {
                if(fillTriangleNumbers(p)) {
                    ans++;
                }
            }
            else if(binarySearch(p, triangleNumbers)) {
                ans++;
            }
        }
        System.out.println(ans);
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime));
    }
}