#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void addInLL(struct node **head,int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	struct node* temp=NULL;
	if(*head==NULL){
		*head=newnode;
		temp=*head;
	}else{
		temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(struct node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
int main(){
	struct node *head=NULL;
	int m=0,n=0,i=0,j=0;
	printf("Enter rows and cols:");
	scanf("%d%d",&m,&n);
	int mat[m][n];
	printf("Enter the values of the matrix:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]!=0){
				addInLL(&head,mat[i][j]);
			}
		}
	}
	printf("The non zero values in the sparse matrix are:");
	display(head);
	return 0;
}
