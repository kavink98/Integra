void input(struct employee *emp,FILE *fp)
{
    int flag;
    
	fp = fopen("emp.dat","w");
	
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
    
    printf("Date of Birth in DD MM YY format\n");
    scanf("%d%d%%d",emp->dob.&dd,emp->&dob.&mm,emp->dob.&yy);
    
    printf("Marital Status\n");
    printf("\t1.Single\n\t2.Married\n\t3.Divorced");
    scanf("%d",emp->&m_status);
    
    flag = fwrite(emp,sizeof(struct employee),1,fp);
    
    if (flag != 0)
        printf("Written Successfully");
    else
        printf("Error/n");
    
}
	
