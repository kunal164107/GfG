// A complete working C program to demonstrate deletion in singly
// linked list
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **head_ref, int key)
{
  struct Node* temp = *head_ref;
  struct Node* temp1 =temp->next;
   if((*head_ref)->data == key){
	   *head_ref = temp->next;
	   free(temp);
   }
   else{
	   while(temp1->data != key){
		   temp = temp->next;
		   temp1 = temp1->next;
	   }
	   temp->next = temp1->next;
	   free(temp1);
   }
}

// This function prints contents of linked list starting from 
// the given node
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List: ");
	printList(head);
	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1: ");
	printList(head);
	return 0;
}
