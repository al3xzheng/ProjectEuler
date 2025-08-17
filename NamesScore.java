/**
 * NamesScore
 */
import java.io.IOException;
import java.util.Arrays;
import java.nio.file.Files;
import java.nio.file.Paths;



public class NamesScore {

    static long nameSum (String name) {
        long sum = 0;
        for(int i = 0; i < name.length(); i++) {
            if(name.charAt(i) == 'A')
                sum += 1;
            else if(name.charAt(i) == 'B')
                sum += 2;
            else if(name.charAt(i) == 'C')
                sum += 3;
            else if(name.charAt(i) == 'D')
                sum += 4;        
            else if(name.charAt(i) == 'E')
                sum += 5;
            else if(name.charAt(i) == 'F')
                sum += 6;
            else if(name.charAt(i) == 'G')
                sum += 7;
            else if(name.charAt(i) == 'H')
                sum += 8;
            else if(name.charAt(i) == 'I')
                sum += 9;
            else if(name.charAt(i) == 'J')
                sum += 10;
            else if(name.charAt(i) == 'K')
                sum += 11;
            else if(name.charAt(i) == 'L')
                sum += 12;
            else if(name.charAt(i) == 'M')
                sum += 13;
            else if(name.charAt(i) == 'N')
                sum += 14;
            else if(name.charAt(i) == 'O')
                sum += 15;
            else if(name.charAt(i) == 'P')
                sum += 16;
            else if(name.charAt(i) == 'Q')
                sum += 17;
            else if(name.charAt(i) == 'R')
                sum += 18;
            else if(name.charAt(i) == 'S')
                sum += 19;
            else if(name.charAt(i) == 'T')
                sum += 20;
            else if(name.charAt(i) == 'U')
                sum += 21;
            else if(name.charAt(i) == 'V')
                sum += 22;
            else if(name.charAt(i) == 'W')
                sum += 23;
            else if(name.charAt(i) == 'X')
                sum += 24;
            else if(name.charAt(i) == 'Y')
                sum += 25;
            else if(name.charAt(i) == 'Z')
                sum += 26;
        }
        return sum;
    }

    public static void main(String[] args) throws IOException{
        
        String names = new String(Files.readAllBytes(Paths.get("C:/Users/Alex/Documents/ProblemSolving/Project Euler/resources/names.txt")));
        names = names.substring(1,names.length()-1);
        System.out.println(names);
        String [] arrNames = names.split("\",\"");
        Arrays.sort(arrNames);
        long score = 0;
        for(int i = 0; i < arrNames.length; i++) {
            // System.out.println(arrNames[i]);
            // if(arrNames[i].equals("COLIN"))
            //     System.out.println(nameSum(arrNames[i]) * i);

            // Had the rookie mistake where the index of the word was off by 1. Realized it's cuz the indices start counting at 0
            // programmatically but for the problem (in real life) counting starts at 1.
            score += (long)nameSum(arrNames[i]) * (i+1);
        }
        System.out.println(score);
    }
}