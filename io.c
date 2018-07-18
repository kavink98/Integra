#include "verification.h"
#include "common.h"

void readLine(struct employee *emp)
{
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
}

void displayLine(struct employee *emp)
{
        printf("Name:%s\n",emp->name);
        printf("Phone no:%s\n",emp->phone);
        printf("Aadhar no:%s\n",emp->aadhar);
		printf("DOB:%s/%s/%s\n",emp->dob.dd,emp->dob.mm,emp->dob.yy);
		printf("Address:%s\n",emp->address);
		printf("Occupation:%s\n",emp->occupation);
		printf("Marital status:%s\n",emp->m_status);
		printf("Income:%s\n",emp->income);
		printf("\n");
}

int findLines()
{
    fp = fopen(FILE_NAME,"r");
    fseek(fp,0,SEEK_END);
    int numlines = (int)(ftell(fp)/200);
    printf("No. of lines:%d\n\n",numlines);
    fclose(fp);
    return numlines;
}

void input(struct employee *emp)
{
	int n,marital,err;

    fp = fopen(FILE_NAME,"a");
	printf("Enter the following details\n");

	do//Inputting name
	{
		printf("Name\n");
		getchar();
		scanf("%[^\n]s",emp->name);
	}while(verifyName(emp->name));

	do//Inputting phone number
	{
		printf("Phone No.\n");
        scanf("%s",emp->phone);
	}while(verifyPhone(emp->phone));

	printf("Aadhar no.\n");//INputting Aadhar Number
    scanf("%s",emp->aadhar);

	do
	{
		printf("Date of Birth in DD MM YYYY format\n");//INputting dob
		scanf("%s%s%s",emp->dob.dd,emp->dob.mm,emp->dob.yy);
	}while(verifyDate(emp->dob.dd,emp->dob.mm,emp->dob.yy));

	getchar();
    printf("Address \n");//Inputting address
    scanf("%[^\n]s",emp->address);

	getchar();
	printf("Occupation \n");//Inputting occupation
    scanf("%[^\n]s",emp->occupation);

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


	do//INputting annual income
	{
		printf("Annual Income\n");
		scanf("%s",(emp->income));
	}while(verifyIncome(emp->income));

    write(emp);

    fclose(fp);

}

void write(struct employee *emp)
{
    char buf=' ';
    int n;
	if (fp==NULL)
    {
			fprintf(stderr,"\nError opend file\n");//Opening file in write and append mode
			exit(1);
    }
    printf("%ld",ftell(fp));
    fprintf(fp,"%s|",emp->name );
    fprintf(fp,"%s|",emp->phone );
    fprintf(fp,"%s|",emp->aadhar );
	fprintf(fp,"%s|%s|%s|",(emp->dob.dd),(emp->dob.mm),(emp->dob.yy));
	fprintf(fp,"%s|",emp->address );
	fprintf(fp,"%s|",emp->occupation );
    fprintf(fp,"%s|",emp->m_status );
	fprintf(fp,"%s|",emp->income );
    while((n=(ftell(fp)%200))!=199)
    {
        fprintf(fp,"%c",buf);
    }

	fprintf(fp,"\n");
	//printf("Written Succesfully %ld bytes\n",ftell(fp));

}

void read(struct employee *emp)
{

	int numlines = findLines(fp);
	fp = fopen(FILE_NAME,"r");//Opening file in read mode

	if (fp==NULL)
	{
		fprintf(stderr,"\nError opening file\n");
		exit(1);
	}
	int c;
	for(int i=0;i<numlines;i++)
	{
		printf("Record number %d:\n",i+1);
		fseek(fp,i*200,SEEK_SET);
        readLine(emp);
        displayLine(emp);
		c = fgetc(fp);
	}

	fclose(fp);
}

