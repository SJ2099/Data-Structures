#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
{
	int data;
	int priority;
	struct node *next;
};
struct node *head=NULL;
int x,pri;
void insert(int x, int pri);
void delete();
void display();
int main()
{
	int choice;
	do
	{
	printf("\n1.Insert\n2.Delete\n3.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Enter element and its priority:");
		scanf("%d %d", &x,&pri);
		insert(x,pri);
		break;
		case 2:
		delete();
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
void insert(int x, int pri)           //from rear end
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->priority=pri;
	if(head==NULL || pri< head->priority)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL && pri >= temp->next->priority)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void delete()          //from front end (priority not considered)
{
	if(head==NULL)
	{
		printf("Queue Underflow\n");
		return;
	}
	else
	{
		struct node *temp=head;
		printf("%d Deleted", temp->data);
		head=head->next;
		free(temp);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Queue Underflow\n");
		return;
	}
	else
	{
		struct node *temp=head;
		while(temp!=NULL)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
	}
}
