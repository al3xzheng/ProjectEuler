public class EvenFibonnaciNumbers {
    
    public static int fib (int a, int b, int sum) {
        if(b > 4000000)
            return sum;
        if((a+b) % 2 == 0)
            sum += a+b;
        return fib(b, a + b, sum);
    }
    public static void main(String[] args) {
        System.out.println(fib(0,1,0));
    }
}