void search(struct employee *emp)
{
    char entry[25],name[25],aadhar[12],phone[11];
	int numLines ;

    numLines = findLines(fp);
	fp = fopen(FILE_NAME,"r");//Opening file in read mode

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

    for(int i=0;i<numLines;i++)
    {
        fseek(fp,(i*200),SEEK_SET);
        fscanf(fp,"%[^|]|s",name);

        fscanf(fp,"%[^|]|s",phone);

        fscanf(fp,"%[^|]|s",aadhar);

        if(strcmp(name,entry)==0||strcmp(phone,entry)==0||strcmp(aadhar,entry)==0)
        {
            found=1;
            fseek(fp,i*200,SEEK_SET);
            readLine(emp);
            displayLine(emp);

        }
        else
            found=0;

        c = fgetc(fp);
    }

    if(found == 0)
        printf("Record not found\n");
    fclose(fp);
}

void modify(struct employee *emp)
{
    read(emp);
	int n,marital,rec,entry;
    char buf=' ';
    fp = fopen(FILE_NAME,"r+");
	if (fp==NULL)
		{
			fprintf(stderr,"\nError opend file\n");
			exit(1);
    }

	printf("enter record to be modified\n");
	scanf("%d",&rec);
	fseek(fp,(--rec)*200,SEEK_SET);
    readLine(emp);
    displayLine(emp);

	printf("What do you want to modify\n1.Name\n2.Phone\n3.Aadhar\n4.DOb\n5.Address\n.6.Occupation\n7.Marital Status\n8.Income\n");
	scanf("%d",&entry);

	printf("Enter the following details\n");


	if(entry ==1)
	{
		do//Inputting name
		{
			printf("Name\n");
			getchar();
			scanf("%[^\n]s",emp->name);
		}while(verifyName(emp->name));
	}

	else if(entry == 2)
	{
		do//Inputting phone number
		{
			printf("Phone No.\n");
            scanf("%s",emp->phone);
		}while(verifyPhone(emp->phone));
	}

	else if(entry == 3)
	{
		printf("Aadhar no.\n");//INputting Aadhar Number
        scanf("%s",emp->aadhar);
	}

	else if(entry == 4)
	{
		do
		{
			printf("Date of Birth in DD MM YYYY format\n");//INputting dob
			scanf("%s%s%s",emp->dob.dd,emp->dob.mm,emp->dob.yy);
		}while(verifyDate(emp->dob.dd,emp->dob.mm,emp->dob.yy));
	}

	else if(entry == 5)
	{
		getchar();
        printf("Address \n");//Inputting address
        scanf("%[^\n]s",emp->address);
	}

	else if(entry == 6)
	{
		getchar();
		printf("Occupation \n");//Inputting occupation
        scanf("%[^\n]s",emp->occupation);
	}

	else if(entry == 7)
	{
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
	}

	else if(entry == 8)
	{
		do//INputting annual income
		{
			printf("Annual Income\n");
			scanf("%s",(emp->income));
		}while(verifyIncome(emp->income));
	}
	fseek(fp,(rec*200),SEEK_SET);
    write(emp);

	fclose(fp);
}

void sort(struct employee* emp)
{
    int numLines,choice;
    struct employee *curr;
    numLines = findLines();
    fp = fopen("emp.dat","r+");//Opening file in read mode

    if (fp==NULL)
	{
		fprintf(stderr,"\nError opening file\n");
		exit(1);
	}
  init();
	for(int i=0;i<numLines;i++)
	{
		fseek(fp,i*200,SEEK_SET);

        readLine(emp);
        push(emp);
        fgetc(fp);
  }
  printf("1.Sort by phone\n" );
  printf("2.Sort by name\n" );
  scanf("%d",&choice);
    if(choice == 1)
    {
      printf("Sorting by Phone\n");
      bubbleSort();
      curr = head;

      fseek(fp,0,SEEK_SET);
      do
      {

          write(curr);
          curr = curr->next;
      }while (curr!=NULL);
    }
    else if(choice == 2)
    {
      printf("Sorting by name\n");
      bubbleSortName();
      curr = head;

      fseek(fp,0,SEEK_SET);
      do
      {

          write(curr);
          curr = curr->next;
      }while (curr!=NULL);
    }
  freeList();
	fclose(fp);

}
