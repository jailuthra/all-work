#include <stdio.h>

int main(char argc, char *argv[])
{
  long long a=1; 
  long i= atoi(argv[1]);
  
  while (i>=1) 
    {
      a=a*i;
      i--;
    }

  printf("%d\n",a);
  return 0;
}
  
