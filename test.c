#include <stdio.h>
#include "encrypt_folder/header.h"

int main()
{
    char msg[100];
    int code;

    printf("Enter the message to encrypt: ");
    scanf("%99[^\n]", msg);
    printf("Enter the encrypt code: ");
    scanf("%i", &code);

    printf("Original message : %s\n", msg);
    encrypt(msg, code);
    printf("Encrypted message: %s\n", msg);
    descrypt(msg, code);
    printf("Recovered message: %s\n", msg);

    return 0;
}

