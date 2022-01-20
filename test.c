# include <stdio.h>

int counter(char *msg)
{
    int count = 0;

    while (*msg != '\0') {
        count++;
        msg++;
    }
    return count;
}

int main()
{
    char msg[6]; 
    int count;

    do {
        puts("Enter:");
        scanf("%5s", msg);
        if (!(msg[0] == 'X' && msg[1] == '\0')) {
            count = counter(msg);
            printf("Your message: %s\n", msg);
            printf("size: %i\n", count);
            printf("Hidden message: %s\n", msg + count + 1);
        } else
            printf("Bye bye");
    } while (!(msg[0] == 'X' && msg[1] == '\0'));

    return 0;
}

