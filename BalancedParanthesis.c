#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
int top=-1;
char stack[MAX];
void push(char c){
	stack[++top]=c;
}
void pop(){
	--top;
}
bool isBalanced(char str[]){
	int i=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			push(str[i]);
		}
		else if(str[i]==')' && top>=0 && stack[top]=='('){
			pop();
		}
		else if(str[i]==']' && top>=0 && stack[top]=='['){
			pop();
		}
		else if(str[i]=='}' && top>=0 && stack[top]=='{'){
			pop();
		}
		else if(str[i]==']' || str[i]==')' || str[i]=='}'){
			return false;
		}
	}
	return top==-1;
}
int main(){
	char str[20];
	int i=0,n=0;
	printf("Enter the characters:");
	scanf("%s",str);
	if(isBalanced(str)){ 
		printf("Valid paranthesis\n");
	}
	else{
		printf("Not a valid paranthesis\n");
	}
	return 0;	
}
