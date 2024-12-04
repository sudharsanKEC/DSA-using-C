#include<stdio.h>
int main(){
	printf("Enter the size of the array:");
	int n=0,i=0,mid=0,data=0;
	scanf("%d",&n);
	printf("Enter the sorted array\n");
	int arr[n],l=0,r=n-1;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to find in the array:");
	scanf("%d",&data);
	while(l<=r){
		mid=(l+r)/2;
		if(arr[mid]==data){
			printf("Element found at position:%d\n",mid+1);
			return 0;
		}else if(arr[mid]<data){
			l=mid+1;
		}
		else if(arr[mid]>data){
			r=mid-1;
		}
	}
	printf("Element not found in the array\n");
	return 0;
}
