#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_QUOTES 6

char** quoteBank();
void randomQuote(char** quotes);

int main(int argc, char* argv[]) {
    srand(time(NULL)); // prevents re-calling of same random index
    char** quotes = quoteBank();
    randomQuote(quotes);

    return 0; 
}

// must make static as array is removed from stack once function ends
char** quoteBank() {
    static char* quotes[NUM_OF_QUOTES] = {
        "If it fits, I sits!",
        "Home is where my cat is...",
        "Have a pawsome day today!",
        "Are you feline good today?",
        "Time spent with cats is never wasted!",
        "You came, you purred, you conquered!"
    };

    return quotes;
}

void randomQuote(char** quotes) {
    int randomIdx = rand() % NUM_OF_QUOTES;
    printf("%s\n", quotes[randomIdx]);
}