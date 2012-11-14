#include<stdio.h>
#include<stdlib.h>

int main() {
	system("clear");
	int i, n, step;
	double cel, fahr;
	
	printf("Please give in a lower limit, limit >= 0: ");
	scanf("%d",&i);
	
	printf("Please give in a higher limit, 10 > limit <= 50000: ");
	scanf("%d",&n);
	
	printf("Please give in a step, 0 < step <= 10: ");
	scanf("%d",&step);

	cel=i;
	
	printf("\nCelsius\t\tFahrenheit");
	printf("\n-------\t\t----------\n");
	
	for (cel; cel<=n; cel+=step) 
	{	
		fahr=((cel*9.0)/5.0)+32.0;
		printf("%f\t%f\n",cel,fahr);
	}
	getchar();
}	
