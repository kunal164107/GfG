/* This program swaps the nodes of linked list rather
than swapping the field from the nodes.*/

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodes(struct Node **head_ref, int x, int y)
{
    struct Node* key1 = *head_ref;
    struct Node* key2 = *head_ref;
    
    struct Node* prev_k1 = NULL;
    struct Node* after_k1= key1->next;
    struct Node* prev_k2 = NULL;
    struct Node* after_k2 = key2->next;
    
    while(key1->data != x){
		// printf("\nchk6");
        prev_k1 = key1;
        key1=key1->next;
        after_k1 = key1->next;
    }
    
    while(key2->data!= y){
		// printf("\nchk7");
        prev_k2 = key2;
        key2=key2->next;
        after_k2 = key2->next;
    }
    
    if((*head_ref)->data == x && (*head_ref)->next->data != y){
		// printf("\nchk1");
        key2->next = after_k1;
        prev_k2->next = key1;
        key1->next = after_k2;
		(*head_ref) = key2;
    }
    else if((*head_ref)->data == x && (*head_ref)->next->data == y){
		// printf("\nchk2");
        key2->next = key1;
        key1->next = after_k2;
		(*head_ref) = key2;
    }
    else if(key1->next->next == NULL && key2->next == NULL){
		// printf("\nchk3");
        prev_k1->next = key2;
        key2->next = key1;
        key1->next = after_k2;
    }
    else if(key1->next->data == key2->data ){
		// printf("\nchk4");
        prev_k1->next = key2;
        key2->next = key1;
        key1->next = after_k2;
    }
    else{
		// printf("\nchk5");
        prev_k1->next = key2;
        key2->next = after_k1;
        prev_k2->next = key1;
        key1->next = after_k2;
    }
}

/* Function to add a node at the begining of List */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while(node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Druver program to test above function */
int main()
{
	struct Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5->6->7 */
//	push(&start, 8);
//	push(&start, 7);
	push(&start, 14);
	push(&start, 20);
	push(&start, 13);
	push(&start, 12);
	push(&start, 15);
	push(&start, 10);

	printf("\n Linked list before calling swapNodes() ");
	printList(start);

	swapNodes(&start, 12, 13);

	printf("\n Linked list after calling swapNodes() ");
	printList(start);

	return 0;
}
