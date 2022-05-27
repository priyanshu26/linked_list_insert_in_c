/**
* program to insert only one node and only one data.
*
*
**/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR start;
NODEPTR getNode();
void print(NODEPTR);

int main(){
	NODEPTR tmp;
	tmp = getNode();
	printf("Enter The data : ");
	scanf("%d", &tmp->data);
	tmp->next = NULL;
	start = tmp;
	print(start);
}

// node getting funtion..

NODEPTR getNode(){
	NODEPTR t;
	t=(NODEPTR)malloc(sizeof(NODEPTR));
	return t;
}

// print function..

void print(NODEPTR ptr){
	NODEPTR temp = ptr;
	while(temp != NULL){
		printf("\nThe data is in linked-list : %d", temp->data);
		temp = temp->next;
	}
}
