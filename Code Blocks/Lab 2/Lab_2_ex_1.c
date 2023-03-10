#include <stdio.h>

struct node
{
    int data;
    int key;
    struct node *next;
};

typedef struct node NODE;

void delete_duplicates(NODE *p1)
{
    NODE *p2;

    while((p1 != NULL) && (p1->next != NULL))
    {
        for(p2 = p1; p2->next != NULL; )
        {
            if(p1->data == p2->next->data)
            {
                p2->next = p2->next->next;
            }
            else p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main()
{

    NODE *head, *p, *q, *aux, *temp;
    int i, n;

    printf("Introduceti numarul de valori: ");
    scanf("%d", &n);

    p = (NODE*)malloc(sizeof(NODE));

    // introducerea elementelor

    getchar();
    printf("Introduceti valoarea cu indexul 0: ");
    scanf("%d", &p->data);
    p->key = 0;
    p->next = NULL;
    head = p;

    for(i = 1; i < n; i++)
    {
        q = (NODE*)malloc(sizeof(NODE));
        printf("Introduceti valoarea cu indexul %d: ", i);
        scanf("%d", &q->data);
        q->key = i;
        q->next = NULL;
        p->next = q;
        p = q;
    }
    printf("\n");

    delete_duplicates(&p);

    // afisarea listei fara duplicate

    printf("Lista fara duplicate este: ");
    for(p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

    printf("\n");

}
