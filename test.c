#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    struct island *prev;
    struct island *next;
    char *name;
} island;

island* add_island(char* name)
{
    island* new = malloc(sizeof(island));
    new->prev = NULL;
    new->next = NULL;
    new->name = strdup(name);

    return new;
}

int main(int argc, char *argv[])
{
    char island_name[80];
    FILE *input = fopen(argv[1], "r");
    island head = {NULL, NULL, "HEAD"};
    island *temp = &head;

    while (fscanf(input, "%[^\n]\n", island_name) == 1) {
        temp->next = add_island(island_name);
        temp->next->prev = temp;
        temp = temp->next;
    }
    fclose(input);

    for (temp=&head; temp; temp=temp->next) { 
        printf("name: %s", temp->name);
        if (temp->prev)
            printf(", prev: %s", temp->prev->name);
        if (temp->next)
            printf(", next: %s", temp->next->name);
        printf("\n");
    }

    temp = head.next;
    island* temp2;
    while (temp) {
        free(temp->name);
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
 
    return 0;
}

