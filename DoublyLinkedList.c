#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next,*prev;
}Node;
Node* createNode(int data){
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void insertNode(Node **head,int data){
	Node *newnode=createNode(data);
	Node *temp=NULL;
	if(*head==NULL){
		(*head)=newnode;
		temp=(*head);
	}else{
		temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}
void deleteNode(Node **head,int pos){
	if(*head==NULL){
		printf("List is empty\n");
		return;
	}
	Node *temp=*head,*temp2=NULL;
	int i=1;
	while(i!=pos && temp!=NULL){
		temp=temp->next;
		i++;
	}
	if(pos==1){
		if((*head)->next==NULL){
			free(*head);
			(*head)=NULL;
			return;
		}
		(*head)->next->prev=NULL;
		(*head)=(*head)->next;
		free(temp);	
	}else if(i==pos && temp!=NULL){
		if(temp->next!=NULL){
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		}
		else{
			temp->prev->next=NULL;
			temp->prev=NULL;
		}
		free(temp);
	}
	else{
		printf("No such position exists\n");
	}
}
void search(Node *temp,int data){
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	int i=0;
	while(temp!=NULL){
		if(temp->data==data){
			i++;
			printf("Element found at position %d\n",i);
			return;
		}
		temp=temp->next;
		i++;
	}
	printf("Element not found in the list\n");
}
void traversal(Node *head){
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
void freeUpList(Node** head){
	Node *temp=*head;
	while(temp!=NULL){
		*head=(*head)->next;
		free(temp);
		temp=*head;
	}
	printf("List is deleted\n");
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
						printf("Double Linked List is empty so deletion is not possible\n");
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
						printf("Double Linked List is empty\n");
					} else {
						printf("The elements in DLL are: ");
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
