// Copyright (C) 2013 Jai Luthra <me@jailuthra.in> 

#include<stdio.h>
#include<stdlib.h>

int arr[10];
int top = -1;

void menu();
void push(int x);
void showStack();
void pop(); 

int main() {
	menu();
	return 0;
}

void menu() {
	
	int option, input;
	
	printf("\n1. Push\n2. Pop\n3. Show Stack\n4. Exit\n\n");
	scanf("%d", &option);
	
	switch (option) {
		case 1: printf("\n\nInput: ");
			scanf("%d", &input);
			push(input);
			break;
		case 2: pop();
			break;
		case 3: showStack();	
			break;
		case 4: exit(0);
		default: printf("\nError: Please enter a valid option.\n");
	}

}

void push(int x) {	
	top++;
	if (top>=10) printf("\n\nStack Overflow!!!");
	else arr[top]=x;
	menu();
}

void showStack() {
	int a = top;
	if (a==-1) fprintf(stderr, "\n\nError: Stack Underflow");
	else 
	{
		printf("\n\nStack Is:\n");
		for (a; a>=0; a--) 
		  printf("%d\n",arr[a]);
		menu();
	}
}


void pop() {
	printf("\n\nPopped: %d\n",arr[top]);
	top--;
	menu();
}

