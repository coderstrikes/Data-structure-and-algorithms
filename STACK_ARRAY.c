#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
void push(int data){
	if(top==MAX-1){
		printf("Stack Overflow");
	}
	else{
		top++;
		stack[top]=data;
	}
}
void pop(){
	int data;
	if(top==-1)
		printf("Stack Underflow");
	else{
		data=stack[top];
		top--;
		printf("Deleted data element %d",data);
	}
}
void peek(){
	int data;
	if(top==-1)
		printf("Stack is Empty");
	else{
		data=stack[top];
		printf("Element at the top of stack:%d",data);
	}
}
void display(){
	int i;
	if(top==-1)
	printf("Stack is Empty");
	else{
		printf("The elements are:");
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
	}
}
int main(){
	int  option,item;
	do{
	printf("\n""*****MAIN MENU*****");
	printf("\n 1. peek");
	printf("\n 2. pop");
	printf("\n 3. peek");
	printf("\n 4. Display");
	printf("\n 5. Exit");
	printf("\n Enter your option:");
	scanf("%d",&option);
	switch(option){
		case 1:
			printf("Enter the item to be pushed:");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			break;
		default:
			printf("invalid condition");
			break;
	}
}while(option!=5);
return 0;
}
