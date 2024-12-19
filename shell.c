#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    pid_t child_pid;
    int status;

    while (1)
    {
        printf("#cisfun$ ");
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\n");
            break;  // Handle EOF (Ctrl+D)
        }

        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Error:");
            return 1;
        }

        if (child_pid == 0)
        {
            // Child process
            if (execve(command, (char *[]){command, NULL}, NULL) == -1)
            {
                perror("Error:");
                exit(1);
            }
        }
        else
        {
            // Parent process
            wait(&status);
        }
    }

    return 0;
}
