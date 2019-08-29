#include<stdio.h>
#include<conio.h>
#define MAX 100

int a[MAX],top=-1;

void push(int x)
{
	if(top==MAX-1)
		printf("Stack Overflow\n");
	else
	{
		top++;
		a[top]=x;
		printf("%d Inserted\n", x);
	}
}
void pop()
{
	if(top==-1)
		printf("Stack Underflow");
	else
	{
		printf("%d Deleted\n", a[top]);
		top--;
	}
}
void display()
{
	if(top==-1)
		printf("Stack Underflow");
	else
	{       int i;
		for(i=top;i>=0;i--)
		{
			printf("%d\n", a[i]);
		}
	}
}
int main()
{
	int x,choice;
	clrscr();
	do
	{
	printf("\n1.Push\n2.Pop\n3.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Enter element to insert:");
		scanf("%d", &x);
		push(x);
		break;
		case 2:
		pop();
		break;
		case 3:
		display();
		break;
		default:
		printf("Invalid Choice\n");
		break;
	}
	}while(choice!=4);
	return 0;
}
	
