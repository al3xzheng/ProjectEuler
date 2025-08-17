public class PowerDigitSum {
    public static void main(String[] args) {
        String number= "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
        int sum = 0;
        for (int i = 0; i < number.length(); i++) {
            sum += number.charAt(i) - '0';
        }
        System.out.println(sum);
    }
}

// Should've done it in python with no max value limits on integers, thus did not have to use string to hold value of 2^1000 and could've 
// computed it ourselves instead of WOlfram. Then use % and / to get last digits and summation (answer).
