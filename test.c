#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  struct x
  {
    int z,y;
  };

  struct x a,b;
  a.z = 10;
  a.y = 11;
  b = a ;
  printf("%d\n%d\n",b.z,b.y);

  }
