#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
void createNode(Node **head,int data){
	Node *newnode=(Node*)malloc(sizeof(Node));
	if(newnode==NULL){
		printf("Memory allocation failed\n");
		return;
	}
	newnode->data=data;
	newnode->next=NULL;
	Node *temp=*head;
	if(*head==NULL){
		*head=newnode;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(Node *temp){
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	printf("The elements are:");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void bubbleSort(Node **head){
	if(*head==NULL){
		printf("List is empty\n");
		return;
	}
	Node *temp1=NULL,*temp2=NULL;
	for(temp1=*head;temp1->next!=NULL;temp1=temp1->next){
		for(temp2=temp1;temp2!=NULL;temp2=temp2->next){
			if(temp1->data>temp2->data){
				int data=temp2->data;
				temp2->data=temp1->data;
				temp1->data=data;
			}
		}
	}
}
int main(){
	int n=0;
	Node *head=NULL;
	printf("Enter the size of the linked list:");
	scanf("%d",&n);
	int i=0,data=0;
	printf("Enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNode(&head,data);
	}
	printf("Before Sorting:\n");
	display(head);
	bubbleSort(&head);
	printf("After sorting:\n");
	display(head);
	return 0;
}
