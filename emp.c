#include<stdio.h>

enum marital{Single, Married, Divorced};

struct employee
{
	char name[25],address[50],phone[9],email[25],occupation[15],aadhar[11],birthplace[15];
	int code;
	marital m_status;
	struct date
	{
		int dd,mm,yy;
	} dob;
};


