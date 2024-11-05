#include<stdio.h>
void Selection(int a[],int n){
	int i,j,min,temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min])
			min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
int main(){
    int n,i,a[50],j,t;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	Selection(a,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}
