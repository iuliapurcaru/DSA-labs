#include <limits.h>
#include <stdio.h>

#define nNodes 10

typedef struct edge
{
    int src, dest, weight;
} EDGE;

EDGE edges[] =
{
    {0, 2, 19}, {1, 2, 3}, {1, 3, 16}, {2, 8, 8}, {3, 6, 10}, {3, 7, 4}, {4, 5, 11}, {4, 9, 14}, {5, 8, 9}, {5, 9, 11}, {6, 8, 7}, {7, 9, 6}
};

int nEdges = sizeof(edges)/sizeof(edges[0]);

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

void adj_matrix(int adj[][nNodes])
{
    int i, src, dest;

    init(nNodes, adj);

    for(i = 0; i < nEdges; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        adj[src][dest] = edges[i].weight;
        adj[dest][src] = edges[i].weight;
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

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int min_node(int key[], int mst_nodes[])
{
    int i, min = INT_MAX, min_index;

    for(int i = 0; i < nNodes; i++)
    {
        if (mst_nodes[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void print_spanlist(int parent[], int adj[][nNodes])
{
    int i, cost = 0;

    printf("\nMinimum spanning tree:\n");
    for(i = 1; i < nNodes; i++)
    {
        printf("%d - %d: %d\n", parent[i], i, adj[i][parent[i]]);
        cost += adj[i][parent[i]];
    }
    printf("Cost total: %d", cost);
}

void prim_alg(int adj[][nNodes])
{
    // Array to store constructed MST
    int parent[nNodes];
    // Key values used to pick minimum weight edge in cut
    int key[nNodes];
    // To represent set of vertices included in MST
    int mst_nodes[nNodes];
    //int mst_nodes[nNodes];
    int i, u;

    // Initialize all keys as INFINITE
    for (int i = 0; i < nNodes; i++)
    {
        key[i] = INT_MAX;
        mst_nodes[i] = 0;
    }

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have nNodes vertices
    for (i = 0; i < nNodes; i++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        u = min_node(key, mst_nodes);

        // Add the picked vertex to the MST Set
        mst_nodes[u] = 1;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for(int v = 0; v < nNodes; v++)

            // adj[u][v] is non zero only for adjacent vertices of m
            // mst_nodes[v] is false for vertices not yet included in MST
            // Update the key only if adj[u][v] is smaller than key[v]
            if (adj[u][v] && mst_nodes[v] == 0 && adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    print_spanlist(parent, adj);
}

int main()
{

    int adj_m[nNodes][nNodes];

    adj_matrix(adj_m);
    printf("Matricea de adiacenta a grafului:\n");
    print_matrix(nNodes, adj_m);

    prim_alg(adj_m);
    printf("\n");

}
