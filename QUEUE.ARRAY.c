#include<stdio.h>
#define MAX 10
int queue[MAX],front =-1,rear =-1,item;
void insert_element(int item){
	if(rear==MAX-1)
		printf("\n OVERFLOW\n");
	else if(front==-1 && rear==-1)
		front=rear=0;
	else
		rear++;
	queue[rear]=item;
	}
void delete_element(){
	if(front==-1 || front>rear)
		printf(" UNDERFLOW\n");
	else{
		item=queue[front];
		front++;
		if(front>rear)
			front=rear=-1;
		printf(" The deleted element is:%d",item);
	}
}
void peek(){
		if(front==-1||front>rear)
			printf("\n QUEUE is empty");
		else{
			printf("\n The first value in queue:%d",item);
		}
}
void display(){
	int i;
	printf("\n");
	if(front==-1||front>rear)
		printf("QUEUE is empty");
	else{
		printf("The queue is: ");
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);

	}
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
		
