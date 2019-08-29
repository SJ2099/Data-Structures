#include<stdio.h>
#include<conio.h>
#define MAX 5

//Circular queue helps in reusing the empty space left in queue after deletion (i.e incrementing front)
//This is not possible in normal queue

int q[MAX],front=-1,rear=-1;
void enqueue();
void dequeue();
void display();

int main()
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
	return 0;
}

void enqueue(int x)
{
	if((rear+1)%MAX==front)
		printf("Queue Overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else
			rear=(rear+1)%MAX;

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
			front=(front+1)%MAX;
	}
}
void display()
{
	int i,j;
	if(front==-1)
		printf("Queue Underflow\n");
	if(front>rear)
	{
		for(i=0;i<=rear;i++)   //new element inserted after overflow and deletion
		printf("%d\t", q[i]);
		for(j=front;j<=MAX-1;j++)
		printf("%d\t", q[j]);
	}
	else
	{
		for(i=front;i<=rear;i++)
		printf("%d\t", q[i]);
	}
	printf("\nRear is at: %d", q[rear]);
	printf("\nFront is at: %d", q[front]);
}
	
