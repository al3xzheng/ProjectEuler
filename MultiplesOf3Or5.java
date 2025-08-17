/**
 * MultiplesOf3Or5
 */
public class MultiplesOf3Or5 {

    public static int getSum() {
        int sum = 0;
        for(int i = 3; i <= 999 ;i+=3) {
            sum+=i;
        }
        for(int j = 5; j < 1000;j+=5) {
            if(j%3 != 0)
                sum +=j;
        }
        return sum;
    }

    public static void main(String[] args) {

        System.out.println(getSum());
    }
}