#include<stdio.h>
#include<stdlib.h>

int main (int argc, char* argv[]) {
	printf("Hello %s!\n",argv[1] ? argv[1] : "World");
    return 0;
}

