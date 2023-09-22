#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 1000

void execute_commands(char *commands[][MAX_ARGS], int num_pipes) {
    int i;
    int fd[2];
    int input = STDIN_FILENO;

    for (i = 0; i < num_pipes; i++) {
        pipe(fd);
        if (fork() == 0) {
            dup2(input, STDIN_FILENO);
            if (i < num_pipes - 1) dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            
            int pid = fork();
            if (pid == 0) {
                execve(commands[i][0], commands[i], NULL);
                fprintf(stderr, "error: cannot execute %s\n", commands[i][0]);
                _exit(EXIT_FAILURE);
            } else if (pid < 0) {
                fprintf(stderr, "error: fatal\n");
                _exit(EXIT_FAILURE);
            } else {
                int status;
                waitpid(pid, &status, 0);
                if (status != 0) {
                    fprintf(stderr, "error: fatal\n");
                    _exit(EXIT_FAILURE);
                }
            }
            
            _exit(EXIT_SUCCESS);
        } else {
            wait(NULL);
            close(fd[1]);
            input = fd[0];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command1 [| command2] [; command3] [...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int i, j, num_pipes = 0;
    char *commands[MAX_ARGS][MAX_ARGS];

    for (i = 1, j = 0; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0) {
            commands[num_pipes][j] = NULL;
            num_pipes++;
            if (strcmp(argv[i], ";") == 0) {
                execute_commands(commands, num_pipes);
                num_pipes = 0;
            }
            j = 0;
        } else {
            commands[num_pipes][j++] = argv[i];
        }
    }

    commands[num_pipes][j] = NULL;
    num_pipes++;
    execute_commands(commands, num_pipes);

    return 0;
}