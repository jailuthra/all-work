#include<stdio.h>

int main(char argc, char *argv[])
{
  double a=1; 
  double i=atoi(argv[1]);
  
  while (i>=1) 
    {
      a=a*i;
      i--;
    }

  printf("%f\n",a);
  return 0;
}
  
