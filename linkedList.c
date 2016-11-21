#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"



linkedList_node* makeNode(int val)
{
	linkedList_node *myNode;
	myNode = (linkedList_node*)malloc(sizeof(linkedList_node));
	assert(myNode);
	myNode->value=val;
	myNode->next=NULL;
	return myNode;
}



void addNode(linkedList_node **node, int val)
{
	linkedList_node* head = *node;
	
	if(!head){
		head = makeNode(val);
		*node = head;	//make the actual head point to this new node
		return;
	}

	while(head->next)
		head = head->next;	
	
	head->next = makeNode(val);	
}



void printLinkedList(linkedList_node *head)
{
	printf("The current linked list is this -\n");
	if(!head){
		printf("Sorry! List empty.");
		return;
	}
	while(head){
		printf("%d\t", head->value);
		head = head->next;
	}
}

int main()
{}


/*
int main(){
	printf("****Start of program****\n");
	linkedList_node *head = NULL;
	addNode(&head, 5);
	addNode(&head, 2);
	addNode(&head, 7);
	printLinkedList(head);
	printf("\n****End of program****");
}
*/

