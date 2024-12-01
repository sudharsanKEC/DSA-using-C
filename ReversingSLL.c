#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
void createNode(Node **head,int data){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	Node *temp=*head;
	if(*head==NULL){
		*head=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(Node *temp){
	//printf("The elements in the linked list are\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverse(Node **head){
	Node *prev=NULL,*curr=*head,*next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}
int main(){
	Node *head=NULL;
	printf("Enter the number of datas in the linked list:");
	int n=0,i=0,data=0;
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNode(&head,data);
	}
	printf("Elements in LL before LL:\n");
	display(head);
	reverse(&head);
	printf("The elements in LL after the reversal:\n");
	display(head);
	return 0;
}
 
 
