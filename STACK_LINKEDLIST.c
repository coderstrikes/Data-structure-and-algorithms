#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
void push(int item){
	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=item;
	if(top==NULL){
		ptr->next=NULL;
		top=ptr;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
}
void pop(){
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Empty list");
	else{
		top=top->next;
		printf("The value being deleted is:%d",ptr->data);
		free(ptr);
	}
}
void peek(){
	if(top==NULL)
		printf("Empty list");
	else{
		printf("The top most element is:%d",top->data);
	}
}
void display(){
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Stack is Empty");
	else{
		printf("STACK:");
		while(ptr!=NULL){
			printf("\n %d",ptr->data);
			ptr=ptr->next;
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
