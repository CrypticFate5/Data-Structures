#include <stdio.h>
#define max 100
int queue[max];
int f = -1, r = -1;
int isFull()
{
    if (r == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (f == -1)
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
    if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        r++;
        queue[r] = x;
        if (f == -1)
        {
            f++;
        }
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
        printf("The dequeued element is %d\n", queue[f]);
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
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
        for (int i = f; i <= r; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    printf("WELCOME TO QUEUE IMPLEMENTATION OF ARRAY\n");
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
