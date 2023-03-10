#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define map_rows 7
#define map_cols 8
#define MAX 99999

int map[map_rows][map_cols] = {1, 1, 1, 1, 1, 1, 1, 1,
                                1, 0, 1, 0, 0, 0, 0, 1,
                                1, 0, 0, 0, 0, 0, 0, 1,
                                1, 0, 1, 0, 1, 0, 0, 1,
                                1, 0, 1, 0, 0, 1, 0, 1,
                                1, 0, 0, 0, 0, 1, 0, 1,
                                1, 1, 1, 1, 1, 1, 1, 1
                               };

typedef struct stop
{
    int col, row;
    int *n;
    int n_len, from;
    double f, g, h;

} STOP;

int ind[map_rows][map_cols] = {-1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, -1
                               };

typedef struct route
{
    int src, dest;
    double d;

} ROUTE;

int main()
{
    int i, j, k, l, b, found;
    int start, end, current;
    int p_len = 0, c_len = 0, o_len = 1, s_len = 0, r_len = 0;
    int *path = NULL;
    int *closed = NULL;
    int *open = (int*)calloc(o_len, sizeof(int));
    double min, tempg;
    STOP *stops = NULL;
    ROUTE *routes = NULL;

    for(i = 1; i < map_rows - 1; i++)
    {
        for(j = 1; j < map_cols - 1; j++)
        {
            if(!map[i][j])
            {
                s_len++;
                stops = (STOP *)realloc(stops, s_len *sizeof(STOP));
                int t = s_len - 1;
                stops[t].col = j;
                stops[t].row = i;
                stops[t].from = -1;
                stops[t].g = MAX;
                stops[t].n_len = 0;
                stops[t].n = NULL;
                ind[i][j] = t;
            }
        }
    }

    start = 0;
    end = s_len - 1;

    for(i = 0; i < s_len; i++)
    {
        stops[i].h = sqrt(pow(stops[end].row - stops[i].row, 2) + pow(stops[end].col - stops[i].col, 2));
    }

    for(i = 1; i < map_rows - 1; i++)
    {
        for(j = 1; j < map_cols - 1; j++)
        {
            if(ind[i][j] >= 0)
            {
                for(k = i - 1; k <= i + 1; k++)
                {
                    for(l = j - 1; l <= j + 1; l++)
                    {
                        if((k == i) && (l == j))
                        {
                            continue;
                        }
                        if(ind[k][l] >= 0)
                        {
                            r_len++;
                            routes = (ROUTE *)realloc(routes, r_len *sizeof(ROUTE));
                            int t = r_len - 1;
                            routes[t].src = ind[i][j];
                            routes[t].dest = ind[k][l];
                            routes[t].d = sqrt(pow(stops[routes[t].dest].row - stops[routes[t].src].row, 2) + pow(stops[routes[t].dest].col - stops[routes[t].src].col, 2));
                            stops[routes[t].src].n_len++;
                            stops[routes[t].src].n = (int*)realloc(stops[routes[t].src].n, stops[routes[t].src].n_len *sizeof(int));
                            stops[routes[t].src].n[stops[routes[t].src].n_len - 1] = t;
                        }
                    }
                }
            }
        }
    }

    open[0] = start;
    stops[start].g = 0;
    stops[start].f = stops[start].g + stops[start].h;
    found = 0;

    while(o_len && !found)
    {
        min = MAX;

        for(i = 0; i < o_len; i++)
        {
            if(stops[open[i]].f < min)
            {
                current = open[i];
                min = stops[open[i]].f;
            }
        }

        if(current == end)
        {
            found = 1;

            p_len++;
            path = (int*)realloc(path, p_len *sizeof(int));
            path[p_len - 1] = current;
            while(stops[current].from >= 0)
            {
                current = stops[current].from;
                p_len++;
                path = (int*)realloc(path, p_len *sizeof(int));
                path[p_len - 1] = current;
            }
        }

        for(i = 0; i < o_len; i++)
        {
            if(open[i] == current)
            {
                if(i != (o_len - 1))
                {
                    for(j = i; j < (o_len - 1); j++)
                    {
                        open[j] = open[j + 1];
                    }
                }
                o_len--;
                open = (int*)realloc(open, o_len *sizeof(int));
                break;
            }
        }

        c_len++;
        closed = (int*)realloc(closed, c_len *sizeof(int));
        closed[c_len - 1] = current;

        for(i = 0; i < stops[current].n_len; i++)
        {
            b = 0;

            for(j = 0; j < c_len; j++)
            {
                if(routes[stops[current].n[i]].dest == closed[j])
                {
                    b = 1;
                }
            }

            if(b)
            {
                continue;
            }

            tempg = stops[current].g + routes[stops[current].n[i]].d;

            b = 1;

            if(o_len > 0)
            {
                for(j = 0; j < o_len; j++)
                {
                    if(routes[stops[current].n[i]].dest == open[j])
                    {
                        b = 0;
                    }
                }
            }

            if(b || (tempg < stops[routes[stops[current].n[i]].dest].g))
            {
                stops[routes[stops[current].n[i]].dest].from = current;
                stops[routes[stops[current].n[i]].dest].g = tempg;
                stops[routes[stops[current].n[i]].dest].f = stops[routes[stops[current].n[i]].dest].g + stops[routes[stops[current].n[i]].dest].h;

                if(b)
                {
                    o_len++;
                    open = (int*)realloc(open, o_len *sizeof(int));
                    open[o_len - 1] = routes[stops[current].n[i]].dest;
                }
            }
        }
    }

    if(found)
    {
        printf("Drumul este:\n");
        for(i = p_len - 1; i >= 0; i--)
        {
            printf("(%d, %d)\n", stops[path[i]].col, stops[path[i]].row);
        }
        printf("Cost total: %d\n", p_len);
    }
    else printf("Nu exista drum");

    for(i = 0; i < s_len; ++i)
    {
        free(stops[i].n);
    }
    free(stops);
    free(routes);
    free(path);
    free(open);
    free(closed);

    return 0;
}
