# include <stdio.h>

int coordinate_check(float coord, float limit)
{
    if ((coord > limit) || (coord < -limit))
        return 0;
    else
        return 1;
}

int main()
{
    float longitude;
    float latitude;
    char info[80];
    int start = 0;
    int lines = 1;
    int error = 0;

    fprintf(stdout, "data=[");
    while (3 == scanf("%f,%f,%79[^\n]", &longitude, &latitude, info)) {
        int valid_long = coordinate_check(longitude, 180);
        int valid_lati = coordinate_check(latitude, 90);

        if (!valid_long || !valid_lati) {
            if (!error)
                error = 1;

            fprintf(stderr, "Line %i.", lines);
            if (!valid_long)
                fprintf(stderr, " longitude: %f", longitude);
            if (!valid_lati)
                fprintf(stderr, " latitude: %f", latitude);
            fprintf(stderr, "\n");
        } else {
            if (start)
                fprintf(stdout, ",\n");
            else {
                start = 1;
                fprintf(stdout, "\n");
            }
            fprintf(stdout, "{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
        }
        lines++;
    }
    printf("]");

    if (error)
        return 2;
    else
        return 0;
}

