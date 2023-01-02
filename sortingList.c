#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void sort(struct node *head)
{
    struct node *p = head;
    struct node *r = head;
    int t;
    while (p->next != NULL)
    {
        while (r->next != NULL)
        {
            if (r->data > r->next->data)
            {
                t = r->data;
                r->data = r->next->data;
                r->next->data = t;
            }
            r = r->next;
        }r=head;
        p = p->next;
    }
}
void join(struct node *f, struct node *s)
{
    struct node *p = f;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = s;
}
// void reverse(struct node *head){
     
//     struct node* prev = head;
//     struct node* pres = prev->next;
//     prev->next = NULL;
//     struct node* temp=;
//     while(temp->next != NULL){
//         temp = pres->next;
//         pres->next = prev;
//         prev = pres;
//         pres = temp;

//     }
//     temp->next = prev;
//     head = pres;

//     // display
//     temp = head;
//     while(temp != NULL){
//         printf("%d\n", temp->data);
//         temp = temp->next;
//     }
// }
void main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *sec;

    // Allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    sec = (struct node *)malloc(sizeof(struct node));

    sec->data = 434;
    sec->next = NULL;

    head->data = 74;
    head->next = second;
    // printf( "%d",head->data);

    second->data = 11;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 89;
    fourth->next = NULL;
    linkedListTraversal(head);
    sort(head);
    linkedListTraversal(head);
    join(head, sec);
    linkedListTraversal(head); 
    // reverse(head);
    // linkedListTraversal(head);
}