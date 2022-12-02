#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector> 
#include <deque> 


int checkMate(std::pair<int, int> match) {
    //match.second = 1 = lose = 
    //match.second = 2 = draw = 
    //match.second = 3 = win = 

    //1 = rock
    //2 = paper
    //3 = scissor

    //win = 6
    printf("\n%d\n%d\n\n", match.first, match.second);
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
    printf("\n%c %c\n", first, second);
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

    printf("\n%d %d\n", retFirst, retSecond);

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