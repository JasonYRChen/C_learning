# include <stdio.h>
# include <string.h>

void reverse(char *word, char *reversed)
{
    int end = strlen(word);
    int i;

    for (i=0; i<end; i++) {
        reversed[i] = word[end - 1 - i];
    }
}

void reverse_in_place(char *word)
{
    int end = strlen(word);
    int i;
    int mid;
    
    if ((float)end / 2 > end / 2)
        mid = end / 2 + 1;
    else
        mid = end / 2;

    for (i=0; i<mid; i++) {
        char temp = word[i];
        word[i] = word[end - 1 - i];
        word[end - 1 - i] = temp;
    }
}

int main()
{
    char word[10];
    char reversed[10];

    puts("enter a word:");
    scanf("%9s", word);
    reverse(word, reversed);
    reverse_in_place(word);
    printf("Reversed with copied: %s\n", reversed);
    printf("Reversed in place: %s\n", word);

    return 0;
}

