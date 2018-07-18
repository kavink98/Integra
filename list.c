#include "common.h"

void init()
{
    head = NULL;
}

void push(struct employee *emp)
{
    struct employee *p;
    p = (struct employee*)malloc(sizeof(struct employee));
    *p = *emp;
    p->next = head;
    head = p;
}

void bubbleSort()
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

void freeList()
{
    struct employee* curr;
    while(curr=head)
    {
        head = curr->next;
        free(curr);
    }
}

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
