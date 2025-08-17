public class SummationOfPrimes {

    static boolean isPrime(int N) {
        // redundant since no even numbers.
        if(N%2 == 0)
            return false;
        for(int i = 3; i <= Math.ceil(Math.sqrt(N)); i+=2) {
            if(N%i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        // Must use long, since exceeds maximum integer value. 
        // When an arithmetic operation exceeds Integer.MAX_VALUE, it wraps around due to overflow, which can lead to unexpected behavior or results.
        long sum = 2;
        int largest = 0;
        for(int i = 3; i < 2000000; i+=2) {
            if(isPrime(i)) {
                sum = sum + i;
                largest = i;
            }
        }
        System.out.println(largest);
        System.out.println(sum);

    }
}
