#include<stdio.h>
#include<stdlib.h>

int arr[10];
int top = -1;


void menu() {
	
	int option,input;
	
	printf("\n\n1. Push\n2. Pop\n3. Show Stack\n4. Exit\n\n");
	scanf("%d",&option);
	
	switch(option) {
		case 1: printf("Input: ");
			scanf("%d",&input);
			push(input);
			break;
		case 2: pop();
			break;
		case 3: showStack();	
			break;
		case 4: exit(0);
		default: printf("\nError: Wrong Option\n");
	}

}




int push(int x) {	
	top++;
	if (top>=10) printf("\n\nStack Overflow!!!");
	else arr[top]=x;
	menu();
}

int showStack() {
	int a=top;
	if (a==-1) printf("\n\nError: Stack Underflow");	
	else 
	{
		printf("\n\nStack Is:\n");
		for(a;a>=0;a--) 
		{printf("%d\n",arr[a]);}
		printf("\n");
		menu();
	}
}


int pop() {
	printf("\n\nPopped: %d",arr[top]);
	top--;
	menu();
}


int main() {
	system("clear");
	menu();
	return 0;
}
	

