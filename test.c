#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "./error_folder/error.h"

int main()
{
    int tunnel[2];
    char url[100];
    if (pipe(tunnel) == -1)
        error("Create pipe error");

    char *msg[] = {"http://www.google.com", "http://www.apple.com"};

    pid_t pid = fork();

    if (pid == -1)
        error("Unseccessful fork");

    if (!pid) {
        close(tunnel[0]);
        dup2(tunnel[1], 1);
    } else {
        close(tunnel[1]);
        dup2(tunnel[0], 0);
    }

    for (int i=0; i<2; i++) {
        if (!pid) {
            printf("%s\n", msg[i]);
        } else {
            char command[105];
            fgets(url, 100, stdin);
            sprintf(command, "%s %s", "open", url);
            system(command);
        }
    }

    return 0;
}

