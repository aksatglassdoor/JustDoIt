#ifndef HEADERFILE_linkedList
#define HEADERFILE_linkedList


typedef struct node_t{
	int val;
	struct node_t *next;
}node_t;



struct node_t* makeNode(int val);
void addNode(struct node_t **node, int val);
void printLinkedList(struct node_t *head);


#endif

