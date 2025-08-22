# Mini-Shell-in-C
My practice project for learning Operating Systems concepts
This is a simple command line shell written in the C programming language.
The purpose of this project is to practice operating system concepts like process creation and execution using system calls (fork, execvp, wait).
Features:
Runs basic Linux commands like ls, pwd, date, echo
Supports cd command to change directory
Supports exit command to quit the shell
Shows error if command is invalid
How to run:
Save the file as mini_shell.c
Open terminal in the same folder
Compile: gcc mini_shell.c -o mini_shell
Run: ./mini_shell
Example:
mini-shell> pwd
/home/ayush
mini-shell> ls
mini_shell.c README.txt
mini-shell> cd ..
mini-shell> pwd
/home
mini-shell> echo Hello
Hello
mini-shell> exit
Exiting shell...
What I learnt:
How fork creates new processes
How execvp runs commands
How parent process waits for child
Basic idea of how shells like bash work
Author: Ayush Kumar
B.Tech CSE, 2027 batch
