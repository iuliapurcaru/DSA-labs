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

void push_2(int element, int stack[], int *top2, int top1, int size)
{
    if(isFull(*top2, 2*size))
    {
        printf("Stiva este plina");
    }
    else if(*top2 == -1)
    {
        *top2 = top1 + 1;
        stack[*top2] = element;
    }
    else
    {
        stack[(*top2) + 1] = element;
        (*top2)++;
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

void pop_2(int stack[], int *top2, int top1, int *n)
{
    if(*top2 == top1)
    {
        *top2 = -1;
    }
    if(isEmpty(*top2))
    {
        printf("Stiva este goala\n");
    }
    else
    {
        *n = stack[*top2];
        (*top2)--;
    }
}

int main()
{

    int size = 5, top_1 = -1, top_2 = -1, stack[2*size], i, popped;

    // crearea stivei 1

    for(i = 0; i < size; i++)
    {
        push(i, stack, &top_1, size);
    }

    // crearea stivei 2

    for( ; i < 2*size; i++)
    {
        push_2(i, stack, &top_2, top_1, size);
    }

    // afisarea stivelor

    printf("Stiva 1:\n");
    for(i = top_1; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    printf("\n");

    printf("Stiva 2:\n");
    for(i = top_2; i >= top_1 + 1; i--)
    {
        printf("%d\n", stack[i]);
    }

    printf("Vectorul: ");
    for(i = 0; i < 2*size; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n\n");

    // stergerea stivei 2

    printf("Stiva 2:\n");
    for(i = top_1 + 1; top_2 >= top_1 + 1; i++)
    {
        pop_2(stack, &top_2, top_1, &popped);
        printf("Elementul popped: %d\n", popped);
    }
    pop_2(stack, &top_2, top_1, &popped);
    printf("\n");

    // stergerea stivei 1

    printf("Stiva 1:\n");
    for(i = 0; top_1 >= 0; i++)
    {
        pop(stack, &top_1, &popped);
        printf("Elementul popped: %d\n", popped);
    }
    pop(stack, &top_1, &popped);

}
