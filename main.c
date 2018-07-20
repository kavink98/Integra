#include "verification.h"
#include "common.h"

void main()
{
  char ch;
	struct employee emp;
	while(1)
	{
        printf("\nWhat do you want to do\n1.Input\n2.Read file\n3.Search\n4.Modify\n5.Sort\n6.Delete\n7.Exit\n");
        scanf("%c",&ch);

        if(ch == '1')
            input(&emp);

        else if (ch == '2')
             read(&emp);

        else if(ch == '3')
            search(&emp);

        else if(ch == '4')
            modify(&emp);

        else if(ch == '5')
  			    sort(&emp);

        else if(ch == '6')
            deleteRec(&emp);

        else if(ch == '7')
        {
            findLines();
            break;
        }

        else
            printf("Enter Valid Input\n");
        ch = '\0';
        getchar();

    }
}
