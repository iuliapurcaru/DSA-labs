#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

/* Returns true if the given tree is a binary search tree
(efficient version). */
int isBST(struct node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its
values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;

    /* false if this node violates the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* Driver program to test above functions*/
int main()
{
    struct node *root_1 = newNode(1);

    root_1->left = newNode(2);
    root_1->right = newNode(3);
    root_1->left->left = newNode(4);
    root_1->left->right = newNode(5);

    if(isBST(root_1))
        printf("Is BST");
    else
        printf("Not a BST");

    struct node *root_2 = newNode(8);
    root_2->left = newNode(3);
    root_2->right = newNode(10);
    root_2->left->left = newNode(1);
    root_2->left->right = newNode(6);
//    root_2->left->right->left = newNode(4);
//    root_2->left->right->right = newNode(7);
    root_2->right->right = newNode(14);
//    root_2->right->right->left = newNode(13);

    if(isBST(root_2))
        printf("Is BST");
    else
        printf("Not a BST");

    getchar();
    return 0;
}

