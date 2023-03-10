#include <stdio.h>

struct node
{
    int data;
    int key;
    struct node *next;
};

typedef struct node NODE;

void reverse_list(NODE **head_ref)
{
    NODE *prev = NULL, *current = *head_ref, *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int is_palindrome(NODE *head_ref)
{
    NODE *reverse = head_ref;

    reverse_list(&reverse);

    while((head_ref != NULL) && (reverse != NULL))
    {
        if(head_ref->data != reverse->data)
        {
            return 0;
        }
        head_ref = head_ref->next;
        reverse = reverse->next;
    }
    return 1;
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

    if(is_palindrome(head) == 1)
        printf("Lista este un palindrom.");
    else printf("Lista nu este un palindrom.");

}
