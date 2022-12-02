#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector> 
#include <deque> 


/*
--- Part Two ---
The Elf finishes helping with the tent and sneaks back over to you. 
"Anyway, the second column says how the round needs to end: 
X means you need to lose, 
Y means you need to end the round in a draw, and 
Z means you need to win. 
Good luck!"

The total score is still calculated in the same way, but now you need to figure out what shape to choose so the round ends as indicated. 
The example above now goes like this:

In the first round, your opponent will choose Rock (A), and you need the round to end in a draw (Y), so you also choose Rock. 
This gives you a score of 1 + 3 = 4.

In the second round, your opponent will choose Paper (B), and you choose Rock so you lose (X) with a score of 1 + 0 = 1.

In the third round, you will defeat your opponent's Scissors with Rock for a score of 1 + 6 = 7.

Now that you're correctly decrypting the ultra top secret strategy guide, you would get a total score of 12.

Following the Elf's instructions for the second column, 
what would your total score be if everything goes exactly according to your strategy guide?
*/


int checkMate(std::pair<int, int> match) {
    switch(match.first) {
        case 1:
            switch(match.second) {
                case 1: //lose
                    return 3 + 0;
                
                case 2: //draw
                    return 1 + 3;
                
                case 3: //win
                    return 2 + 6;
            }
        case 2:
            switch (match.second) {
                case 1:
                    return 1 + 0;

                case 2:
                    return 2 + 3;

                case 3:
                    return 3 + 6;
            }
        case 3:
            switch (match.second) {
                case 1:
                    return 2 + 0;

                case 2:
                    return 3 + 3;

                case 3:
                    return 1 + 6;
            }
    }
    return -1; 
}



std::pair<int, int> checkBoth(char first, char second) {
    int retFirst = 0;
    int retSecond = 0;
    if (first == 'A') 
        retFirst = 1; 
    
    if (first == 'B') 
        retFirst = 2;

    if (first == 'C') 
        retFirst = 3;
    
    if (second == 'X')
        retSecond = 1;

    if (second == 'Y')
        retSecond = 2;
    
    if (second == 'Z')
        retSecond = 3; 

    return std::make_pair(retFirst, retSecond);
}


int main() {
    FILE *file = fopen("file.txt", "r");
    long size = ftell(file);
    char buffer[size];
    int outcome = 0;
    std::pair<int, int> holda; 
    while (fgets(buffer, 10, file)) {
        holda = checkBoth(buffer[0], buffer[2]);
        outcome += checkMate(holda);
    }
    printf("\n%d\n", outcome);
}
