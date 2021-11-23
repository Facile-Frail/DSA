// Operations in the Singly Linked List(Return Pointer Implementation)
// a) Traversal of the list.
// b) Check if the list is empty.
// c) Insert a node at the certain position (at beginning/end/any position).
// d) Delete a node at the certain position (at beginning/end/any position).
// e) Delete a node for the given key.
// f) Count the total number of nodes.
// g) Search for an element in the linked list.
// h) Reverse a linked list.
// i) Make loop in linked list.
// j) Detect Loop and remove it.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void traverse(struct node *head)
{
    struct node *temp;

    if (head == NULL)
        printf("\nList is empty\n");

    else
    {
        temp = head;
        printf("\nThe list is => ");
        while (temp != NULL)
        {
            printf("%d -> ", temp->info);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

int isEmpty(struct node *head)
{
    return !head;
}

int search(struct node *head, int s)
{
    struct node *temp;
    int pos = 0;

    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            pos++;
            if (temp->info == s)
                break;
            temp = temp->link;
        }
    }

    return temp == NULL ? -1 : pos;
}

int countNodes(struct node *head)
{
    struct node *temp;
    int count = 0;

    if (head != NULL)
    {
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->link;
        }
    }

    return count;
}

void freeList(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->link;
    while (*head != NULL)
    {
        free(temp);
        temp = *head;
        *head = (*head)->link;
    }
}

int detectLoop(struct node *head)
{
    struct node *slowPtr = head, *fastPtr = head;
    while (slowPtr && fastPtr && fastPtr->link)
    {
        slowPtr = slowPtr->link;
        fastPtr = fastPtr->link->link;
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}

int main()
{
    struct node *head = NULL;
    int choice;
    while (1)
    {
        printf("\n------------------------MENU------------------------\n"
               "\t1 To see list\n"
               "\t2 For insertion at heading\n"
               "\t3 For insertion at end\n"
               "\t4 For insertion at any position\n"
               "\t5 For deletion of first element\n"
               "\t6 For deletion of last element\n"
               "\t7 For deletion of element at any position\n"
               "\t8 For deletion of element for any key\n"
               "\t9 For counting number of nodes\n"
               "\t10 For searching an element\n"
               "\t11 For checking if list is empty or not\n"
               "\t12 Reverse a linked list\n"
               "\t13 Make loop in linked list\n"
               "\t14 Detect Loop and remove it\n"
               "\t0 To exit\n"
               "----------------------------------------------------\n"
               "\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            freeList(&head);
            return 0;
            break;
        case 1:
            traverse(head);
            break;
        case 2:
            // insertAtFront(&head);
            break;
        case 3:
            // insertAtEnd(&head);
            break;
        case 4:
            // insertAtPosition(&head);
            break;
        case 5:
            // deleteFirst(&head);
            break;
        case 6:
            // deleteEnd(&head);
            break;
        case 7:
            // {
            //     int pos;
            //     printf("\nEnter index to delete(start from 1): ");
            //     scanf("%d", &pos);
            //     deletePosition(&head, pos);
            // }
            break;
        case 8:
        // {
        //     int key;
        //     printf("\nEnter key : ");
        //     scanf("%d", &key);
        //     deleteKey(&head, key);
        // }
        case 9:
            printf("\nNumber of nodes = %d\n", countNodes(head));
            break;
        case 10:
        {
            int s;
            printf("Enter element to search for: ");
            scanf("%d", &s);
            printf("\nElement found at index(-1 if not found) = %d\n", search(head, s));
        }
        break;
        case 11:
            isEmpty(head) ? printf("\nList is empty!\n") : printf("\nList is not empty!\n");
            break;
        case 12:
            // reverse(&head);
            break;
        case 13:
            // {
            //     int n;
            //     printf("Enter node to point loop: ");
            //     scanf("%d", &n);
            //     makeLoop(&head, n);
            // }
            break;
        case 14:
            detectLoop(head) ? printf("Loop Detected, removing loop.....\n") /*, removeLoop(&head)*/ : printf("No Loop Detected\n");
            break;
        default:
            printf("Incorrect Choice\n");
            break;
        }
    }
    return 0;
}
