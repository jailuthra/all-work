#include<stdio.h>
#include<time.h>
#include<stdlib.h>

genrand()
{
	srand(time(NULL));
	int i=0;
	int sum=0;
	for (i; i<180; i++)
	{
		int r = rand() % 20;
		sleep(1);
		//printf("%d\n",r);
		sum += r;
	}
	double avrg;
	avrg = sum/180.000;
	printf("The Average Of the Random Nos. is: %f\n\n",avrg);

}


main() {
	genrand();
}
