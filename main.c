#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "verification.h"
#include "common.h"

void main()
{
    int choice;
	struct employee emp;
	while(1)
	{
        printf("What do you want to do\n1.Input\n2.Read file\n3.Search\n4.Modify\n5.Exit\n");
        scanf("%d",&choice);
        
        if(choice==1)
            input(&emp);

        else if (choice == 2)
             read(&emp);

        else if(choice == 3)
            search(&emp);

        else if(choice == 4)
            modify(&emp);

        else if(choice == 5)
        {
            findLines();
            break;
        }
        else
            printf("ENter Valid Input\n");

    }
}
