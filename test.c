# include <stdio.h>

void nav(int *lat, int *lon, int lat_incr, int lon_incr)
{
    *lat = *lat + lat_incr;
    *lon = *lon + lon_incr;
}

int main()
{
    int lat = 87;
    int lon = 65;

    printf("Original latitude: %i\n", lat);
    printf("Original lontitude: %i\n", lon);
    nav(&lat, &lon, -3, 6);
    printf("New latitude: %i\n", lat);
    printf("New lontitude: %i\n", lon);

    return 0;
}
