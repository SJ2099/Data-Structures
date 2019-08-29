#include<stdio.h>
#include<conio.h>
#define MAX 5

int q[MAX], front=-1, rear=-1,x;
void output_restricted();
void input_restricted();
void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();
int main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n1.Output Restricted Queue\n2.Input Restricted Queue\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		output_restricted();
		break;
		case 2:
		input_restricted();
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=3);
	return 0;
}
void output_restricted()
{
	int choice;
	do
	{
	printf("\n1.Insert right\n2.Insert left\n3.Delete left\n4.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		insert_right();
		break;
		case 2:
		insert_left();
		break;
		case 3:
		delete_left();
		break;
		case 4:
		display();
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=5);
}
void input_restricted()
{
	int choice;
	do
	{
	printf("\n1.Insert right\n2.Delete right\n3.Delete left\n4.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		insert_right();
		break;
		case 2:
		delete_right();
		break;
		case 3:
		delete_left();
		break;
		case 4:
		display();
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=5);
}
int newinsert(int x)
{
	printf("Enter element to insert:");
	scanf("%d", &x);
	return x;
}
void insert_right()                        		 //normally we insert from right
{
	if((front==0 && rear==MAX-1)||(((rear+1)%MAX)==front))
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1||rear==-1)
	{
		front=rear=0;
	}
	else if(rear==MAX-1)                 //circular queue condition
		rear=0;
	else
		rear=rear+1;
	q[rear]=newinsert(x);
	printf("%d inserted from right",q[rear]);
}
void insert_left()
{
	if((front==0 && rear==MAX-1)||(((rear+1)%MAX)==front))
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1||rear==-1)
	{
		front=rear=0;
	}
	else if(front==0)                 //circular queue condition (decrementing front => inserting from front)
		front=MAX-1;
	else
		front=front-1;
	q[front]=newinsert(x);
	printf("%d inserted from left",q[front]);
}
void delete_right()
{
	if(front==-1)
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("%d deleted from right",q[rear]);
	if(front==rear)
		front=rear=-1;
	else if(rear==0)		     //circular queue condition (decrementing rear => deleting from rear)
		rear=MAX-1;
	else
		rear=rear-1;

}
void delete_left()                      //normally we delete from left
{
	if(front==-1)
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("%d deleted from left",q[front]);
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)		     //circular queue condition
		front=0;
	else
		front=front+1;
}
void display()
{
	int i,j;
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
}
