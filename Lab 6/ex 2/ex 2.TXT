#include <stdio.h>

#define nNodes 5
#define maxsize 5

int stack[maxsize], top = -1;

struct edge
{
    int src, dest;
};

typedef struct edge EDGE;

void init(int n, int a[][n])
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}

void adj_matrix(int adj[][5], EDGE edges[], int edg)
{
    int i, src, dest;

    for(i = 0; i < edg; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        adj[src][dest] = 1;
    }
}

void print_matrix(int n, int a[][n])
{
    int i, j;

    printf("    ");
    for(j = 0; j < n; j++)
        printf("%d ", j);
    printf("\n\n");
    for(i = 0; i < n; i++)
    {
        printf("%d   ", i);
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top >= maxsize-1)
        return 1;
    else
        return 0;
}

void push(int element)
{
    if(isFull())
    {
        printf("Stiva este plina");
    }
    if(top == -1)
    {
        top = 0;
        stack[0] = element;
    }
    else
    {
        stack[top + 1] = element;
        top++;
    }
}
void pop()
{
    if(isEmpty(top))
    {
        printf("Stiva este goala\n");
    }
    else
    {
        top--;
    }
}

int peek()
{
    return stack[top];
}

int find_path(int begin, int end, int adj[][nNodes])
{
    int i = 0;

    push(begin);

    if(adj[begin][end])
    {
        push(end);
        return 1;
    }

    while(i < nNodes)
    {
        if(adj[begin][i] == 0)
        {
            i++;
        }
        else if(adj[begin][i] && find_path(i, end, adj) == 0)
        {
            pop();
            i++;
        }
        else if(find_path(i, end, adj))
        {
            pop();
            pop();
            return 1;
        }
        else return 0;
    }

    return 0;
}

int main()
{

    int i, nEdges, begin, end, n = 0;
    int adj_m[nNodes][nNodes];
    int path[nNodes];

    init(nNodes, adj_m);

    EDGE edges[] =
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 3}, {1, 4}, {3, 4}, {4, 2}
    };

    nEdges = sizeof(edges)/sizeof(edges[0]);

    adj_matrix(adj_m, edges, nEdges);

    printf("Matricea de adiacenta a grafului:\n");
    print_matrix(nNodes, adj_m);

    printf("\nIntroduceti cele doua noduri:\nNodul de plecare: ");
    scanf("%d", &begin);
    printf("Nodul de sosire: ");
    scanf("%d", &end);

    if(find_path(begin, end, adj_m))
    {
        while(top > -1)
        {
            path[n] = peek();
            n++;
            pop();
        }
        printf("Exista drum intre nodurile %d si %d: ", begin, end);
        for(i = n-1; i > 0; i--)
        {
            printf("%d->", path[i]);
        }
        printf("%d", path[0]);
    }
    else  printf("Nu exista drum intre nodurile %d si %d", begin, end);

    printf("\n");

}
