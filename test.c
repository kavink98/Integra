#include<stdio.h>

void main()
{
  char str1[20];
  printf("Enter \n");
  scanf("%[^\n]s",str1);
  printf("%s",str1);
}
