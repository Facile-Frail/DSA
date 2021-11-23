
//Author - Hans Pattnaik(Github ID -> https://github.com/HANS-2002)

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
// k) Sort the linked list(merge sort).

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

void traverse(node *);
int isEmpty(node *);
void insertAtFront(node **, int);
void insertAtEnd(node **, int);
void insertAtPosition(node **, int, int);
void deleteFirst(node **);
void deleteEnd(node **);
void deletePosition(node **, int);
void deleteKey(node **, int);
int search(node *, int);
int countNodes(node *);
void freeList(node **);
void reverse(node **);
int detectLoop(node *);
void removeLoop(node **);
void makeLoop(node **, int);
node *SortedMerge(node *, node *);
void splitList(node *, node **, node **);
void MergeSort(node **);

int main()
{
    node *head = NULL;
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
               "\t15 Merge sort the linked list\n"
               "\t16 To free the linked list\n"
               "\t0 To exit\n"
               "----------------------------------------------------\n"
               "\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\nExiting the program......\n");
            freeList(&head);
            printf("\n\tX--------BYE--------X\n\n");
            return 0;
            break;
        case 1:
            traverse(head);
            break;
        case 2:
        {
            int data;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            insertAtFront(&head, data);
        }
        break;
        case 3:
        {
            int data;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
        }
        break;
        case 4:
        {
            int pos, data;
            printf("\nEnter position(start from 1) and data :");
            scanf("%d %d", &pos, &data);
            insertAtPosition(&head, data, pos);
        }
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
            printf("\nEnter element to search for: ");
            scanf("%d", &s);
            search(head, s) == -1 ? printf("\nElement %d not found\n", s) : printf("\nElement %d found at position: %d\n", s, search(head, s));
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
            printf("\nEnter node to point loop: ");
            scanf("%d", &n);
            makeLoop(&head, n);
        }
        break;
        case 14:
            detectLoop(head) ? printf("\nLoop Detected, removing loop.....\n"), removeLoop(&head) : printf("\n\nNo Loop Detected\n");
            break;
        case 15:
            MergeSort(&head);
            break;
        case 16:
            freeList(&head);
            break;
        default:
            printf("\nIncorrect Choice\n");
            break;
        }
    }
    return 0;
}

//Function to traverse(a.k.a print) the singly linked list.
void traverse(node *head)
{
    node *temp;

    if (head == NULL)
        printf("\nList is empty\n");
    else if (detectLoop(head))
        printf("\nLoop present in linked list\n");
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

//Function to check if the linked list is empty.
int isEmpty(node *head)
{
    return !head;
}

//Function to insert a node at a beginning of singly linked list.
void insertAtFront(node **head, int data)
{
    node *temp = malloc(sizeof(node));
    temp->info = data;
    temp->link = *head;
    *head = temp;
}

//Function to insert a node at a end of singly linked list.
void insertAtEnd(node **head, int data)
{
    node *temp = malloc(sizeof(node)), *h;
    temp->link = NULL;
    temp->info = data;
    h = *head;
    while (h->link != NULL)
        h = h->link;
    h->link = temp;
}

//Function to insert a node at a given position(starts from 1).
void insertAtPosition(node **head, int data, int pos)
{
    if (pos == 1)
        insertAtFront(head, data);
    else if (countNodes(*head) < pos)
        insertAtEnd(head, data);
    else
    {
        node *temp = *head, *newnode = malloc(sizeof(node));
        int i = 1;
        newnode->info = data;
        newnode->link = NULL;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

//Function to delete first node of the singly linked list.
void deleteFirst(node **head)
{
    node *temp;
    if (*head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

//Function to delete last node of the singly linked list.
void deleteEnd(node **head)
{
    node *temp, *prevnode;
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

//Function to delete a node on the basis of its position(starting from 1).
void deletePosition(node **head, int pos)
{
    node *temp, *position;
    int i = 1;

    if (*head == NULL)
        printf("\nList is empty\n");

    else
    {

        position = malloc(sizeof(node));
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

//Function to delete a node of the singly linked list using a key value(data point) -> Deletes the first occurrence of the key in case of multiple occurrence.
void deleteKey(node **head, int key)
{

    if (*head == NULL)
        printf("\nList is empty\n");
    int pos = search(*head, key);
    if (pos == -1)
        printf("\nElement not found!\n");
    else
        deletePosition(head, pos);
}

//Function to search a key in singly linked list(Return position of node if present else -1).
int search(node *head, int s)
{
    node *temp;
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

//Function to count the number of nodes of a singly linked list.
int countNodes(node *head)
{
    node *temp;
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

//Function to reverse a singly linked list.
void reverse(node **head)
{
    node *prev = NULL, *current = *head, *link;
    while (current)
    {
        link = current->link;
        current->link = prev;
        prev = current;
        current = link;
    }
    *head = prev;
}

//Function to detect loop in a singly linked list.
int detectLoop(node *head)
{
    node *slowPtr = head, *fastPtr = head;
    while (slowPtr && fastPtr && fastPtr->link)
    {
        slowPtr = slowPtr->link;
        fastPtr = fastPtr->link->link;
        if (slowPtr == fastPtr)
            return 1;
    }
    return 0;
}

//Function to remove loop in a singly linked list.
void removeLoop(node **head)
{
    if (!detectLoop(*head))
    {
        printf("\nLoop doesn't exists, make a loop first.\n");
        return;
    }
    node *fast = *head, *slow = *head;
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

//Function to make a loop to given data point in a singly linked list.
void makeLoop(node **head, int n)
{
    if (detectLoop(*head))
    {
        printf("\nLoop already exists\n");
        return;
    }
    node *temp = *head, *lastNode = temp;
    while (lastNode->link)
        lastNode = lastNode->link;
    while (temp->info != n)
        temp = temp->link;
    lastNode->link = temp;
}

//Function to sort 2 sorted linked list.
node *SortedMerge(node *a, node *b)
{
    node *res = NULL;

    //Base conditions
    if (!a)
        return b;
    else if (!b)
        return a;

    if (a->info <= b->info)
    {
        res = a;
        res->link = SortedMerge(a->link, b);
    }
    else
    {
        res = b;
        res->link = SortedMerge(a, b->link);
    }
    return res;
}

//Function to split the linked list into 2parts, in case of odd number of elements extra element goes to first halve of split.
void splitList(node *head, node **frontptr, node **backptr)
{
    //Algorithm used: 2 pointers(fast-moves by 2 steps every iteration,slow - moves by one step every iteration),
    //when fast reaches NULL , slow is at middle of linked list.
    node *fast = head->link, *slow = head;

    while (fast)
    {
        fast = fast->link;
        if (fast)
        {
            slow = slow->link;
            fast = fast->link;
        }
    }

    *frontptr = head;
    *backptr = slow->link;
    slow->link = NULL;
}

//Function to merge sort a linked list in ascending order.
void MergeSort(node **headRef)
{
    node *head = *headRef, *a, *b;

    if (!head || !(head->link))
        return;

    splitList(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

//Function to destroy the whole list.
void freeList(node **head)
{
    printf("\nFreeing the list........\n");
    node *temp = *head;
    if (!temp)
    {
        printf("Linked list already free.\n");
        return;
    }
    *head = (*head)->link;
    while (*head != NULL)
    {
        free(temp);
        temp = *head;
        *head = (*head)->link;
    }
    printf("Linked list freed.\n");
}
