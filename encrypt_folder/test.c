#include <stdio.h>
#include "header.h"

int main()
{
    char msg[] = "This is a msg.";
    int code = 15;

    printf("Origianl msg: %s\n", msg);
    encrypt(msg, code);
    printf("Encrypt msg : %s\n", msg);
    descrypt(msg, code);
    printf("Descrypt msg: %s\n", msg);

    return 0;
}

