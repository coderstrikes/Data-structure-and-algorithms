#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char st[MAX];
int top=-1;
void push(int item){
	if(top==MAX-1){
		printf("Stack Overflow");
	}
	else{
		top++;
		st[top]=item;
	}
}
char pop(){
	int data;
	if(top==-1)
		printf("Stack Underflow");
	else{
		data=st[top];
		top--;
	}
	return data;
}
int getpriority(char op){
    if(op == '/' || op == '*' || op == '%')
        return 1;
    else if(op == '+' || op == '-')
        return 0;
    else
        return -1;
}

void infixtopostfix(char source[],char target[]){
	int i=0,j=0;
	char temp;
	strcpy(target,"");
	while(source[i]!='\0'){
		if (source[i]=='('){
			push(source[i]);
			i++;
		}
		else if(source[i]==')'){
			while((top!=-1) && (st[top]!='(')){
				target[j]=pop();
				j++;
			}
			if(top==-1){
				printf("\n INCORRECT EXPRESSION");
				exit(1);
			}
			temp=pop();
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i])){
			target[j]=source[i];
			j++;
			i++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%'){
			while ((top != -1) && (st[top] != '(') && (getpriority(st[top]) >= getpriority(source[i]))) {
   				 target[j] = pop();
   					 j++;
			}

			push(source[i]);
			i++;
		}
		else{
			printf("\n INCORRECT ELEMENT IN EXPRESSION");
			exit(1);
		}
	}
	while((top!=-1) && (st[top]!='(')){
		target[j]=pop();
		j++;
	}
	target[j]='\0';
}
int main(){
	char infix[100],postfix[100];
	printf("Enter any infix expression: ");
	gets(infix);
	
strcpy(postfix,"");
infixtopostfix(infix,postfix);
printf("\n The corresponding postfix expression is: ");
puts(postfix);
return 0;
}
