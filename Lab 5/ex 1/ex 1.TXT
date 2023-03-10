#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

NODE *insert_node(int data)
{
    NODE *temp_node = (NODE*)malloc(sizeof(NODE));

    temp_node->data = data;
    temp_node->left = NULL;
    temp_node->right = NULL;

    return (temp_node);
}

int tree_height(NODE *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(tree_height(node->left), tree_height(node->right));
}

int balanced_tree(NODE *node)
{
    int left_height, right_height, height_dif;

    if((node->left == NULL) && (node->right == NULL))
        return 1;

    left_height = tree_height(node->left);
    right_height = tree_height(node->right);

    height_dif = left_height - right_height;

    if(height_dif < 0)
    {
        height_dif *= -1;
    }

    if(height_dif <= 1 && balanced_tree(node->left) && balanced_tree(node->right))
        return 1;

    return 0;

}

void print_inorder(NODE* node)
{
    if (node == NULL)
        return;

    print_inorder(node->left);
    printf("%d ", node->data);
    print_inorder(node->right);
}

int main()
{

    NODE *root_1 = insert_node(1);
    NODE *root_2 = insert_node(1);

    root_1->left = insert_node(2);
    root_1->right = insert_node(3);
    root_1->left->left = insert_node(4);
    root_1->left->right = insert_node(5);

    root_2->left = insert_node(2);
    root_2->right = insert_node(3);
    root_2->left->left = insert_node(4);
    root_2->left->right = insert_node(5);
    root_2->left->left->left = insert_node(6);

    printf("Arborele 1: ");
    print_inorder(root_1);
    printf("\n");

    if(balanced_tree(root_1))
    {
        printf("Arborele este echilibrat.\n");
    }
    else
    {
        printf("Arborele nu este echilibrat.\n");
    }

    printf("Arborele 2: ");
    print_inorder(root_2);
    printf("\n");

    if(balanced_tree(root_2))
    {
        printf("Arborele este echilibrat.\n");
    }
    else
    {
        printf("Arborele nu este echilibrat.\n");
    }

}
