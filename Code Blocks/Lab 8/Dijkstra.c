#include <stdio.h>

#define nNodes 10
#define MAX 9999

typedef struct edge
{
    int src, dest, weight;
} EDGE;

EDGE edges_1[] =
{
    {0, 2, 19}, {1, 2, 3}, {1, 3, 16}, {2, 8, 8}, {3, 6, 10}, {3, 7, 4}, {4, 5, 11}, {4, 9, 14}, {5, 8, 9}, {5, 9, 11}, {6, 8, 7}, {7, 9, 6}
};

int nEdges_1 = sizeof(edges_1)/sizeof(edges_1[0]);

EDGE edges_2[] =
{
    {0, 1, -2}, {0, 3, 14}, {0, 4, 2}, {1, 2, -5}, {1, 8, 13}, {2, 9, 8}, {3, 5, -11}, {3, 8, -4}, {4, 6, 15}, {4, 7, -3}, {5, 9, 7}, {6, 7, 10}, {6, 8, -13}
};

int nEdges_2 = sizeof(edges_2)/sizeof(edges_2[0]);

void init(int n, int a[][n])
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] = MAX;
        }
    }
}

void cost_matrix(int cost[][nNodes], EDGE edges[], int nEdges)
{
    int i, src, dest;

    init(nNodes, cost);

    for(i = 0; i < nEdges; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        cost[src][dest] = edges[i].weight;
        cost[dest][src] = edges[i].weight;
    }
}

void Dijkstra_alg(int cost[nNodes][nNodes], int source)
{
    int dist[nNodes], visited[nNodes], prev[nNodes];
    int count = 1, min_dist, next, i, order = 2, tree_cost = 0;
    EDGE spanlist[nNodes];

    for (i = 0; i < nNodes; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
        prev[i] = source;
    }

    dist[source] = 0;
    visited[source] = 1;

    while(count < nNodes - 1)
    {
        min_dist = MAX;

        for(i = 0; i < nNodes; i++)
        {
            if((dist[i] < min_dist) && !visited[i])
            {
                min_dist = dist[i];
                next = i;
            }
        }

        visited[next] = order;
        order++;
        for(i = 0; i < nNodes; i++)
        {
            if (!visited[i])
            {
                if(min_dist + cost[next][i] < dist[i])
                {
                    dist[i] = min_dist + cost[next][i];
                    prev[i] = next;
                }
            }

        }
        count++;
    }

    for(i = 0; i < nNodes; i++)
    {
        if(i != source)
        {
            spanlist[i].src = i;
            spanlist[i].dest = prev[i];
            spanlist[i].weight = cost[i][prev[i]];
        }
    }

    printf("Minimum spanning tree:\n");
    for (i = 0; i < nNodes; i++)
    {
        if(i != source)
        {
            printf("%d - %d: %d\n", spanlist[i].src, spanlist[i].dest, spanlist[i].weight);
            tree_cost += spanlist[i].weight;
        }
    }
    printf("Total cost: %d", tree_cost);

    for (i = 0; i < nNodes; i++)
        if (i != source)
        {
            printf("\nDistance from source to %d: %d", i, dist[i]);
        }

}

int main()
{

    int cost_m1[nNodes][nNodes], cost_m2[nNodes][nNodes];

    cost_matrix(cost_m1, edges_1, nEdges_1);
    cost_matrix(cost_m2, edges_2, nEdges_2);

    Dijkstra_alg(cost_m1, 0);
    printf("\n\n");
    Dijkstra_alg(cost_m2, 0);
    printf("\n");
}
