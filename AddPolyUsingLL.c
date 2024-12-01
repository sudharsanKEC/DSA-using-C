#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coeff,pow;
	struct node* next;
}Node;
Node* createPoly(int n){
	int i=0;
	struct node* head=NULL,*temp=NULL;
	for(i=0;i<n;i++){
		Node *newnode=(Node*)malloc(sizeof(Node));
		printf("Enter the coeff of the term:");
		scanf("%d",&newnode->coeff);
		printf("Enter the power of the term:");
		scanf("%d",&newnode->pow);
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			temp=newnode;
		}else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head;
}
void display(Node *head){
	Node *temp=head;
	while(temp->next!=NULL){
		printf("%dx^%d + ",temp->coeff,temp->pow);
		temp=temp->next;
	}
	printf("%dx^%d",temp->coeff,temp->pow);
}
Node* addPoly(Node *head1,Node *head2){
	Node *add=NULL,*temp=NULL;
	while(head1!=NULL || head2!=NULL){
		Node *newnode=(Node*)malloc(sizeof(Node));
		if(head1!=NULL && head2!=NULL && head1->pow==head2->pow){
			newnode->pow=head1->pow;
			newnode->coeff=head1->coeff+head2->coeff;
			newnode->next=NULL;
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1!=NULL && (head2==NULL || head2->pow<head1->pow)){
			newnode->pow=head1->pow;
			newnode->coeff=head1->coeff;
			newnode->next=NULL;
			head1=head1->next;
		}
		else if(head2!=NULL && (head1==NULL || (head1->pow<head2->pow))){
			newnode->pow=head2->pow;
			newnode->coeff=head2->coeff;
			newnode->next=NULL;
			head2=head2->next;
		}
		if(add==NULL){
			add=newnode;
			temp=newnode;
		}else{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return add;
}
int main(){
	printf("Enter the number of elements you want in the first Polynomial equation:");
	int n=0;
	scanf("%d",&n);
	Node *head1=createPoly(n);
	printf("Enter the number of elements you want in the second Polynomial equation:");
	scanf("%d",&n);
	Node *head2=createPoly(n);
	printf("\nThe First polynomial equation is:\n");
	display(head1);
	printf("\nThe second polynomial equation is:\n");
	display(head2);
	Node* addedPoly=addPoly(head1,head2);
	printf("\nAfter The addition:\n");
	display(addedPoly);
	return 0;
}
