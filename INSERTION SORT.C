#include<stdio.h>
void InsertionSort(int a[],int n){
	int i,j,v;
	for(i=1;i<=n-1;i++){
		v=a[i];
		j=i;
		while(a[j-1]>v && j>=1){
			a[j]=a[j-1];
			j--;
			
		}
		a[j]=v;
	}
}
int main(){
    int n,i,a[50],j,t;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	InsertionSort(a,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}
