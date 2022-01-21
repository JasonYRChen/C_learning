# include <stdio.h>

int main()
{
    char first_name[20];
    char last_name[20];
    int year;
    int month;
    int day;

    puts("Enter your name (first last):");
    scanf("%19s %19s", first_name, last_name);
    puts("Enter your year of birth (yyyy mm dd):");
    scanf("%i %i %i", &year, &month, &day);

    puts("Your profiles:");
    printf("Name: %s, %s\n", first_name, last_name);
    printf("Birthday: %i/%i/%i\n", year, month, day);

    return 0;
}

