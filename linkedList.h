#ifndef HEADERFILE_linkedList
#define HEADERFILE_linkedList


typedef struct linkedList_node{
	int value;
	struct linkedList_node *next;
}linkedList_node;


struct linkedList_node* makeNode(int val);
void addNode(struct linkedList_node **node, int val);
void printLinkedList(struct linkedList_node *head);


#endif

