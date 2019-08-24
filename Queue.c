#include<stdio.h>
#include<conio.h>
#define MAX 100

int q[MAX],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();

main()
{
	int choice,x;
	clrscr();
	do
	{
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Enter element to insert:");
		scanf("%d", &x);
		enqueue(x);
		break;
		case 2:
		dequeue();
		break;
		case 3:
		display();
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=4);
}

void enqueue(int x)
{
	if(rear==MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else
			rear++;

		q[rear]=x;
		printf("%d Inserted", x);
	}
}
void dequeue()
{
	if(front==-1)
		printf("Queue Underflow\n");
	else
	{
		printf("%d Deleted", q[front]);
		if(rear==front)                      //rear=front=0
			front=rear=-1;
		else
			front++;
	}
}
void display()
{
	int i;
	if(front==-1)
		printf("Queue Underflow\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t", q[i]);
	}
}
	
