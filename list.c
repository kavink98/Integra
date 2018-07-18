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
    printf("%s",head->name);
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
    char temp[50];
    strcpy(temp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp);

    strcpy(temp,a->phone);
    strcpy(a->phone,b->phone);
    strcpy(b->phone,temp);

    strcpy(temp,a->aadhar);
    strcpy(a->aadhar,b->aadhar);
    strcpy(b->aadhar,temp);

    strcpy(temp,a->dob.dd);
    strcpy(a->dob.dd,b->dob.dd);
    strcpy(b->dob.dd,temp);

    strcpy(temp,a->dob.mm);
    strcpy(a->dob.mm,b->dob.mm);
    strcpy(b->dob.mm,temp);

    strcpy(temp,a->dob.yy);
    strcpy(a->dob.yy,b->dob.yy);
    strcpy(b->dob.yy,temp);

    strcpy(temp,a->address);
    strcpy(a->address,b->address);
    strcpy(b->address,temp);

    strcpy(temp,a->occupation);
    strcpy(a->occupation,b->occupation);
    strcpy(b->occupation,temp);

    strcpy(temp,a->m_status);
    strcpy(a->m_status,b->m_status);
    strcpy(b->m_status,temp);

    strcpy(temp,a->income);
    strcpy(a->income,b->income);
    strcpy(b->income,temp);



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
