/**
* program to create linked list and enter data..
*
**/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef node *NODEPTR;
NODEPTR start;

NODEPTR getNode();
void print(NODEPTR);
void insert_first();
void insert_last();
void insert_kth_position();
void delete_first();
int length();

int main(){
	NODEPTR p, t, tmp;
	char ch ;
	int choice, nodeCount;
	
	if(start == NULL){
		start = getNode();
		printf("Enter first element : ");
		scanf("%d",&start->data);
		start->next = NULL;
		p=start;
	}
	
	printf("\nDo you want more nodes (y or n): ");
	scanf(" %c", &ch);
	
	while(ch=='y'||ch=='Y'){
		t=getNode();
		printf("\nEnter data in node : ");
		scanf("%d",&t->data);
		t->next = NULL;
		p->next = t;
		p=p->next;
		printf("\nDo you want more nodes (y or n): ");
		scanf(" %c", &ch);
	}
	
	// printing node..
	print(start);
	printf("\n\n");
	printf("\nSelect option which you want to perform in Linked-List :");
	printf("\n");
	printf("\n1. length of Linked-List.");
	printf("\n2. Insert node in first position in Linked-List.");
	printf("\n3. Insert node in last position in Linked-List,");
	printf("\n4. Insert node in Kth position in Linked-List,");
	printf("\n\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: nodeCount = length();
				printf("\nlength of linked-list is : %d ",nodeCount);
				break;
		case 2: insert_first();
				print(start);
				printf("\n");
				break;
		case 3: insert_last();
				print(start);
				printf("\n");
				break;
		case 4: insert_kth_position();
				print(start);
				printf("\n");
				break;
	}
}

// counting the node..

int length(){
	NODEPTR t;
	int c=0;
	t= start;
	while(t!=NULL){
		c++;
		t=t->next;
	}
	return c;
}

// for getting node..

NODEPTR getNode(){
	NODEPTR q;
	q=(NODEPTR)malloc(sizeof(NODEPTR));
	return q;
}

// for printing..

void print(NODEPTR ptr){
	NODEPTR tmp = ptr;
	while(tmp!=NULL){
		printf("\nElement is : %d", tmp->data);
		tmp = tmp->next;
	}
}

// insert at first position..

void insert_first(){
	NODEPTR t;
	t=getNode();
	printf("\nEnter data in node : ");
	scanf("%d",&t->data);
	t->next = start;
	start = t;
}

// insert at last position..

void insert_last(){
	NODEPTR t, q;
	q=start;
	t=getNode();
	printf("\nEnter data to insert in last : ");
	scanf("%d",&t->data);
	t->next = NULL;
	
	while(q->next != NULL)
		q = q->next;
		
	q->next = t;
}
// inserting Kth position..

void insert_kth_position(){
	NODEPTR p, q, t;
	int cnt, k;
	
	printf("\nEnter Kth positon : ");
	scanf("%d",&k);
	
	cnt = length();
	p = start;
	
	if (k > cnt+1){
		printf("\nYour k value is large to linked-list.");
		printf("\nlinked-list length : %d", cnt);
		exit(0);
	}else if(k==1)
		insert_first();
	else{
		t = getNode();
		printf("\nEnter data in node : ");
		scanf("%d",&t->data);
		p = start;
		q=p;
		
		while(k > 1){
			q=p;
			p = p->next;
			k--;
		}
		q->next = t;
		t->next = p;
	}
		
}

