public class NumberLetterCounts {

    static int getLength1(int a) {
        if(a == 1)
            return 3;
        if(a == 2)
            return 3;
        if(a == 3)
            return 5;
        if(a == 4)
            return 4;
        if(a == 5)
            return 4;
        if(a == 6)
            return 3;
        if(a == 7)
            return 5;
        if(a == 8)
            return 5;
        if(a == 9)
            return 4;
        if(a== 10)
            return 3;
        if(a == 11)
            return 6;
        if(a == 12)
            return 6;
        if(a == 13)
            return 8;
        if(a == 14)
            return 8;
        if(a == 15)
            return 7;
        if(a == 16)
            return 7;
        if(a == 17)
            return 9;
        if(a == 18)
            return 8;
        if(a == 19)
            return 8;
        return 0;
    }
    static int getLength2(int a) {
        if(a == 4) 
            return 5;
        if(a == 2) 
            return 6;
        if (a == 3)
            return 6;
        if (a == 5) 
            return 5;
        if (a ==6) 
            return 5;
        if (a ==7) 
            return 7; 
        if (a ==8) 
            return 6; 
        if (a ==9) 
            return 6;
        return 0;
    }

    public static void main(String[] args) {
        int sum = 0;
        int num;
        for(int i = 0; i <= 999; i++) {
            num = i;
            if(num > 99) {
                sum += getLength1(num/100) + 10;
                num %= 100;
                if(num == 0)
                    sum -= 3;
            }
            if(num < 20)
                sum += getLength1(num);
            else {
                sum += getLength2(num/10) + getLength1(num%10);
            }
        }
        //one thousand
        sum += 11;
        System.out.println(sum);
    }
}
