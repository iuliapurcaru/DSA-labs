#include <stdio.h>

int isEmpty_stack(int top)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull_stack(int top, int size)
{
    if(top >= size-1)
        return 1;
    else
        return 0;
}

void push(int element, int stack[], int *top, int size)
{
    if(isFull_stack(*top, size))
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
    if(isEmpty_stack(*top))
    {
        printf("Stiva este goala\n");
    }
    else
    {
        *n = stack[*top];
        (*top)--;
    }
}

int isEmpty_queue(int size)
{
    if(size == 0)
        return 1;
    else
        return 0;
}

int isFull_queue(int size, int maxsize)
{
    if(size >= maxsize)
        return 1;
    else
        return 0;
}

void enqueue(int element, int queue[], int *rear, int *size, int maxsize)
{
    if(isFull_queue(*size, maxsize))
    {
        printf("Coada este plina");
    }
    else if(*rear == -1)
    {
        *rear = 0;
        queue[0] = element;
        (*size)++;
    }
    else
    {
        queue[(*rear) + 1] = element;
        (*rear)++;
        (*size)++;
    }
}

int main()
{
    int sSize = 5, maxsize = 5, qSize = 0, i, popped;
    int stack_1[sSize], top_1 = -1;
    int stack_2[maxsize], top_2 = -1;
    int queue[maxsize], front = 0, rear = -1;

    // crearea stivei 1

    for(i = 0; i < sSize; i++)
    {
        push(i, stack_1, &top_1, sSize);
    }

    printf("Stiva 1:\n");
    for(i = top_1; i >= 0; i--)
    {
        printf("%d\n", stack_1[i]);
    }
    printf("\n");

    for(i = 0; top_1 >= 0; i++)
    {
        pop(stack_1, &top_1, &popped);
        push(popped, stack_2, &top_2, sSize);
    }

    printf("Stiva 2:\n");
    for(i = top_2; i >= 0; i--)
    {
        printf("%d\n", stack_2[i]);
    }
    printf("\n");

    for(i = 0; top_2 >= 0; i++)
    {
        pop(stack_2, &top_2, &popped);
        enqueue(popped, queue, &rear, &qSize, maxsize);
    }

    printf("Coada: ");
    for(i = 0; i < maxsize; i++)
    {
        printf("%d ", queue[i]);
    }

}
