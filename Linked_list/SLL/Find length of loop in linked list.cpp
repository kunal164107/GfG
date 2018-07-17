#include<stdio.h>
#include<stdlib.h>



struct Node
{
	int data;
	struct Node* next;
};

int countNodesinLoop(struct Node *list)
{
	struct Node* temp = list;
	struct Node* add[500];
	int i=0,j=-1;
	while(temp!=NULL){
		for(int k=0;k<j;k++){
			if(add[k] == temp){
				return j-k+1;
			}
		}
		add[i]=temp;
		i+=1;
		j+=1;
		temp=temp->next;
	}
	return -1;
}

struct Node *newNode(int key)
{
	struct Node *temp =
		(struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}


int main()
{
	struct Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = head->next;

	printf("%d \n", countNodesinLoop(head));

	return 0;
}
