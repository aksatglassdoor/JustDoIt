#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"



node_t* makeNode(int val)
{
	node_t *myNode;
	myNode = (node_t*)malloc(sizeof(node_t));
	assert(myNode);
	myNode->val=val;
	myNode->next=NULL;
	return myNode;
}



void addNode(node_t **node, int val)
{
	node_t* head = *node;
	// Note that head and *node are still two different and independent pointers

	if(!head){
		head = makeNode(val);
		*node = head;	//make the actual head point to this new node
		return;
	}

	while(head->next)
		head = head->next;	
	
	head->next = makeNode(val);	
}



void printLinkedList(node_t *head)
{
	printf("\nThe current linked list is this -\n");
	if(!head){
		printf("Sorry! List empty.");
		return;
	}
	while(head){
		printf("%d\t", head->val);
		head = head->next;
	}
}

void reverseLL(node_t** head)
{
	node_t* curr =*head;
	node_t* prev = NULL;
	node_t* next = curr;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}


node_t* reverseLL_rec(node_t* head)
{
	if(head->next == NULL){
		return head;
	}
	reverseLL_rec(head->next);
	node_t* nextnode = head->next;
	nextnode->next = head;
	head->next = NULL;
}


void print_revLL_rec(node_t* head)
{
	if(head==NULL)
		return;
	
	print_revLL_rec(head->next);
	printf("%d\t", head->val);
}



int main(){
	printf("****Start of program****\n");
	node_t *head = NULL;
	addNode(&head, 5);
	addNode(&head, 2);
	addNode(&head, 7);
	addNode(&head, 19);
	addNode(&head, 8);
	addNode(&head, 3);
	printLinkedList(head);
	reverseLL(&head);
	printLinkedList(head);
	printf("\nPrinting reversed linked list-\n");
	print_revLL_rec(head);
	head = reverseLL_rec(head);
	printf("\nReversing linked list(using recurion)");
	printLinkedList(head);
	//sortLL(head);
	//printLinkedList(head);
	printf("\n****End of program****");
}


