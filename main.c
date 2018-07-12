#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "verification.h"

struct employee
{
	char name[25],address[50],phone[11],email[25],occupation[15],aadhar[13],birthplace[15],m_status[10],income[10];
	int code;
	struct date
	{
		char dd[3],mm[3],yy[5];
	} dob;
};//Declaring structure

void input(struct employee *emp,FILE *fp)
{
	int flag,a,err;
  fp = fopen("emp.dat","a");
	if (fp==NULL)
		{
			fprintf(stderr,"\nError opend file\n");//Opening file in write and append mode
			exit(1);
    }

	printf("Enter the following details\n");

	do//Inputting name
	{
		printf("Name\n");
		getchar();
		scanf("%[^\n]s",emp->name);
	}while(verifyname(emp->name));
	fprintf(fp," %s|",emp->name );

	do//Inputting phone number
	{
		printf("Phone No.\n");
  	scanf("%s",emp->phone);
	}while(verifyphone(emp->phone));
	fprintf(fp,"%s|",emp->phone );

	printf("Aadhar no.\n");//INputting Aadhar Number
  scanf("%s",emp->aadhar);
	fprintf(fp,"%s|",emp->aadhar );

	do
	{
		printf("Date of Birth in DD MM YYYY format\n");//INputting dob
		scanf("%s%s%s",emp->dob.dd,emp->dob.mm,emp->dob.yy);
	}while(verifydate(emp->dob.dd,emp->dob.mm,emp->dob.yy));
	fprintf(fp,"%s|%s|%s|",(emp->dob.dd),(emp->dob.mm),(emp->dob.yy));

	getchar();
  printf("Address \n");//Inputting address
  scanf("%[^\n]s",emp->address);
	fprintf(fp,"%s|",emp->address );

	getchar();
	printf("Occupation \n");//Inputting occupation
  scanf("%[^\n]s",emp->occupation);
	fprintf(fp,"%s|",emp->occupation );

	printf("Marital status\n1.Single\n2.Married\n3.Divorced\n");//Inputting Marital status
	scanf("%d",&a );
	if(a==1)
	strcpy(emp->m_status,"Single");
	else if(a==2)
	strcpy(emp->m_status,"Married");
	else if(a==3)
	strcpy(emp->m_status,"Divorced");
	fprintf(fp,"%s|",emp->m_status );

	do//INputting annual income
	{
		printf("Annual Income\n");
		scanf("%s",(emp->income));
	}while(verifyincome(emp->income));
	fprintf(fp,"%s|",emp->income );

	fprintf(fp,"\n");
	printf("Written Succesfully\n");
	fclose(fp);
}


void read(struct employee *emp,FILE *fp)
{

	fp = fopen("emp.dat","r");//Opening file in read mode

	if (fp==NULL)
	{
		fprintf(stderr,"\nError opend file\n");
		exit(1);
	}
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		fscanf(fp,"%[^|]|s",emp->name);
		printf("Name:%s\n",emp->name);

		fscanf(fp,"%[^|]|s",emp->phone);
		printf("Phone no:%s\n",emp->phone);

		fscanf(fp,"%[^|]|s",emp->aadhar);
		printf("Aadhar no:%s\n",emp->aadhar);

		fscanf(fp,"%[^|]|s",emp->dob.dd);
		fscanf(fp,"%[^|]|s",emp->dob.mm);
		fscanf(fp,"%[^|]|s",emp->dob.yy);
		printf("DOB:%s/%s/%s\n",emp->dob.dd,emp->dob.mm,emp->dob.yy);

		fscanf(fp,"%[^|]|s",emp->address);
		printf("Address:%s\n",emp->address);

		fscanf(fp,"%[^|]|s",emp->occupation);
		printf("Occupation:%s\n",emp->occupation);

		fscanf(fp,"%[^|]|s",emp->m_status);
		printf("Marital status:%s\n",emp->m_status);

		fscanf(fp,"%[^|]|s",emp->income);
		printf("Income:%s\n",emp->income);

		printf("\n");
		c = fgetc(fp);
	}

	fclose(fp);
}
void main()
{
	FILE *fp;
	printf("Enter 1 for input and 2 for read\n");
	int choice;
	scanf("%d",&choice);
	struct employee emp;
	while(choice==1)
	{
		input(&emp,fp);
		printf("Do you want to continue inputting\n1.Continue\n2.read file\n3.Exit\n");
		scanf("%d",&choice);
	}

	if (choice == 2)
	{
		read(&emp,fp);
	}

	else
		exit(0);
}
