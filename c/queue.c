/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct node {
	void * data;
	struct node* next;
};
// Two glboal variables to store address of front and rear nodes. 
struct node* front = NULL;
struct node* rear = NULL;

// To Enqueue an integer
void Enqueue(void * x) {
	struct node* temp = 
		(struct node*)malloc(sizeof(struct node));
	temp->data =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct node* temp = front;
	if(front == NULL) {
        /*printf("Queue is Empty\n");*/
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

void * Front() {
	if(front == NULL) {
		//printf("Queue is empty\n");
		return NULL;
	}
	return front->data;
}

/*void Print() {
	struct node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}*/
/*
int main(){
	[> Drive code to test the implementation. <]
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}*/
