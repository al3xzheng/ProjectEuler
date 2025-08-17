public class CountingSundays {
    public static void main(String[] args) {
        int numFirstSundays = 0;
        int day = 1;
        int counter = 1;
        // counter is the month we are on (mod 12 to get exact month)
        // day is the number of days passed/cumulated in previous months (or previous counters)
        while(counter <= 1200) {
            // System.out.println(day);
            if(day%7==6) {
                numFirstSundays++;
                // System.out.println(counter);
            }
            if(counter%12 == 1)
                day += 31;
            else if(counter%12 == 2){
                if((1 + counter/12)%4 == 0)
                    day += 29;
                else {
                    day += 28;
                }
            }
            else if(counter%12 == 3) 
                day += 31;
            
            else if(counter%12 == 4) 
                day += 30;
            
            else if(counter%12 == 5) 
                day += 31;
            
            else if(counter%12 == 6) 
                day +=30;
            
            else if(counter%12 == 7) 
                day +=31;
            
            else if(counter%12 == 8) 
                day +=31;
            
            else if(counter%12 == 9) 
                day +=30;
            
            else if(counter%12 == 10) 
                day +=31;
            
            else if(counter%12 == 11) 
                day +=30;
            
            else if(counter%12 == 0) 
                day +=31;
            
            counter++;
        }
        // System.out.println(day);
        System.out.println(numFirstSundays);
    }
}
