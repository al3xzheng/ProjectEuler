import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * MaximumPathSum2
 */
public class MaximumPathSum2 {

    public static void main(String[] args) throws IOException {
        // read text file and convert store as string
        String numbers = new String(Files.readAllBytes(Paths.get("C:/Users/Alex/Documents/ProblemSolving/Project Euler/resources/triangle.txt")));
        // System.out.println(numbers);

        //use gauss's Summation to get size
        int [] triangle = new int[5050];
        //populate the array representing the triangle with the existing numbers
        for(int i = 0; i < 5050; i++) {
            triangle[i] = Integer.parseInt(numbers.substring(i*3, i*3 +2));
        }
        // can't use left child = 2i & right child = 2i + 1 here like binary tree.

        //left child = i + row length, right child = i + row length + 1
        int count = 1; //row length
        int start = 0;
        for(int i = 0; i < triangle.length; i++) {
            if(i == start + count) {
                start = i;
                count++;
            }
            if(i + count + 1 < triangle.length) {
                // no need to compare, since first one
                if(i == start) {
                    triangle[i + count] += triangle[i];
                }
                // has to compare (option 1)
                else if(triangle[i] > triangle[i-1])
                    triangle[i + count] += triangle[i];
                // (option 2)
                else {
                    triangle[i + count] += triangle[i-1];
                }
                // end number has to compare and has to be added to the last number of the next row as well. Here adds it to the last number of next row.
                if(i == start +count -1)
                    triangle[i + count + 1] += triangle[i]; 
            }
        }
        int max = 0;
        for(int i = 5049; i >= 4950; i--) {
            if(triangle[i] > max)
                max = triangle[i];
        }
        System.out.println(max);
    }
}