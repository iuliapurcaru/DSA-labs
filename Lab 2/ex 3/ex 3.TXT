#include <stdio.h>

struct node
{
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;

void delete_element(NODE **head_ref, int key)
{
    NODE *current = *head_ref, *previous = NULL;

    while(current != NULL)
    {
        previous = current;
        current = current->next;
        if(previous->key == key)
        {
            if(previous->prev != NULL)
            {
                previous->prev->next = previous->next;
            }

            if(previous->next != NULL)
            {
                previous->next->prev = previous->prev;
            }

            break;
        }
    }

    *head_ref = current;
}

int main()
{

    NODE *head, *p, *q;
    int i, n, del_key;

    printf("Introduceti numarul de valori: ");
    scanf("%d", &n);

    p = (NODE*)malloc(sizeof(NODE));

    // introducerea elementelor

    getchar();
    printf("Introduceti valoarea cu indexul 0: ");
    scanf("%d", &p->data);
    p->key = 0;
    p->next = NULL;
    p->prev = NULL;
    head = p;

    for(i = 1; i < n; i++)
    {
        q = (NODE*)malloc(sizeof(NODE));
        printf("Introduceti valoarea cu indexul %d: ", i);
        scanf("%d", &q->data);
        q->key = i;
        q->next = NULL;
        p->next = q;
        q->prev = p;
        p = q;
    }
    printf("\n");

    printf("Introduceti indexul elementului care doriti sa fie sters (intre 0 si %d): ", n-1);
    scanf("%d", &del_key);

    delete_element(&head, del_key);

    for(p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

}
