#include <stdio.h>

#define nNodes 10
#define MAX 9999

typedef struct muchie
{
    char sorce1[20];
    int index1;
    char sorce2[20];
    int index2;
    int distance;
}M;

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

void cost_matrix(int cost[][nNodes], M vector[], int nr_lines)
{
    int i, index1, index2;

    init(nNodes, cost);

    for(i = 0; i < nr_lines; i++)
    {
        index1 = vector[i].index1;
        index2 = vector[i].index2;

        cost[index1][index2] = vector[i].distance;
        cost[index2][index1] = vector[i].distance;
    }
}

void Dijkstra_alg(int cost[nNodes][nNodes], int source)
{
    int dist[nNodes], visited[nNodes], prev[nNodes];
    int count = 1, min_dist, next, i, order = 2, tree_cost = 0;
    M spanlist[nNodes];

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
            spanlist[i].sorce1 = i;
            spanlist[i].sorce2 = prev[i];
            spanlist[i].distance = cost[i][prev[i]];
        }
    }

    printf("Minimum spanning tree:\n");
    for (i = 0; i < nNodes; i++)
    {
        if(i != source)
        {
            printf("%d - %d: %d\n", spanlist[i].sorce1, spanlist[i].sorce2, spanlist[i].distance);
            tree_cost += spanlist[i].distance;
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

    cost_matrix(cost_m1, vector_1, nr_lines);

    Dijkstra_alg(cost_m1, 0);
    printf("\n\n");
    Dijkstra_alg(cost_m2, 0);
    printf("\n");
}
