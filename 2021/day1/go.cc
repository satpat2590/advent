#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <deque>
#include <iostream>
#include <string>  

std::string STRING1 = "INCREASING";
std::string STRING2 = "DECREASING";


int main () {
    FILE *file = fopen("file.txt", "r");
    long size = ftell(file);
    char buffa[size]; 
    int count = 0; 

    int compare = 0; 
    while (fgets(buffa, 15, file)) {
        if (atoi(buffa) > compare) {
            printf("\n%d : %s\n", atoi(buffa), STRING1.c_str());
            count++;
        } else {
            //printf("\n%d : %s\n", atoi(buffa), STRING2.c_str());
        }
        compare = atoi(buffa);
    }

    printf("\n\nCount: %d\n", count);
}