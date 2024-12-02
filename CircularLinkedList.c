#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node;
void insertNode(Node **head,int data){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	Node *temp=NULL;
	if(*head==NULL){
		*head=newnode;
		(*head)->next=newnode;
	}else{
		temp=(*head)->next;
		while(temp->next->data!=(*head)->data){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=*head;
	}
}
void deleteNode(Node **head,int pos){
	if(*head==NULL){
		printf("List is empty\n");
		return;
	}
	int i=1;
	Node* temp=*head;
	if(i==pos){
		if((*head)->next==*head){
			free(*head);
			(*head)=NULL;
			printf("Element deleted successfully\n");
			return;
		}else{
			do{
				temp=temp->next;
			}while(temp->next!=(*head));
			temp->next=(*head)->next;
			free(*head);
			(*head)=temp->next;
			printf("Element deleted successfully\n");
			return;
		}
	}
	do{
		if(i==pos-1)
		break;
		temp=temp->next;
		i++;
	}while(temp->next!=(*head));
	if(i==pos-1){
		Node* temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		printf("Element delete successfully\n");
	}else{
		printf("Position not found\n");
	}
}
void search(Node *head,int data){
	int i=1;
	Node *temp=head;
	do{
		if(temp->data==data){
			printf("Element found at position %d\n",i);
			break;
		}
		temp=temp->next;
		i++;
	}while(temp!=head);
	printf("Element not found\n");
}
void traversal(Node *head){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	Node *temp=head;
	printf("The elements in the list are:\n");
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp->data!=head->data);
	printf("\n");
}
void freeUpList(Node **head){
	Node *oriHead=(*head);
	Node *temp=(*head)->next;
	*head=(*head)->next;
	do{
		(*head)=(*head)->next;
		free(temp);
		temp=(*head);
	}while(temp!=oriHead);
	free(temp);
	(*head)=NULL;
	printf("The List is free up\n");
}
int main(){
	Node *head=NULL;
	int op=0;
	do{
		printf("1.Insert At End\n2.Delete\n3.Search an element Position\n4.Traverse the List\n5.FreeUp the List\n6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	{
				printf("Enter an element: ");
				int x=0;
				scanf("%d", &x);
				insertNode(&head, x);
				break;
			}
			case 2:{
				if (head == NULL) {
						printf("Circular Linked List is empty so deletion is not possible\n");
					} else {
						printf("Enter position to delete:");
						int pos=0;
						scanf("%d",&pos);
						deleteNode(&head,pos);
					}
				break;
			}
			case 3:	{
					printf("Enter search element: ");
					int data=0;
					scanf("%d", &data);
					search(head,data);
					break;
			}
			case 4: 
					if (head == NULL) {
						printf("Circular Linked List is empty\n");
					} else {
						printf("The elements in CLL are: ");
						traversal(head);
					}
					break;
			case 5:{
				freeUpList(&head);
				break;
			}
			case 6:	exit(0);
		
		}
	}while(op!=6);
}
