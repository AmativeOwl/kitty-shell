#include <stdio.h>
#include <stdlib.h>

#define DELIM_NUM 15
#define LINE_NUM 4
#define NEWLINE printf("\n")

void printBoundary();
void printVerticalLines();
void printHorizontalLines();

int main(int argc, char* argv[]) {
    printBoundary();
    
    return 0; 
}

void printBoundary() {
    printHorizontalLines();
    printVerticalLines();

    printf("|     ^-^     |\n");
    printf("|    | _ |    |\n");
    printf("|   === ===   |\n");
    printf("|    w---w    |");

    printVerticalLines();
    printHorizontalLines();
    NEWLINE;
}

void printHorizontalLines() {
    for (int i=0; i<DELIM_NUM; i++) printf("-");
}

void printVerticalLines() {
    for (int i=0; i<LINE_NUM; i++) {
        NEWLINE;
        printf("|             |");
    }
    NEWLINE;
}