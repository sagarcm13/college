#include <stdio.h>
#include <stdlib.h>
#define max 20
int queue[max];
int front=-1;
int rear=-1;
void add()
{
    printf("enter element\n");
    int n;
    scanf("%d",&n);
    if (rear == max - 1)
    {
        printf("stack overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        queue[++rear] = n;
    }
    else
    {
        queue[++rear] = n;
    }
}
void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("stack underflow");
    }
    else
    {
        front++;
    }
}
void display()
{
    if (rear >= front && rear > -1)
    {
        printf("elements present in queue are\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
    else
        printf("NO elements present in queue");
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
            delete();
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
