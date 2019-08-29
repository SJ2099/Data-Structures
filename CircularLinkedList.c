#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void create()
{
	int val;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter element:");
	scanf("%d", &val);
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=newnode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=newnode;
		newnode->next=head;
	}
	printf("%d Inserted\n",newnode->data);
}
void del()
{
	struct node *temp=head;
	if(head==NULL)
	printf("Underflow\n");
	else
	{
	while(temp->next!=head)
		temp=temp->next;
	printf("%d deleted", head->data);
	temp->next=head->next;              //circular LL deletion
	free(head);
	head=temp->next;
	}
}
void display()
{
	struct node *temp=head;
	if(head==NULL)
	printf("Underflow\n");
	else
	{
		while(temp->next!=head)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		printf("%d\t", temp->data);
	}
}
int main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n1.Create\n2.Delete\n3.Display\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		create();
		break;
		case 2:
		del();
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
