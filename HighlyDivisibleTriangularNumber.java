public class HighlyDivisibleTriangularNumber {

    static int getNumberOfFactors(int N) {
        int count = 1;
        if(N%2 == 0)
            count*=getMaxPowerOfPrimeFactor(N, 2)+1;
        if(isPrime(N)) 
            count*=2;
        // <= Math.ceil(Math.sqrt(N)) to see if number is prime, not to check all its prime factors!
        // We should go to < n/2 for general case
        // but since the number k will be greater than 36 (or n=?), we can shorten the complexity significantly with Math.ceil(Math.sqrt(N))
        for(int i = 3; i <= Math.ceil(Math.sqrt(N)); i+=2) {
            if(isPrime(i) && N%i == 0)
                count*=getMaxPowerOfPrimeFactor(N, i)+1;
        }
        return count;
    }

    static boolean isPrime(int N) {
        if(N%2 == 0)
            return false;
        for(int i = 3; i <= Math.ceil(Math.sqrt(N)); i+=2) {
            if(N%i == 0)
                return false;
        }
        return true;
    }

    static int getMaxPowerOfPrimeFactor (int N, int p) {
        int count = 0;
        while(N%p == 0) {
            N /=p;
            count++;
        }
        return count;
    }

    static int nthTriangleNumber (double n) {
        return (int)(((n+1))*(n/2));
    }

    public static void main(String[] args) {
        int NthTriangleNumber = 1;
        while(getNumberOfFactors(nthTriangleNumber(NthTriangleNumber)) <= 500) {
            NthTriangleNumber++;
        }
        System.out.println(NthTriangleNumber);
        System.out.println(nthTriangleNumber(NthTriangleNumber));
    }
}
