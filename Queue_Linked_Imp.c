#include <stdio.h>
#include <stdlib.h>
struct node
{
    int element;
    struct node *next;
} *front = NULL, *rear = NULL;
typedef struct node node;

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->element = x;
    newnode->next = NULL;
    if (isEmpty())
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{

    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        node *temp = front;
        printf("The deleted element is %d\n", temp->element);
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        free(temp);
    }
}
void traverse()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        node *pos = front;
        while (pos != rear)
        {
            printf("%d ", pos->element);
            pos = pos->next;
        }
        printf("%d\n", rear->element);
    }
}
int main()
{
    printf("WELCOME TO LINKED IMPLEMENTATION OF QUEUE\n");
    int ch, x;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be enqueued: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice!!\n");
        }

    } while (ch != 4);
    return 0;
}
