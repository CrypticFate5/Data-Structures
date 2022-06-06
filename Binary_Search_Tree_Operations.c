#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *left;
    struct node *right;
};
typedef struct node node;
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
void inorder(node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->element);
        inorder(tree->right);
    }
}
node *search(node *tree, int x)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (x < tree->element)
    {
        return search(tree->left, x);
    }
    else if (x > tree->element)
    {
        return search(tree->right, x);
    }
    else
    {
        return tree;
    }
}
node *searchMin(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return searchMin(tree->left);
    }
}
void searchMax(node *tree)
{
    if (tree == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        while (tree->right != NULL)
        {
            tree = tree->right;
        }
        printf("%d is the maximum element\n", tree->element);
    }
}
node *delete (node *tree, int x)
{
    node *temp;
    if (x < tree->element)
    {
        tree->left = delete (tree->left, x);
    }
    else if (x > tree->element)
    {
        tree->right = delete (tree->right, x);
    }
    else if (tree->left && tree->right)
    {
        temp = searchMin(tree->right);
        tree->element = temp->element;
        tree->right = delete (tree->right, tree->element);
    }
    else
    {
        if (tree->left == NULL)
        {
            tree = tree->right;
        }
        else if (tree->right == NULL)
        {
            tree = tree->left;
        }
        free(temp);
    }
    return tree;
}
int main()
{
    node *tree = NULL;
    int ch, x, n;
    do
    {
        printf("\nEnter your choice: \n");
        printf("1.Insert Elements\n2.Traverse (inorder)\n3.Delete Element\n4.Search\n5.Search Minimum\n6.Search Maximum\n7.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of elements: \n");
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
            printf("Enter the element to be deleted: \n");
            scanf("%d", &x);
            delete (tree, x);
            break;
        case 4:
            printf("Enter the element to search for: \n");
            scanf("%d", &x);
            if (search(tree, x) != NULL)
            {
                printf("Element Found!!\n");
            }
            else
            {
                printf("Element Not Found\n");
            }
            break;
        case 5:
            if (searchMin(tree) != NULL)
            {
                printf("%d is the minimum element\n", searchMin(tree)->element);
            }
            else
            {
                printf("Tree is empty\n");
            }
            break;
        case 6:
            searchMax(tree);
            break;
        case 7:
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
    } while (ch != 7);
    return 0;
}
