#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int SCORE = 0;

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(2);
}

int catch_signal(int sig, void (*func)(int))
{
    struct sigaction action;
    action.sa_handler = func;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void show_score()
{
    printf("\nThis is your score: %i\n", SCORE);
}

void times_up(int sig)
{
    printf("\n-----TIMES UP-----\n");
    raise(SIGINT);
}

void user_quit(int sig)
{
    show_score();
    exit(0);
}

int main()
{
    srand(time(0));
    char repeat[2];

    if (catch_signal(SIGINT, user_quit) == -1) 
        error("Cannot handle user interruption");
    if (catch_signal(SIGALRM, times_up) == -1)
        error("Cannot hangle alarm signal");

    while (1) {
        int a = random() % 11;
        int b = random() % 11;
        int ans;

        printf("%i x %i = ", a, b);
        alarm(5);
        scanf("%i", &ans);
        if (ans == a*b) {
            SCORE ++;
            printf("Excellent! You got one point and score %i\n", SCORE);
        } else
            printf("Ooops! Try again. You've got %i scores\n", SCORE);
    }


    return 0;
}

