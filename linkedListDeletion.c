// WAP to implement singly linked list with following operations:
// a) Create a linked list
// b) Deletion of first element, specified element and last element in the list
// c) Display the contents of the linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//  traversal of linked list
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insertion at first
struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// Insertion in between
struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Insertion at the End
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

// deletion at first
struct node *deleteAtFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// deletion at the between
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

// deletion at the End
struct node *deleteAtEnd(struct node *head)
{
    struct node *q = head;
    struct node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second; 

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth;

    fourth->data = 89;
    fourth->next = NULL;
    linkedListTraversal(head);

    while (1)
    {
        int dat, ind;
        int choice;
        printf("\n1.insertAtFirst\t\t\t\t2.insertAtIndex\t\t\t\t3.insertAtEnd\n4.deleteAtFirst\t\t\t\t5.deleteAtIndex\t\t\t\t6.deleteAtEnd\n7.linkedListTraversal\t\t\t\t7.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &dat);
            head = insertAtFirst(head, dat);
            break;

        case 2:
            scanf("%d", &dat);
            scanf("%d", &ind);
            head = insertAtIndex(head, dat, ind);
            break;

        case 3:
            scanf("%d", &dat);
            head = insertAtEnd(head, dat);
            break;

        case 4:
            head = deleteAtFirst(head);
            break;

        case 5:
            scanf("%d", &ind);
            head = deleteAtIndex(head, ind);
            break;

        case 6:
            head = deleteAtEnd(head);
            break;

        case 7:
            linkedListTraversal(head);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Enter other choice");
            break;
        }
    }

    return 0;
}