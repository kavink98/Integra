#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
/*Verifies name and returns 0 if there are no intergers present and 1 if there is an error*/
int verifyName(char *name)
{
  int flag;
  for(int i=0;name[i]!='\0';i++)
  {
    if(isalpha(name[i])==0&&name[i]!=32)
    {
      printf("Enter a valid name\n");
      flag = 1;
      break;
    }
    else
    flag = 0;
  }
  return flag;
}

/*Verifies phone number and returns 1 if there is an Error
*Error occurs if
                1)There is a letter in the number
                2)If there arent 10 digits in the numbers
                3)If the first 5 digit of the number are lesser than 5

*/
int verifyPhone(char *phone)
{
  int flag;
  for(int i=0;i<strlen(phone);i++)
  {
    if(isdigit(phone[i])==0)
    {
      flag = 1;
      break;
    }
    else
    flag = 0;
  }
  if(phone[0]-'0'<5)
  {
    flag = 1;
  }
  if(strlen(phone)!=10)
  {
    flag = 1;
  }
  if(flag == 1)
  printf("Enter Valid number\n");
  return flag;

}

/*Verifies date and returns 1 if there is an Error*/
int verifyDate(char *dd,char *mm,char *yy)
{
  int flag;
  time_t t = time(NULL);
  struct tm *ti = localtime(&t);
  if(atoi(dd)>31||atoi(dd)<1)
  {
    flag = 1;
    printf("Enter valid DOB\n");
  }
  else if(atoi(mm)>12||atoi(mm)<0)
  {
    flag = 1;
    printf("Enter valid DOB\n");
  }
  else if(atoi(yy)>(ti->tm_year+1900))
  {
    flag = 1;
    printf("Enter valid DOB\n");
  }
  else if(atoi(yy)==(ti->tm_year+1900))
  {
      if(atoi(mm)>ti->tm_mon)
      {
        flag = 1;
        printf("Enter valid DOB\n");

      }
      else if(atoi(mm)>ti->tm_mon)
      {
          if(atoi(dd)>ti->tm_mday)
          flag = 1;
          printf("Enter valid DOB\n");
      }
  }
  else
  flag = 0;
  return flag;
}
/*Verifies income and returns 1 if there is and error(charecter present)*/
int verifyIncome(char *income)
{
  int flag;
  for(int i=0;i<strlen(income);i++)
  {
    if(isdigit(income[i])==0)
    {
      printf("Enter valid input\n");
      flag = 1 ;
      break;
    }
    else
    flag = 0;
  }
  return flag;
}
int verifyAadhaar(const char* const str)
{
      const int d[10][10] =
      {
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
      { 1, 2, 3, 4, 0, 6, 7, 8, 9, 5 },
      { 2, 3, 4, 0, 1, 7, 8, 9, 5, 6 },
      { 3, 4, 0, 1, 2, 8, 9, 5, 6, 7 },
      { 4, 0, 1, 2, 3, 9, 5, 6, 7, 8 },
      { 5, 9, 8, 7, 6, 0, 4, 3, 2, 1 },
      { 6, 5, 9, 8, 7, 1, 0, 4, 3, 2 },
      { 7, 6, 5, 9, 8, 2, 1, 0, 4, 3 },
      { 8, 7, 6, 5, 9, 3, 2, 1, 0, 4 },
      { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }
    };
    const int p[8][10] =
    {
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
      { 1, 5, 7, 6, 2, 8, 3, 0, 9, 4 },
      { 5, 8, 0, 3, 7, 9, 6, 1, 4, 2 },
      { 8, 9, 1, 6, 0, 4, 3, 5, 2, 7 },
      { 9, 4, 5, 3, 1, 2, 6, 8, 7, 0 },
      { 4, 2, 8, 6, 5, 7, 3, 9, 0, 1 },
      { 2, 7, 9, 3, 8, 0, 6, 4, 1, 5 },
      { 7, 0, 4, 6, 9, 1, 3, 2, 5, 8 }
    };
    int c = 0, i = 0, len = 0;
    len = strlen(str);
    while (len--)
    c = d[c][p[i++ % 8][str[len] - '0']];
    if(c != 0 )
      printf("Enter a valid Aadhar Number \n");
    return (c == 0);

}
 
