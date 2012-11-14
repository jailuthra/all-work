#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c;
	printf("Type a number: ");
	scanf("%d",&a);

	b=(a>>1);
	c=(a<<1);

	printf("\nNumber/2 is %d\n",b);
	printf("Number*2 is %d\n",c);
}
