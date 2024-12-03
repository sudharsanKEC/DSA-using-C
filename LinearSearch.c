#include<stdio.h>
void linearSearch(int arr[],int data,int n){
	int i=0,flag=0;
	for(i=0;i<n;i++){
		if(data==arr[i]){
			flag=1;
			printf("The given element is found at the position %d\n",i+1);
			break;
		}
	}
	if(flag==0)
	printf("Element not found\n");
	return;
}
int main(){
	int n=0;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int arr[n],i=0;
	printf("Now enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int data=0;
	printf("Enter the element to find its position:");
	scanf("%d",&data);
	linearSearch(arr,data,n);
}
