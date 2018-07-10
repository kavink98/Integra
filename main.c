#include <stdio.h>
#include <stdlib.h>

enum marital{Single, Married, Divorced};

struct employee
{
	char name[25],address[50],phone[9],email[25],occupation[15],aadhar[11],birthplace[15];
	int code;
	//enum marital m_status;
	struct date
	{
		int dd,mm,yy;
	} dob;
};

void input(struct employee *emp,FILE *fp)
{
	int flag;
    
   	fp = fopen("emp.dat","a");
	
    	if (fp==NULL)
    	{
		fprintf(stderr,"\nError opend file\n");
		exit(1);
    	}

    	printf("Enter the following details\n");
    
    	printf("Name\n");
    	scanf("%s",emp->name);
    
    	printf("Phone No.\n");
    	scanf("%s",emp->phone);
    
    	printf("Aadhar no.\n");
    	scanf("%s",emp->aadhar);
    
    	printf("Address \n");
    	scanf("%s",emp->address);
    
    	printf("Occupation \n");
    	scanf("%s",emp->occupation);
    
    	printf("Date of Birth in DD MM YYYY format\n");
	scanf("%d%d%d",&(emp->dob.dd),&(emp->dob.mm),&(emp->dob.yy));
    
/*
    	printf("Marital Status\n");
    	printf("\t1.Single\n\t2.Married\n\t3.Divorced");
    	scanf("%d",&(emp->m_status));
*/    
    	flag = fwrite(emp,sizeof(struct employee),1,fp);
    
    	if (flag != 0)
        printf("Written Successfully");
    	else
        printf("Error/n");
    	fclose(fp);    
}
	

void read(struct employee *emp,FILE *fp)
{
	fp = fopen("emp.dat","r");
	
	if (fp==NULL)
	{
		fprintf(stderr,"\nError opend file\n");
		exit(1);
	}	
	while(fread(emp,sizeof(struct employee),1,fp))
	{ 
		printf("Name:%s \n",emp->name);
		printf("Phone number:%s \n",emp->phone);
		printf("Aadhar no:%s \n",emp->aadhar);
		printf("Address:%s \n",emp->address);
		printf("Occupation:%s \n",emp->occupation);
		//printf("%sMarital status: \n",emp->m_status);
	}
	
	fclose(fp);
}
void main()
{	/*
	FILE *fp;
	printf("Enter 1 for input and 2 for read\n");
	int choice;
	scanf("%d",&choice);
	//struct employee *emp;
	struct employee emp;
	while(choice==1)
	{		
		input(&emp,fp);
		printf("Do you want to continue inputting");
		scanf("%d",&choice);
	}
	
	if (choice == 2)
	{ 	
		read(emp,fp);
	}
	
	else 
		exit(0);
	*/
	FILE *fp;
	struct employee *emp;
	input(emp,fp);
	read(emp,fp);
}	

