#include<stdio.h>

int main()
{
  float balance;
  const float bankcharge=0.50;
  int withdraw;

  scanf("%d %f", &withdraw, &balance);
 
  if ( ((withdraw % 5) == 0) && ((withdraw+bankcharge) < balance) )
    balance = balance - (withdraw+bankcharge);

  printf("%0.2f\n", balance); 

  return 0;

}
