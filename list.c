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
            if (atoi(ptr1->phone) > atoi(ptr1->next->phone))
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
    struct employee *temp;
    temp = a;
    a = b;
    b = temp;
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
