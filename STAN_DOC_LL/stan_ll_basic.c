#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_tt{
	int val;
	struct node_tt* next;
}node_t;



node_t* makenode(int val)
{
	node_t* curr = (node_t*)malloc(sizeof(node_t));
	assert(curr);
	curr->val = val;
	curr->next = NULL;
	return curr;
}

void addnode(node_t **head, int val)
{
	node_t* curr = *head;
	if(!curr){
		curr = makenode(val);
		*head = curr;
		return;
	}
	while(curr->next)
		curr=curr->next;	
	curr->next = makenode(val);
}


void printlist(node_t* head)
{
	if(!head){
		printf("sorry list is empty.\n");
		return;
	}
	while(head){
		printf("%d\t", head->val);
		head= head->next;
	}
	return;
}

int findlength(node_t* head)
{
	if(!head)
		return 0;
	int c=0;
	while(head){
		c++;
		head=head->next;
	}
	return c;
}
int main()
{
	printf("Start of program-\n");
	node_t* head = NULL;
	addnode(&head, 5);
	addnode(&head, 7);
	addnode(&head, 3);
	addnode(&head, 9);	
	addnode(&head, 2);
	addnode(&head, 3);
	printf("Length of LL is :%d\n", findlength(head));
	printlist(head);
	printf("\nEnd of program-\n");
}
