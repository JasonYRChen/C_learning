# include <stdio.h>

int main()
{
    float longitude;
    float latitude;
    char info[80];
    int start = 0;

    puts("data=[");
    while (3 == scanf("%f,%f,%79[^\n]", &longitude, &latitude, info)) {
        if (start)
            printf(",\n");
        else
            start = 1;
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n]");

    return 0;
}

