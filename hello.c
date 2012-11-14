#include<stdio.h>
#include<stdlib.h>

int main() {
	system("clear");
	char name;
	printf("Type your name: ");
	scanf("%s",&name);
	printf("Hello! %s\n",&name);
	getchar();
	return 0;
}
