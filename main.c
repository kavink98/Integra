#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "verification.h"
#include "io.h"

struct employee
{
	char name[25],address[50],phone[11],email[25],occupation[15],aadhar[13],birthplace[15],m_status[10],income[10];
	int code;
	struct date
	{
		char dd[3],mm[3],yy[5];
	} dob;
};//Declaring structure

void main()
{
	FILE *fp;
	printf("Enter 1 for input,2 for read and 3 for search\n");
	int choice;
	scanf("%d",&choice);
	struct employee emp;
	while(1)
	{
    if(choice==1)
    input(&emp,fp);

	  else if (choice == 2)
	   {
	     read(&emp,fp);
	   }

    else if(choice == 3)
    search(&emp,fp);

    else if(choice == 4)
    {
        findLines(fp);
        exit(0);
    }
    else
    printf("ENter Valid Input\n");
    
    printf("Do you want to continue inputting\n1.Continue\n2.read file\n3.Search\n4.Exit\n");
		scanf("%d",&choice);
  }
}
