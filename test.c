# include <stdio.h>
# include <string.h>

int search_name(char *name, char *names, int row, int col)
{
    int i;
    for (i=0; i<row; i++) {
        char *address = names + i * col;
        if (strstr(address, name)) 
            return i;
    }
    return -1;
}

int main()
{
    char names[][10] = {"Jason", "Ian", "Steve", "Dora"};
    int track;
    char name[10];

    puts("What do you want to search:");
    scanf("%9s", name);
    track = search_name(name, names, 4, 10);
    if (track == -1)
        printf("Track not found.");
    else
        printf("On track %i", track);

    return 0;
}

