#include <stdio.h>
#include <stdlib.h>

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

NODE *find_ancestor(NODE *root, int node_1, int node_2)
{
    NODE *left_tree, *right_tree;

    if(root == NULL)
        return NULL;

    if ((root->data == node_1) || (root->data == node_2))
        return root;

    left_tree = find_ancestor(root->left, node_1, node_2);
    right_tree = find_ancestor(root->right, node_1, node_2);

    if(left_tree && right_tree)
        return root;

    if(left_tree)
        return left_tree;
    else return right_tree;


}

void print_postorder(NODE* node)
{
    if (node == NULL)
        return;

    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->data);
}

int main()
{

    int node_1, node_2;
    NODE *root = insert_node(8);
    root->left = insert_node(3);
    root->right = insert_node(10);
    root->left->left = insert_node(1);
    root->left->right = insert_node(6);
    root->left->right->left = insert_node(4);
    root->left->right->right = insert_node(7);
    root->right->right = insert_node(14);
    root->right->right->left = insert_node(13);

    printf("Arborele: ");
    print_postorder(root);
    printf("\n");

    printf("Cel mai apropiat stramos comun al nodurilor 1 si 14 este: %d\n", find_ancestor(root, 1, 14)->data);
    printf("Cel mai apropiat stramos comun al nodurilor 1 si 4 este: %d\n", find_ancestor(root, 1, 4)->data);
    printf("Cel mai apropiat stramos comun al nodurilor 4 si 7 este: %d\n", find_ancestor(root, 4, 7)->data);

}
