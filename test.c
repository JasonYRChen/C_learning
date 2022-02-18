#include <stdio.h>

typedef struct {
    int a;
    int b;
    int (*func)(int, int);
} function;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

void calculation(function *func)
{
    printf("result: %i\n", func->func(func->a, func->b));
}

int main()
{
    function func_a = {5, 3, add};
    function func_b = {5, 3, sub};

    calculation(&func_a);
    calculation(&func_b);

    return 0;
}

