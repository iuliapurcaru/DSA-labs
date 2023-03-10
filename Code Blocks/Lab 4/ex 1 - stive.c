#include <stdio.h>

int isEmpty(int top)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(int top, int size)
{
    if(top >= size-1)
        return 1;
    else
        return 0;
}

void push(int element, int stack[], int *top, int size)
{
    if(isFull(*top, size))
    {
        printf("Stiva este plina");
    }
    else if(*top == -1)
    {
        *top = 0;
        stack[0] = element;
    }
    else
    {
        stack[(*top) + 1] = element;
        (*top)++;
    }
}
void pop(int stack[], int *top, int *n)
{
    if(isEmpty(*top))
    {
        printf("Stiva este goala\n");
    }
    else
    {
        *n = stack[*top];
        (*top)--;
    }
}

int peek(int stack[], int top)
{
    return stack[top];
}

int main()
{
    int size = 6, top = -1, stack[size], popped, i;

    // crearea stivei

    for(i = 0; i < size; i++)
    {
        push(i, stack, &top, size);
        printf("Elementul top: %d\n", peek(stack, top));
    }
    push(i, stack, &top, size);
    printf("\n\n");

    // stergerea elementelor din stiva

    for(i = 0; top >= 0; i++)
    {
        pop(stack, &top, &popped);
        printf("Elementul popped: %d\n", popped);
    }
    pop(stack, &top, &popped);

}
