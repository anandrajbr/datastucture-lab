#include <stdio.h>
#include<stdlib.h>
int main(){
	int a[100],b[100];
	int n1,n2,i,temp,total,size=0;
	
	printf("Enter how much element in first array: ");
	scanf("%d",&n1);
	printf("enter first array");
	for(i=0;i<n1;i++){
		scanf("%d",&a[i]);
	}
	printf("\nEnter how much elements in second array: ");
	scanf("%d",&n2);
	printf("enter 2nd array");
	for(i=0;i<n2;i++){
		scanf("%d",&b[i]);
	}
	total=n1+n2;
	
	for(i=n1;i<total;i++){
		a[i]=b[size];
		size++;
		}
		
	for(i=0;i<total-1;i++)
	{
		for(int j=0;j<total-i-1;j++)
		{
		        if(a[j]>a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	}
	printf("Array elements are : \n");
	for(i=0;i<total;i++){
		printf("%d\n",a[i]);
		}
		return 0;
	}
		
