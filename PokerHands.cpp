# include <iostream>
# include <fstream>
# include <string.h>
# include <string>

int suitToInt (char a) {
    if(a == 'C')
        return 1;
    if(a == 'S')
        return 2;
    if(a == 'H')
        return 3;
    return 4;
}

int valToInt (char a) {
    if(int(a - '0') < 10)
        return a -  '2';
    if(a == 'T')
        return 8;
    if(a == 'J')
        return 9;
    if(a == 'Q')
        return 10;
    if(a == 'K')
        return 11;
    if(a == 'A')
        return 12;
    return -100;
}

void shiftBack (int (&array) [5]) {
    for(int i = 4; i>= 1; i--) {
        array[i] = array[i-1];
    }
}

void read (std::ifstream &file, int (&pattern) [5], int (&hand) [13], bool &flush) {

    int track = 0;
    bool prevPattern = false;

    // for(int i = 0;i<5;i++) {
    //     std::cout<<pattern[i]<<std::endl;
    // }

    for(int i = 12; i >= 0;i--) {
        if(i >= 4 && hand[i] == 1 && hand[i-1] == 1 && hand[i-2] == 1 && hand[i-3] == 1 && hand[i-4] == 1) {
            pattern[4] = i;
            pattern[0] = pattern[1] = pattern[2] = pattern[3] = -1;
            break;
        }
        
        else if(hand[i] > 1) {
            shiftBack(pattern);
            if(hand[i] == 2) {
                if(prevPattern) 
                    pattern[1] = i;
                else {
                    pattern[0] = i;
                    prevPattern = true;
                }
            }
            else {
                pattern[0] = i;
                if(hand[i] = 3)
                    prevPattern = true;
            }
            track++;
        }
        else if(hand[i] == 1) {
            pattern[track] = i;
            track++;
        }
    }
}

int calculate (int (&pattern) [5], int (&hand) [13], bool flush) {

    int score = 0;

    if(pattern[0] == -1 && flush)
        score = 9;
    else if(flush)
        return 6;
    else if(hand[pattern[0]] == 1)
        score = 1;
    else if(hand[pattern[0]] == 2 && hand[pattern[1]] == 2)
        score = 3;
    else if(hand[pattern[0]] == 2)
        score = 2;
    else if(hand[pattern[0]] == 3 && hand[pattern[1]] == 2)
        score = 7;
    else if(hand[pattern[0]] == 3)
        score = 4;
    else if(pattern[0] == -1)
        score = 5;
    else if(hand[pattern[0]] == 4)
        score = 8;

    return score;
}

int solution() {

    std::ifstream file;
    file.open("resources/poker.txt");

    int count = 0;

    std::string readFile [10] = {""};

    int prevSuit;

    int pattern1[5];
    int hand1[13];
    bool flush1;
    int score1 = 0;

    int pattern2[5];
    int hand2 [13];
    bool flush2;
    int score2 = 0;

    int index = 1;

    while(file >> readFile[0] >> readFile[1] >> readFile[2] >> readFile[3] >> readFile[4] >> readFile[5] >> readFile[6] >> readFile[7] >> readFile[8] >> readFile[9]) {

        prevSuit = -1;
        flush1 = true;
        flush2 = true;
        
        for(int i = 0;i < 13;i++) {
            hand1[i] = hand2[i] = 0;
            if(i < 5) {
                pattern1[i] = pattern2[i] = -1;
            }
        }

        for(int i = 0; i < 5; i++) {
            // std::cout<<card << "helel"<<std::endl;
            if(prevSuit > 0 && prevSuit != suitToInt(readFile[i][1]))
                flush1 = false;

            prevSuit = suitToInt(readFile[i][1]);
            hand1[valToInt(readFile[i][0])] += 1;
        }

        prevSuit = -1;
        
        for(int i = 5; i < 10; i++) {
            // std::cout<<card << "helel"<<std::endl;
            if(prevSuit > 0 && prevSuit != suitToInt(readFile[i][1]))
                flush2 = false;
            prevSuit = suitToInt(readFile[i][1]);
            hand2[valToInt(readFile[i][0])] += 1;
        }

        read(file, pattern1, hand1, flush1);
        read(file, pattern2, hand2, flush2);

        // for(int i = 0; i < 5;i++) {
        //     std::cout<<pattern1[i]<<std::endl;
        // }

        score1 = calculate(pattern1, hand1, flush1);
        score2 = calculate(pattern2, hand2, flush2);

        if(score1 == 0 || score2 == 0) {
            std::cout<<index<<std::endl;
        }

        if(score1 > score2)
            count++;
        else if(score1 == score2) {

            for(int i = 0 ; i < 5; i++) {
                if(pattern1[i] > pattern2[i]) {
                    count++;
                    break;
                }
                else if(pattern1[i] < pattern2[i]){
                    break;
                }
            }
        }
        index++;
    }

    return count;
}

int main() {
    std::cout<<solution();
    return 0;
}