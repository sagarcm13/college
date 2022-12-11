#include <stdio.h>
#include <stdlib.h>
#define max 5
int queue[max];
int front = -1, rear = -1;

void add()
{
    printf("enter the element\n");
    int n;
    scanf("%d", &n);
    if ((front == rear + 1) || (front == 0 && rear == max - 1))
        printf("\n Queue is full!! \n");
    else if (front == -1 && rear == -1)
    {
        front = 0;
        queue[++rear] = n;
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = n;
    }
}

void delete()
{
    int element;
    if (front == -1)
    {
        printf("\n Queue is empty !! \n");
    }
    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % max;
        }
        printf("\n Deleted element -> %d \n", element);
    }
}

void display()
{
    int i;
    if (front==-1)
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % max)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
    }
}

void main()
{
    while (1)
    {
        int n;
        printf("enter choice 1 for add\n2 for delete\n3 for display\n4 for exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting the program\n");
            exit(1);
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }
}