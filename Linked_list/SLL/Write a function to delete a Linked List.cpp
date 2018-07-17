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
void deleteList(struct Node **head_ref)
{
  struct Node* temp = *head_ref;
  struct Node* temp1 = temp;
  
  while(temp->next!=NULL){
	  temp1=temp->next;
	  free(temp);
	  temp = temp1;
  }
  free(temp);
  *head_ref = NULL;
  
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
    
    /* Use push() to construct below list
     1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1); 
    push(&head, 12);
    push(&head, 1);   
    
    printf("Deleting linked list");
    deleteList(&head);  
	
    printf("\n Linked list deleted");
	
}
