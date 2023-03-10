#include <stdio.h>

int isEmpty(int size)
{
    if(size == 0)
        return 1;
    else
        return 0;
}

int isFull(int size, int maxsize)
{
    if(size >= maxsize)
        return 1;
    else
        return 0;
}

void enqueue(int element, int queue[], int *rear, int *size, int maxsize)
{
    if(isFull(*size, maxsize))
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

void dequeue(int queue[], int *front, int *n, int *size)
{
    if(isEmpty(*size))
    {
        printf("Coada este goala\n");
    }
    else
    {
        *n = queue[*front];
        (*front)++;
        (*size)--;
    }
}

int peek(int queue[], int front)
{
    return queue[front];
}

int main()
{

    int maxsize = 6, size = 0, front = 0, rear = -1, queue[maxsize], i, removed;

    // crearea cozii

    printf("Enqueue (size = %d): ", size);
    for(i = 0; i < maxsize; i++)
    {
        enqueue(i, queue, &rear, &size, maxsize);
        printf("%d ", queue[i], size);
    }
    printf("\nSize dupa enqueue: %d\n", size);

    if(isFull(size, maxsize))
    {
        printf("Coada este plina\n\n");
    }

    // stergerea cozii

    printf("Dequeue (size = %d):\n", size);
    for(i = 0; i < maxsize; i++)
    {
        printf("Front: %d - ", peek(queue, front));
        dequeue(queue, &front, &removed, &size);
        printf("Elementul sters: %d - size: %d\n", removed, size);
    }

    if(isEmpty(size))
    {
        printf("Coada este goala\n");
    }
}
