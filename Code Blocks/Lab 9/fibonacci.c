#include <stdio.h>

int fibonacci_recursiv(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    return fibonacci_recursiv(n-2) + fibonacci_recursiv(n-1);
}

int fibonacci_iterativ(int n)
{
    int f0 = 0, f1 = 1, fib = 0, i;

    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    for(i = 1; i < n-1; i++)
    {
        fib = f0 + f1;
        f0 = f1;
        f1 = fib;
    }

    return fib;
}

int main()
{
    printf("Fibonacci recursiv: %d\n", fibonacci_recursiv(10));
    printf("Fibonacci iterativ: %d\n", fibonacci_iterativ(10));
}
