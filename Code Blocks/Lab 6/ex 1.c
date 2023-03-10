#include <stdio.h>

#define nNodes 6
#define maxsize 6

int visited_dfs[10], visited_bfs[10];
int queue[maxsize], front = 0, rear = -1, size = 0;

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

void adj_matrix(int adj[][nNodes], EDGE edges[], int edg)
{
    int i, src, dest;

    for(i = 0; i < edg; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        adj[src][dest] = 1;
        adj[dest][src] = 1;
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

void DFS(int adj[][nNodes], int head)
{
    int i;
    visited_dfs[head] = 1;

    for(i = 0; i < nNodes; i++)
    {
        if((adj[head][i]) && (visited_dfs[i] == 0))
        {
            printf("%d->%d  ", head, i);
            DFS(adj, i);
        }
    }
}

int isEmpty()
{
    if(size == 0)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(size >= maxsize)
        return 1;
    else
        return 0;
}

void enqueue(int element)
{
    if(isFull(size))
    {
        printf("Coada este plina");
    }
    else if(rear == -1)
    {
        rear = 0;
        queue[0] = element;
        size++;
    }
    else
    {
        queue[rear + 1] = element;
        rear++;
        size++;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Coada este goala\n");
    }
    else
    {
        front++;
        size--;
    }
}

int peek()
{
    return queue[front];
}

void BFS(int adj[][nNodes], int head)
{
    int i, j, temp;
    visited_bfs[head] = 1;

    enqueue(head);

    while(isEmpty() == 0)
    {
        temp = peek();
        dequeue();

        for(i = 0; i < nNodes; i++)
        {
            if((adj[temp][i]) && (visited_bfs[i] == 0))
            {
                printf("%d->%d  ", temp, i);
                enqueue(i);
                visited_bfs[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, nEdges, dfs_node, bfs_node;
    int adj_m[nNodes][nNodes];

    init(nNodes, adj_m);

    EDGE edges[] =
    {
        {0, 1}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {4, 5}
    };

    nEdges = sizeof(edges)/sizeof(edges[0]);

    // crearea matricei de adiacenta

    adj_matrix(adj_m, edges, nEdges);

    printf("Matricea de adiacenta a grafului:\n");
    print_matrix(nNodes, adj_m);

    // parcurgerea DFS

    printf("\nIntroduceti nodul de plecare pentru parcurgerea DFS: ");
    scanf("%d", &dfs_node);
    printf("Parcurgerea DFS plecand de la nodul %d: ", dfs_node);
    DFS(adj_m, dfs_node);

    printf("\n");

    // parcurgerea BFS

    printf("\nIntroduceti nodul de plecare pentru parcurgerea BFS: ");
    scanf("%d", &bfs_node);
    printf("Parcurgerea BFS plecand de la nodul %d: ", bfs_node);
    BFS(adj_m, bfs_node);

    printf("\n");
}
