#include<stdio.h>
main(){
	int n,i,a[50],j,t;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
		if(a[j]>a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
		}
	}
	printf("The sorted array is:");
	for(i=0;i<n;i++)
	printf("%d",a[i]);	
}
