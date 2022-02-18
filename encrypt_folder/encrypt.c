# include "header.h"

void encrypt(char *msg, int xor_num)
{
    while (*msg) {
        *msg = *msg ^ xor_num;
        msg++;
    }
}

