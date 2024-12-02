#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char stack[25];
void push(char c){
	stack[++top]=c;
}
void pop(){
	printf("%c",stack[top--]);
}
int main(){
	char str[25];
	printf("Enter the character to be reversed:\n");
	scanf("%s",str);
	int i=0;
	for(i=0;str[i]!='\0';i++){
		push(str[i]);
	}
	printf("Reversing the string using stack:");
	for(i=0;i<strlen(str);i++){
		pop();
	}
	return 0;
}
