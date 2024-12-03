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
	int i=0,flag=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			push(str[i]);
			flag=1;
		}
		else if(str[i]==')' && top>=0 && stack[top]=='('){
			pop();
			flag=1;
		}
		else if(str[i]==']' && top>=0 && stack[top]=='['){
			pop();
			flag=1;
		}
		else if(str[i]=='}' && top>=0 && stack[top]=='{'){
			pop();
			flag=1;
		}
		else if(str[i]==']' || str[i]==')' || str[i]=='}'){
			return false;
		}
	}
	if(flag==0)
	printf("The given string does not contains a parantheses\n");
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
/*
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

bool isValidParentheses(const char *str) {
    char stack[MAX];
    int top = -1,i=0;

    for ( i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1 || !isMatchingPair(stack[top--], str[i])) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char str[MAX];

    printf("Enter a string with parentheses: ");
    scanf("%s", str);

    if (isValidParentheses(str)) {
        printf("The string contains valid parentheses.\n");
    } else {
        printf("The string contains invalid parentheses.\n");
    }

    return 0;
}
*/
