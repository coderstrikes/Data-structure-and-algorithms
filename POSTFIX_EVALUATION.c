#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
int stack[MAX],top=-1;
char exp[100];
void push(int item){
	if(top==MAX-1){
		printf("Stack Overflow");
	}
	else{
		top++;
		stack[top]=item;
	}
}
int pop(){
	int data;
	if(top==-1)
		printf("Stack Underflow");
	else{
		data=stack[top];
		top--;
	}
	return data;
}
float eval(){
	int i=0;
	float op1,op2,value;
	while(exp[i]!='\0'){
		if(isdigit(exp[i]))
			push((float)(exp[i]-'0'));
		else{
			op2=pop();
			op1=pop();
			switch(exp[i]){
				case '+':
					value = op1+op2;
					break;
				case '-':
					value = op1 - op2;
					break;
				case '/':
					value=op1/op2;
					break;
				case '*':
					value=op1*op2;
					break;
				case '%':
					value=(int)op1%(int)op2;
					break;
				}
				push(value);
			}
			i++;
		}
	return(pop());
}
int main(){
	float val;
	printf("Enter any postfix Expression:");
	gets(exp);
	val=eval();
	printf("\n Value of the postfix expression = %.2f",val);
	return 0;
	}
