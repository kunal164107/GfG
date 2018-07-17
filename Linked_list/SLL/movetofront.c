void moveToFront(struct Node **head_ref)
{
    struct Node* temp1 = *head_ref;
    struct Node* temp2 = *head_ref;
	
	struct Node* first = temp1->next;;
	struct Node* second = NULL;	
	
	while(temp2->next != NULL){
		second = temp2;
		temp2 = temp2->next;
	}
	
	temp2->next = first;
	second->next = temp1;
	temp1->next=NULL;
	(*head_ref) = temp2;
}