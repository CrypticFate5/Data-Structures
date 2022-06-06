#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *left;
    struct node *right;
};
typedef struct node node;
void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->element);
        inorder(tree->right);
    }
}
void preorder(node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->element);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void postorder(node *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->element);
    }
}
node *insert(node *tree, int x)
{
    if (tree == NULL)
    {
        node *newnode = malloc(sizeof(node));
        newnode->right = newnode->left = NULL;
        newnode->element = x;
        tree = newnode;
    }
    else if (x < tree->element)
    {
        tree->left = insert(tree->left, x);
    }
    else if (x > tree->element)
    {
        tree->right = insert(tree->right, x);
    }
    return tree;
}
int main()
{
    int ch, n;
    node *tree = NULL;
    do
    {
        printf("\nEnter your choice: \n");
        printf("1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Exit\n");
        scanf("%d", &ch);
        int x;
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements: \n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &x);
                tree = insert(tree, x);
            }
            break;
        case 2:
            inorder(tree);
            break;
        case 3:
            preorder(tree);
            break;
        case 4:
            postorder(tree);
            break;
        case 5:
            break;
        default:
            printf("Invalid Choice...\n");
        }
    } while (ch != 5);
    return 0;
}
