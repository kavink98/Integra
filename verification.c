#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int verifyname(char *name)
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
int verifyphone(char *phone)
{
  int flag;
  for(int i=0;i<strlen(phone);i++)
  {
    if(isalpha(phone[i])!=0)
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

int verifydate(char *dd,char *mm,char *yy)
{
  int flag;
  time_t t = time(NULL);
  struct tm *ti = localtime(&t);
  if(atoi(dd)>31||atoi(dd)<1)
  {
    flag = 1;
    printf("enter valid dob\n");
  }
  else if(atoi(mm)>12||atoi(mm)<0)
  {
    flag = 1;
    printf("enter valid dob\n");
  }
  else if(atoi(yy)>(ti->tm_year+1900))
  {
    flag = 1;
    printf("enter valid dob\n");
  }
  else
  flag = 0;
  return flag;
}

int verifyincome(char *income)
{
  int flag;
  for(int i=0;i<strlen(income);i++)
  {
    if(isalpha(income[i])!=0)
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
