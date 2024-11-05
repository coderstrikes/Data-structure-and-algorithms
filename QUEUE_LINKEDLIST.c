#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	};
struct node *head=NULL,*ptr,*new_node,*front=NULL,*rear=NULL;
int item;
void insert_element(int item){
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	if(front==NULL){
		front=ptr;
		rear=ptr;
		front->next=NULL;
		rear->next=NULL;
	}
	else{
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
	}
}
void delete_element(){
	ptr=front;
	if(front==NULL)
		printf(" Underflow");
	else{
		front=front->next;
		printf("\n The value being deleted is:%d",ptr->data);
		free(ptr);
	}
}
void peek(){
	if(front==NULL)
		printf(" Queue is empty");
	else
		printf("\n The value at the front of the queue:%d",item);
}
void display(){
	ptr=front;
	if(ptr==NULL)
		printf("\n Queue is empty");
	else
		printf("\n");
		while(ptr!=rear){
			printf(" %d",ptr->data);
			ptr=ptr->next;
			}
			printf(" %d",ptr->data);
}
int main(){
	int option;
	do{
		printf("\n ****MAIN MENU****");
		printf("\n 1. Insert an element");
		printf("\n 2. Delete an element");
		printf("\n 3. Peek");
		printf("\n 4. Display");
		printf("\n 5. EXIT");
		printf("\n Enter your option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf(" Enter the Element:");
				scanf("%d",&item);
				insert_element(item);
				break; 
			case 2:
				delete_element(); 
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
				printf(" Invalid option");
				}
			}while(option!=5);
			return 0;
		}
		
