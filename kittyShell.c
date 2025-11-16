#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT 1000
#define MAX_NAME_LEN 10
#define DELIM " \t\a\n"

char* getShellName(int* option);
char* selectShellName();
bool checkExit(char* input);
char** parseInput(char* input);
int runCommandInput(char** parsedInput);

char* getShellName(int* option) {
    switch (*option) {
        case 1: return "kitty";
        case 2: return "cat";
        case 3: return "meow";
        default: return "kitty";
    }
}

char* selectShellName() {
    enum { KITTY, CAT, MEOW, NAME_COUNT };
    char* shellName[NAME_COUNT] = { "KITTY" , "CAT", "MEOW" };

    printf("Please choose from the following shell names: \n");

    for (int i=KITTY; i<NAME_COUNT; i++) {
        printf("%d: %s\n", (i+1), shellName[i]);
    }

    int choice; 
    char input[MAX_NAME_LEN];
    do {
        printf("Enter option: ");

        /* use fgets to retrieve first 99 characters (+ \0) from stdin initially */
        if (fgets(input, sizeof(input), stdin)) {
            // sscanf: store and format input string as integers in variable choice 
            // should this fail, choice = -1 to continually reprompt
            if (sscanf(input, "%d", &choice) != 1) choice = -1;
        }

        /* check if input length > fgets size by failing strchr(input, '\n'), which
        retrieves remaining characters in stdin buffer. If first occurrence of character
        in input is NOT newline, flush the characters in while loop */
        if (!strchr(input, '\n')) {
            int ch; 
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (choice <= KITTY || choice > NAME_COUNT);

    char* name = getShellName(&choice);
    return name; 
}

bool checkExit(char* input) {
    if (strcmp(input, "bye") == 0) {
        printf("Bye for now!\n");
        return 1; 
    }

    return 0; 
}

char** parseInput(char* input) {
    char** tokens = malloc(sizeof(char*) * MAX_INPUT);
    char* token; 
    int idx = 0; 

    if (!tokens) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, DELIM);
    while (token != NULL) {
        tokens[idx++] = token; 
        
        if (idx >= MAX_INPUT) {
            tokens = realloc(tokens, MAX_INPUT * 2 * sizeof(char*));
            if (!tokens) {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIM);
    }
    tokens[idx] = NULL;

    return tokens;
}

int runCommandInput(char** parsedInput) {
    pid_t pid = fork();

    /* child process where it executes its own program */
    if (pid == 0) {
        execvp(parsedInput[0], parsedInput);
        perror("If you've reached here, we couldn't execute this program");
        exit(EXIT_FAILURE);
    } 
    /* parent process where it waits for the child process to complete */
    else if (pid > 0) { 
        int status; 
        waitpid(pid, &status, 0);
    } else {
        perror("fork failed");
    }

    return 1; 
}

int main(int argc, char* argv[]) {
    char input[MAX_INPUT];
    
    system("clear");

    char* kittyShellName = selectShellName();

    system("ksHelp");

    while (1) {
        printf("%s> ", kittyShellName);
        fflush(stdout); // flush output stream immediately

        if (!fgets(input, MAX_INPUT, stdin)) {
            perror("fgets failed");
            continue;
        }

        /* null-terminate string by strcspn: retrieving length of 
        input string up until newline character is encountered */
        input[strcspn(input, "\n")] = '\0';

        if (checkExit(input)) break;

        /* when iterating over parsedInput, strlen(*parsedInput) will
        only return the length of the first string it points to; that is, 
        dereferencing parsedInput will only point to the first string */
        char** parsedInput = parseInput(input);
        // for (int i=0; parsedInput[i] != NULL; i++) {
        //     printf("%s \n", parsedInput[i]);
        // }
        runCommandInput(parsedInput);
    }

    return 0; 
}