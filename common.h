#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FILE_NAME "emp.dat"

FILE *fp;

struct employee
{
	char name[25],address[50],phone[11],email[25],occupation[15],aadhar[13],birthplace[15],m_status[10],income[10];
	int code;
	struct date
	{
		char dd[3],mm[3],yy[5];
	} dob;
	struct employee *next;
};

int findLines();
void input(struct employee *emp);
void write(struct employee *emp);
void read(struct employee *emp);
void search(struct employee *emp);
void modify(struct employee *emp);
void displayLine(struct employee *emp);
void readLine(struct employee *emp);

void swap(struct employee *, struct employee *);
void bubbleSort();
void push(struct employee *);
