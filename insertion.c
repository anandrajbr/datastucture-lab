#include <stdio.h>
int main()
{
int arr[100],n,pos,item,i;
printf("enter number of elements: ");
scanf("%d",&n);
printf("enter %d elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("enter the portion to insert(1 to %d):",n);
scanf("%d",&pos);
printf("enter the value to be insert: ");
scanf("%d",&item);
for(i=n;i>=pos;i--)
{
arr[i]=arr[i=1];
}
arr[pos-1]=item;
n++;
printf("array after insertion:\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
return(0);
}
