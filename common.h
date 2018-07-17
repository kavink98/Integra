#define FILE_NAME "/home/kavin/Integra/emp.dat"

FILE *fp;

struct employee
{
	char name[25],address[50],phone[11],email[25],occupation[15],aadhar[13],birthplace[15],m_status[10],income[10];
	int code;
	struct date
	{
		char dd[3],mm[3],yy[5];
	} dob;
};

int findLines();
void input(struct employee *emp);
void read(struct employee *emp);
void search(struct employee *emp);
void modify(struct employee *emp);
