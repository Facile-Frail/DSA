// Operations in the Singly Linked List(Double Pointer Implementation)
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

void insertAtFront(struct node **head)
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = *head;
    *head = temp;
}

void insertAtEnd(struct node **head)
{
    int data;
    struct node *temp, *h;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    temp->link = NULL;
    temp->info = data;
    h = *head;
    while (h->link != NULL)
    {
        h = h->link;
    }
    h->link = temp;
}

void insertAtPosition(struct node **head)
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    temp = *head;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst(struct node **head)
{
    struct node *temp;
    if (*head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

void deleteEnd(struct node **head)
{
    struct node *temp, *prevnode;
    if (*head == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = *head;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void deletePosition(struct node **head, int pos)
{
    struct node *temp, *position;
    int i = 1;

    if (*head == NULL)
        printf("\nList is empty\n");

    else
    {

        position = malloc(sizeof(struct node));
        temp = *head;

        if (pos == 1)
        {
            deleteFirst(head);
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->link;
                i++;
            }
            position = temp->link;
            temp->link = position->link;

            free(position);
        }
    }
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

void deleteKey(struct node **head, int key)
{

    if (*head == NULL)
        printf("\nList is empty\n");
    int pos = search(*head, key);
    if (pos == -1)
        printf("\nElement not found!\n");
    else
        deletePosition(head, pos);
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

void reverse(struct node **head)
{
    struct node *prev = NULL, *current = *head, *link;
    while (current)
    {
        link = current->link;
        current->link = prev;
        prev = current;
        current = link;
    }
    *head = prev;
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

void removeLoop(struct node **head)
{
    struct node *fast = *head, *slow = *head;
    do
    {
        slow = slow->link;
        fast = fast->link->link;
    } while (slow != fast);
    if (fast == *head)
    {
        while (slow->link != *head)
            slow = slow->link;
        slow->link = NULL;
        return;
    }
    fast = *head;
    while (slow->link != fast->link)
    {
        slow = slow->link;
        fast = fast->link;
    }
    slow->link = NULL;
}

void makeLoop(struct node **head, int n)
{
    struct node *temp = *head, *lastNode = temp;
    while (lastNode->link)
        lastNode = lastNode->link;
    while (temp->info != n)
        temp = temp->link;
    lastNode->link = temp;
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
            insertAtFront(&head);
            break;
        case 3:
            insertAtEnd(&head);
            break;
        case 4:
            insertAtPosition(&head);
            break;
        case 5:
            deleteFirst(&head);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
        {
            int pos;
            printf("\nEnter index to delete(start from 1): ");
            scanf("%d", &pos);
            deletePosition(&head, pos);
        }
        break;
        case 8:
        {
            int key;
            printf("\nEnter key : ");
            scanf("%d", &key);
            deleteKey(&head, key);
        }
        break;
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
            reverse(&head);
            break;
        case 13:
        {
            int n;
            printf("Enter node to point loop: ");
            scanf("%d", &n);
            makeLoop(&head, n);
        }
        break;
        case 14:
            detectLoop(head) ? printf("Loop Detected, removing loop.....\n"), removeLoop(&head) : printf("No Loop Detected\n");
            break;
        default:
            printf("Incorrect Choice\n");
            break;
        }
    }
    return 0;
}
