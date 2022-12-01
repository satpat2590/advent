#include <fstream> 
#include <stdio.h> 
#include <stdlib.h>
#include <iostream> 
#include <string.h>
#include <deque> 


int findMax(std::deque<int> &refDeq) {
    int maxVal = 0;
    int index; 
    for (int i = 0; i < refDeq.size(); i++) {
        if (refDeq[i] > maxVal) {
            maxVal = refDeq[i];
            index = i; 
        }
    }
    refDeq.erase(refDeq.begin() + index); 
    return maxVal; 
}

int main() { 
    FILE *file = fopen("file.txt", "r");
    long size; 
    size = ftell(file);
    char buf[size];
    int count; 
    if (file == NULL) {
        printf("\nError opening file...\n");
        return -1; 
    }

    int maxVal = 0;  
    int valHolder = 0; 
    std::deque<int> elfBane;
    while (fgets(buf, 15, file)) {
        if (!strcmp(buf, "\n")) {
            elfBane.push_back(valHolder);
            valHolder = 0;
        } else {
            valHolder += atoi(buf);
        }    
    }

    int x = findMax(elfBane);
    int y = findMax(elfBane);
    int z = findMax(elfBane);

    printf("\n\nGreedy, Fat Elf: %d\n\n", x);
    printf("\n\nSecond Elf: %d\n\n", y);
    printf("\n\nBest Elf: %d\n\n", z);

    int final_val = x + y + z;

    printf("\n\nCombined Calories: %d\n\n", final_val);
        

}




