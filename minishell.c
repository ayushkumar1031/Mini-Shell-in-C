/*
  Mini-Shell in C
 Author: Ayush Kumar
  Description:
   A simple shell program that can run Linux commands
  using system calls (fork, execvp, wait).
   Built-in commands: cd, exit
 */

#include <stdio.h>      // standard I/O
#include <stdlib.h>     // standard library
#include <string.h>     // string functions
#include <unistd.h>     // fork(), execvp(), chdir()
#include <sys/types.h>  // pid_t type
#include <sys/wait.h>   // wait()

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];
    pid_t pid;
    int status;

    printf("Welcome to Mini-Shell! Type 'exit' to quit.\n");

    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break; // Ctrl+D pressed
        }

        // remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) {
            continue; // empty input, show prompt again
        }

        // exit command
        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // tokenize input into args
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARG_SIZE - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        // built-in cd command
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "mini-shell: expected argument to \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("mini-shell");
                }
            }
            continue;
        }

        // fork and execute other commands
        pid = fork();
        if (pid == 0) {
            // child process
            if (execvp(args[0], args) == -1) {
                perror("mini-shell");
            }
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // parent process waits for child
            wait(&status);
        } else {
            perror("fork failed");
        }
    }

    return 0;
}
