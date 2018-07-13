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

int findLines(FILE *fp)
{
    fp = fopen("emp.dat","r");
    fseek(fp,0,SEEK_END);
		int numlines = (int)(ftell(fp)/200);
    printf("No. of lines:%d\n\n",numlines);
    fclose(fp);
		return numlines;
}

void input(struct employee *emp,FILE *fp)
{
	int n,marital,err;
    char buf=' ';
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
	fprintf(fp,"%s|",emp->name );

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
	scanf("%d",&marital);
	if(marital==1)
	strcpy(emp->m_status,"Single");
	else if(marital==2)
	strcpy(emp->m_status,"Married");
	else if(marital==3)
	strcpy(emp->m_status,"Divorced");
  else
  strcpy(emp->m_status,"NA");

  fprintf(fp,"%s|",emp->m_status );

	do//INputting annual income
	{
		printf("Annual Income\n");
		scanf("%s",(emp->income));
	}while(verifyincome(emp->income));
	fprintf(fp,"%s|",emp->income );

    while((n=(ftell(fp)%200))!=199)
    {
        fprintf(fp,"%c",buf);
    }

	fprintf(fp,"\n");
	printf("Written Succesfully %ld bytes\n",ftell(fp));
	fclose(fp);
}

void read(struct employee *emp,FILE *fp)
{

	int numlines = findLines(fp);
	fp = fopen("emp.dat","r");//Opening file in read mode

	if (fp==NULL)
	{
		fprintf(stderr,"\nError opend file\n");
		exit(1);
	}
	int c;
	for(int i=0;i<numlines;i++)
	{
		fseek(fp,i*200,SEEK_SET);
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

void search(struct employee *emp,FILE *fp)
{
  int numlines = findLines(fp);
  char entry[25];
	fp = fopen("emp.dat","r");//Opening file in read mode

	if (fp==NULL)
	{
		fprintf(stderr,"\nError opend file\n");
		exit(1);
	}
  int found = 0;
  printf("Enter name or phone number or aadhar number \n\n");
  getchar();
  scanf("%[^\n]s",entry);
  int c;

  for(int i=0;i<numlines;i++)
	{
		fseek(fp,(i*200),SEEK_SET);
		fscanf(fp,"%[^|]|s",emp->name);

		fscanf(fp,"%[^|]|s",emp->phone);

		fscanf(fp,"%[^|]|s",emp->aadhar);

		fscanf(fp,"%[^|]|s",emp->dob.dd);
		fscanf(fp,"%[^|]|s",emp->dob.mm);
		fscanf(fp,"%[^|]|s",emp->dob.yy);

		fscanf(fp,"%[^|]|s",emp->address);

		fscanf(fp,"%[^|]|s",emp->occupation);

		fscanf(fp,"%[^|]|s",emp->m_status);

		fscanf(fp,"%[^|]|s",emp->income);

    if(strcmp(emp->name,entry)==0||strcmp(emp->phone,entry)==0||strcmp(emp->aadhar,entry)==0)
    {
        printf("Record Found,entry number %d \n\n",i );
        printf("Name:%s\n",emp->name);
        printf("Phone Number:%s\n",emp->phone);
        printf("Aadhar Number:%s\n",emp->aadhar);
        printf("DOB:%s/%s/%s\n",emp->dob.dd,emp->dob.mm,emp->dob.yy);
        printf("Address:%s\n",emp->address);
        printf("Occupation:%s\n",emp->occupation);
        printf("Marital Status:%s\n",emp->m_status);
        printf("Income:%s\n\n",emp->income);
        found = 1;
    }

		c = fgetc(fp);
	}
  if(found == 0)
  printf("Record not found\n");
	fclose(fp);
}
