/* a dumb note */

# include <stdio.h>
# include <stdlib.h>

int main() {
    char number[3];

    puts("Enter a number: ");
    scanf("%10s", number);
    printf("Your call: %i", atoi(number));

    return 0;
}

