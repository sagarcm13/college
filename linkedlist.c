#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
    int value;
    struct linkedlist *next;
};
struct linkedlist *insert(struct linkedlist *s, int data)
{
    struct linkedlist *nextnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    nextnode->value = data;
    s->next = nextnode;
    nextnode->next = NULL;
    return s;
}
// struct linkedlist *insertmiddle(struct linkedlist *s, int data)
// {
//     struct linkedlist *nextnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
//     nextnode->value = data;
//     s->next = nextnode;
//     nextnode->next = NULL;
//     return s;
// }
struct linkedlist *insertfirst(struct linkedlist *s, int data)
{
    struct linkedlist *nextnode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    nextnode->value = data;
    nextnode->next = s;
    return nextnode;
}
void display(struct linkedlist *s)
{
    printf("elements in linkedlislt are\n");
    do
    {
        printf("%d\n", s->value);
        s = s->next;
    } while (s->next != NULL);
    printf("%d\n", s->value);
}
void main()
{
    struct linkedlist *head, *second, *p;
    // printf("enter the value of head\n");
    head = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    head->value=232;
    display(head);
    head=insert(head,2);
    display(head);
    head=insertfirst(head,6);
    display(head);
}