// A menu driven program for Singly Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;

struct Node* head=NULL;

struct Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//Node* temp;
void insertAtBeg(int data){
	struct Node* newNode = createNode(data);
	if(head==NULL){
		head = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
	
}
void insertAtEnd(int data){
	Node* newNode = createNode(data);
	if(head == NULL){
		head = newNode;
	}
	else{
		Node* temp1 = head;
		while(temp1!=NULL && temp1->next!=NULL){
			temp1=temp1->next;
		}
		if(temp1!=NULL){
			temp1->next = newNode;
		}
	}
	printf("Element entered at end successfully\n");
}
int insertAtPos(int data,int pos){
	Node* temp1 = head;
	if(temp1==NULL){
		printf("\nList is empty!");
		return 1;
	}
	if(pos == 1){
		insertAtBeg(data);
		printf("Data entered at the position 1 successfully\n");
		return 0;
	}
	int count = 1;

	while(count!=pos-1 && temp1!=NULL){
		temp1=temp1->next;
		count++;
	}
	if(temp1==NULL || count<pos-1){
		printf("Position doesnt exist!\n");
		return 1;
	}
	Node* newNode = createNode(data);
	newNode->next = temp1->next;
	temp1->next = newNode;
	return 0;
}
int deleteAtBeginning(){
	if(head==NULL) return 1;
	if(head->next==NULL){
		free(head);
		head=NULL;
		return 0;
	}
	Node* temp1 = head;
	head = head->next;
	free(temp1);
	return 0;
	
	
}
int deleteAtEnd(){
	if(head==NULL) return 1;
	if(head->next==NULL){
		Node* temp=head;
		head=NULL;
		free(temp);
		return 0;
	}
	Node* temp = head;
	Node* tempPrev = NULL;
	while(temp->next!=NULL){
		tempPrev = temp;
		temp = temp->next;
	}
	tempPrev->next = NULL;
	free(temp);
	return 0;
}
int deleteAtPos(int pos){
    Node* temp1 = head;
	if(temp1==NULL){
		printf("List is empty!\n");
		return 1;
	}
	if(pos == 1){
		Node* temp = head;
		head = head->next;
		free(temp);
		return 0;
	}
	int count = 1;

	while(count!=pos-1 && temp1!=NULL){
		temp1=temp1->next;
		count++;
	}
	if(temp1==NULL || count<pos-1){
		printf("Position doesnt exist!\n");
		return 1;
	}
	Node* temp3 = temp1->next;
	temp1->next=temp1->next->next;
	free(temp3);
	return 0;
}
void display(){
	Node *temp = head;
	if(temp == NULL){
		printf("List is Empty!\n");
		return;
	}
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->next!=NULL){
			printf("->");
		}
		temp = temp->next;
	}
//	printf("%d",temp->data);
}

void search(int data){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    if(head->data==data){
        printf("Element found at 1\n");
        return;
    }
    int count=1;
    Node* temp = head;
    while(temp->data!=data){
        temp=temp->next;
        if(temp==NULL){
            printf("Element not found\n");
            return ;
        }
        count++;
    }
    printf("Element found at %d\n",count);
}
void findLength(){
    if(head==NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    int count = 1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Size of the Linked List: %d\n",count);
}
int main(){
	int choice;
	do{
		printf("\n<-----Singly Linked List----->\n");
		printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Search\n");
        printf("9. Find Length\n");
        printf("10. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				int data = 0;
				printf("\nEnter an element to insert at the beginning: ");
				scanf("%d",&data);
				insertAtBeg(data);
				printf("Data inserted at the beginning successfully\n");
				break;
			}
			case 2:{
				printf("\nEnter the element to insert at the end: ");
				int data = 0;
				scanf("%d",&data);
				insertAtEnd(data);
				break;
			}
			case 3:{
				int data = 0,pos = 0;
				printf("\nEnter the element: ");
				scanf("%d",&data);
				printf("\nEnter the position for the element to be inserted: ");
				scanf("%d",&pos);
				int val = insertAtPos(data,pos);
				if(val == 1){
					break;
				}
				display();
				printf("Element inserted at the position successfully!\n");
				break;
			}
			case 4:{
				int val = deleteAtBeginning();
				if(val==0){
					printf("Element deleted successfully!\n");
					display();
				}
				else{
					printf("List is empty!\n");
				}
				break;
			}
			case 5:{
				int val = deleteAtEnd();
				if(val == 0){
					display();
				}
				else{
					printf("List is Empty1\n");
				}
				break;
			}
			case 6:{
			    int pos = 0;
				printf("\nEnter the position for the element to be deleted: ");
				scanf("%d",&pos);
				int val = deleteAtPos(pos);
				if(val == 1){
					break;
				}
				display();
				printf("Element deleted at the position successfully!\n");
				break;
			}
			case 7:{
				display();
				break;
			}
			case 8:{
			    int element = 0;
			    printf("Enter the element to search: ");
			    scanf("%d",&element);
			    search(element);
			    break;
			}
			case 9:{
			    findLength();
			    break;
			}
			default:{
			    printf("Enter a valid number!");
			    break;
			}
		}
		
	}while(choice!=10);
}
