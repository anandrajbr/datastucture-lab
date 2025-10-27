#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int value){
if (top==SIZE-1){
	printf("stack overflow!cannot insert %d\n",value);
	}else{
	top++;
	stack[top]=value;
	printf("%d pushed into stack\n",value);
	}
}
void pop(){
if(top==-1){
printf("stack underflow!stack is empty\n");
}else{printf("%d popped from stack\n",stack[top]);
top--;
}}
void peek(){
if(top==-1)
	printf("stack is empty\n");
else
	printf("top element %d\n",stack[top]);
}

void display(){
if(top==-1)
printf("stack is empty\n");
else{
printf("stack elements\n");
for(int i=top;i>=0;i--)
printf("%d",stack[i]);
printf("\n");
}}	
int main(){
	int choice,value;
	
	while(1){
	printf("\n---stack menu---\n");
	printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
	printf("enter your choice:");
	scanf("%d",&choice);
	
	switch(choice){
	case 1:
		printf("enter the value of push:");
		scanf("%d",&value);
		push(value);
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
		return 0;
	default:
		printf("invalid choice!\n");
	}
	}
	}




