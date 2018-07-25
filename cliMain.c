#include "verification.h"
#include "common.h"

/*************************************************************************************************************************
	Read the input:
		print the user choices.
			The choices are:
				1 to enter new employee data
				2 list the the data of employees found in db
				3 Serch the db based on given input
				4 modifiy the specifed record
				5 sort employee records based on given field
				6 delete the specified record
				7 exit the program.
*************************************************************************************************************************/

void main()
{
	char ch;
	struct employee emp;

	while(1)
	{
		printf("\nWhat do you want to do\n1.Input\n2.Read file\n3.Search\n4.Modify\n5.Sort\n6.Delete\n7.Exit\n");
		scanf("%c",&ch);

		switch (ch)
		{
			case '1': 
				input(&emp) ;
				break ;

        
			case '2': 
				read(&emp);
				break ;

			case '3': 
				search(&emp);
				break ;

			case '4': 
				modify(&emp);
				break ;

			case '5': 
				sort(&emp);
				break ;

			case '6': 
				deleteRec(&emp);
				break ;

			case '7': 
				findLines();
				exit(0);
				break ;
			default : 
				printf("Enter Valid Input\n");
				break ;
		}
		getchar();
    }
}
