#include <stdio.h>
#include <string.h>

#define MAX 9999

typedef struct comanda
{
    int cost;
    char adresa;

} COMANDA;

COMANDA comenzi[] =
{
    {34, 'a'}, {75, 'b'}, {23, 'c'}, {51, 'd'}, {24, 'e'}, {32, 'f'}
};

int nr_comenzi = sizeof(comenzi)/sizeof(comenzi[0]);

struct node
{
    COMANDA data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *insert_node(COMANDA data)
{
    NODE *temp_node = (NODE*)malloc(sizeof(NODE));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;

    return (temp_node);
}

void afisare_comenzi()
{
    int i;

    for(i = 0; i < nr_comenzi; i++)
    {
        printf("Cost comanda %d: %d - %c\n", i + 1, comenzi[i].cost, comenzi[i].adresa);
    }
}

void bubble_sort_descending()
{
    int i, j;
    char temp;
    COMANDA aux;

    for(i = 0; i < nr_comenzi - 1; i++)
    {
        for(j = i + 1; j <= nr_comenzi - 1; j++)
        {
            if(comenzi[i].cost < comenzi[j].cost)
            {
                aux = comenzi[i];
                comenzi[i] = comenzi[j];
                comenzi[j] = aux;
            }
        }
    }
}

void print_preorder(NODE* node)
{
    if (node == NULL)
        return;

    printf("%d - %c\n", node->data.cost, node->data.adresa);
    print_preorder(node->left);
    print_preorder(node->right);
}

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

void cost_matrix(int cost[][nr_comenzi], EDGE edges[], int nEdges)
{
    int i, src, dest;

    init(nr_comenzi, cost);

    for(i = 0; i < nEdges; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        cost[src][dest] = edges[i].weight;
        cost[dest][src] = edges[i].weight;
    }
}

void Dijkstra_alg(int cost[nr_comenzi][nr_comenzi], int source)
{
    int dist[nr_comenzi], visited[nr_comenzi], prev[nr_comenzi];
    int count = 1, min_dist, next, i, order = 2, tree_cost = 0;
    EDGE spanlist[nr_comenzi];

    for (i = 0; i < nr_comenzi; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
        prev[i] = source;
    }

    dist[source] = 0;
    visited[source] = 1;

    while(count < nr_comenzi - 1)
    {
        min_dist = MAX;

        for(i = 0; i < nr_comenzi; i++)
        {
            if((dist[i] < min_dist) && !visited[i])
            {
                min_dist = dist[i];
                next = i;
            }
        }

        visited[next] = order;
        order++;
        for(i = 0; i < nr_comenzi; i++)
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

    for (i = 0; i < nr_comenzi; i++)
        if (i != source)
        {
            printf("\nDistanta de la sursa la %d: %d", comenzi[i].adresa, dist[i]);
        }


}

int main()
{
    afisare_comenzi();
    bubble_sort_descending();
    printf("\n");
    afisare_comenzi();
    printf("\n");

    NODE *root = insert_node(comenzi[0]);
    root->left = insert_node(comenzi[1]);
    root->left->left = insert_node(comenzi[2]);
    root->left->right = insert_node(comenzi[3]);
    root->right = insert_node(comenzi[4]);
    root->right->left = insert_node(comenzi[5]);

    print_preorder(root);
}
