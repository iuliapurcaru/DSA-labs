#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *insert_node(int data)
{
    NODE *temp_node = (NODE*)malloc(sizeof(NODE));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;

    return (temp_node);
}

int max_value(NODE *node)
{
    if(node == NULL)
        return INT_MIN;

    int max = node->data;
    int left_max = max_value(node->left), right_max = max_value(node->right);

    if(left_max > max)
    {
        max = left_max;
    }

    if(right_max > max)
    {
        max = right_max;
    }

    return max;
}

int min_value(NODE *node)
{
    if(node == NULL)
        return INT_MAX;

    int min = node->data;
    int left_min = min_value(node->left), right_min = min_value(node->right);

    if(left_min < min)
    {
        min = left_min;
    }

    if(right_min < min)
    {
        min = right_min;
    }

    return min;
}

int binary_search_tree(NODE *node)
{
    if(node == NULL)
        return 1;

   if (node->left && (max_value(node->left) > node->data))
        return 0;

    if (node->right && (min_value(node->right) < node->data))
        return 0;

    if ((binary_search_tree(node->left) == 0) || (binary_search_tree(node->right) == 0))
        return 0;

    return 1;
}

void print_preorder(NODE* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    print_preorder(node->left);
    print_preorder(node->right);
}

int main()
{

    NODE *root_1 = insert_node(1);

    root_1->left = insert_node(2);
    root_1->right = insert_node(3);
    root_1->left->left = insert_node(4);
    root_1->left->right = insert_node(5);

    printf("Arborele 1: ");
    print_preorder(root_1);
    printf("\n");

    if(binary_search_tree(root_1))
    {
        printf("Arborele este binary search tree.\n");
    }
    else
    {
        printf("Arborele nu este binary search tree.\n");
    }

    NODE *root_2 = insert_node(8);
    root_2->left = insert_node(3);
    root_2->right = insert_node(10);
    root_2->left->left = insert_node(1);
    root_2->left->right = insert_node(6);
    root_2->left->right->left = insert_node(4);
    root_2->left->right->right = insert_node(7);
    root_2->right->right = insert_node(14);
    root_2->right->right->left = insert_node(13);

    printf("Arborele 2: ");
    print_preorder(root_2);
    printf("\n");

    if(binary_search_tree(root_2))
    {
        printf("Arborele este binary search tree.\n");
    }
    else
    {
        printf("Arborele nu este binary search tree.\n");
    }

}
