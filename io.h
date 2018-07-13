struct employee
{
	char name[25],address[50],phone[11],email[25],occupation[15],aadhar[13],birthplace[15],m_status[10],income[10];
	int code;
	struct date
	{
		char dd[3],mm[3],yy[5];
	} dob;
};

int findLines(FILE *fp);
void input(struct employee *emp,FILE *fp);
void read(struct employee *emp,FILE *fp);
void search(struct employee *emp,FILE *fp);
void modify(struct employee *emp,FILE *fp);
