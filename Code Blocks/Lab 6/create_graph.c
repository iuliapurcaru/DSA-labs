struct graph *create_graph(int nNodes, int nEdges, struct edge edges[])
{
    int i, src, dest;

    struct graph *graph = (struct graph*)malloc(sizeof(struct graph));
    graph->N = nNodes;

    for(i = 0; i < graph->N; i++)
    {
        graph->head[i] = NULL;
    }

    for(i = 0; i < nEdges; i++)
    {
        src = edges[i].src;
        dest = edges[i].dest;

        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->dest = dest;
        new_node->next = graph->head[src];
        graph->head[src] = new_node;

        new_node->dest = src;
        new_node->next = graph->head[dest];
        graph->head[dest] = new_node;

    }

    return graph;
}

void print_graph(struct graph *graph)
{
    int i;
    for (i = 0; i < graph->N; i++)
    {
        NODE *aux = graph->head[i];
        printf("Nodul %d: ", i);
        while (aux)
        {
            printf(" -> %d ", aux->dest);
            aux = aux->next;
        }
        printf("\n");
    }
}
