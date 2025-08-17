public class CircularPrimes {

    static boolean [] sieve (int N) {
        boolean [] primes = new boolean [N+1];
        for(int i = 1; i < N+1; i++) {
            primes[i] = true;
        }
        primes[1] = false;

        for(int i = 1; i *i < N + 1; i++) {
            if(primes[i]) {
                for(int j = i; i * j < N +1; j++) {
                    primes[i*j] = false;
                }
            }
        }
        return primes;
    }

    static int numDigits (int N) {
        int num = 0;
        while(N != 0) {
            num++;
            N /= 10;
        }
        return num;
    }

    // Accidentally found the sum of all circular primes under N=1000000
    public static void main(String[] args) {
        int sum = 0;
        int num;
        int n;
        int [] circularnumbers;
        boolean isCircular;
        int N = 1000000;
        boolean [] primes = sieve(N);
        for(int i = 2; i < N + 1; i ++) {
            if(primes[i]) {
                isCircular = true;
                num = numDigits(i)-1;
                circularnumbers = new int [num];
                n = i;
                for(int j = 0; j < num; j++) {
                    n= (n % (int)Math.pow(10, num)) * 10 + n/(int)Math.pow(10, num);
                    if(!primes[n]) {
                        isCircular = false;
                        break;
                    }
                    circularnumbers[j] = n;
                }
                if(isCircular) {
                    sum += 1;
                    for(int k = 0; k < num; k++) {
                        System.out.print(circularnumbers[k] + " ");
                        if(i != circularnumbers[k])
                            sum += 1; //circularnumbers[k] for total sum
                        primes[circularnumbers[k]] = false;
                    }
                    System.out.println();
                }
            }
        }
        System.out.println(sum);
    }
}
