#include "common.h"

/*Initialise a linked list by setting head to NULL*/
void init()
{
    head = NULL;
}

/*
Input: Employee Structure pointer
Push the input into the start of the linked list
*/
void push(struct employee *emp)
{
    struct employee *p;
    p = (struct employee*)malloc(sizeof(struct employee));
    *p = *emp;
    p->next = head;
    head = p;
}

/*Sort the linked list by phone numbers*/
void bubbleSortPhone()
{
    int swapped, i;
    struct employee *ptr1;
    struct employee *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->phone,ptr1->next->phone)>0)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/*
Input: Two Employee Structure pointers from a linked list
Swap the contents of the two pointers whilst keeping the next pointer the same
*/
void swap(struct employee *a, struct employee *b)
{
    struct employee* temp1;
    struct employee* temp2;
    struct employee temp3;
    temp1 = a->next;
    temp2 = b->next;
    temp3 = *a;
    *a = *b;
    *b = temp3;

    a->next = temp1;
    b->next = temp2;

}

/*Free the memory allocated for the linked list*/
void freeList()
{
    struct employee* curr;
    while(curr=head)
    {
        head = curr->next;
        free(curr);
    }
}

/*Sort the linked list by name*/
void bubbleSortName()
{
    int swapped, i;
    struct employee *ptr1;
    struct employee *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->name,ptr1->next->name)>0)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

}
