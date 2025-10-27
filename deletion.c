#include <stdio.h>
int main()
{
int arr[100],n,pos,i;
printf("enter number of elements: ");
scanf("%d",&n);
printf("enter %d elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("enter the portion to delete(1 to %d):",n);
scanf("%d",&pos);
if(pos<1||pos>n){
printf("invalid position!\n");
}
else{
	for(i=pos-1;i<n-1;i++){
	arr[i]=arr[i+1];
	}
	n--;
	printf("array after deletion:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}
return 0;
}
