/* This is for practicing C code in textbook */

# include <stdio.h>
# include <stdlib.h>

int main()
{
    char card[3];
    do {
        int value;
        
        puts("Enter your card:");
        scanf("%2s", card);

        switch (card[0]) {
        case 'k':
        case 'q':
        case 'j':
        case 'a':
            if (card[1] != '\0')
                value = 0;
            else {
                value = 10;
                if (card[0] == 'a')
                    value++;
            }
            break;
        default:
            value = atoi(card);
            if (!(0 <= value && value <= 10))
                value = 0;
        }

        if (card[0] != 'X') {
            if (!((0 < value) && (value <= 11)))
                printf("Invalid card.\n");
            else
                printf("You got %i points\n", value);
        }
    } while (card[0] != 'X');

    return 0;
}

