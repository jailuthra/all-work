#include<stdio.h>
#include<time.h>
#include<stdlib.h>

genrand()
{
	srand(time(NULL));
	int i=0;
	int sum=0;
	for (i; i<1000; i++)
	{
		int r = rand() % 9;
		//sleep(1);
		printf("%d\n",r);
		sum += r;
	}
	double avrg;
	avrg = sum/1000.00000;
	printf("The Average Of the Random Nos. is: %f\n",avrg);

}


main() {
	genrand();
}
