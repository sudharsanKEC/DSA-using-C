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
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void cloneList(Node *head1,Node **head2){
	Node *temp1=head1,*temp2=NULL;
	while(temp1!=NULL){
		Node *newnode=(Node*)malloc(sizeof(Node));
		newnode->data=temp1->data;
		newnode->next=NULL;
		if(*head2==NULL){
			*head2=newnode;
			temp2=newnode;
		}else{
			temp2->next=newnode;
			temp2=newnode;
		}
		temp1=temp1->next;
	}
}
void display(Node * temp){
	printf("The elements are:");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	int n=0;
	Node *head1=NULL,*head2=NULL;
	printf("Enter the size of the linked list:");
	scanf("%d",&n);
	int i=0,data=0;
	printf("Enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNode(&head1,data);
	}
	printf("Original List:\n");
	display(head1);
	cloneList(head1,&head2);
	printf("Cloned list:\n");
	display(head2);
}
