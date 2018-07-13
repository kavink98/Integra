#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "verification.h"
#include "io.h"

void main()
{
	FILE *fp;
	printf("What do you want to do\n1.Input\n2.read file\n3.Search\n4.Mdify\n5.Exit\n");
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
		modify(&emp,fp);

		else if(choice == 5)
    {
        findLines(fp);
        break;
    }
    else
    printf("ENter Valid Input\n");

    printf("What do you want to do\n1.Input\n2.read file\n3.Search\n4.Mdify\n5.Exit\n");
		scanf("%d",&choice);
  }
}
