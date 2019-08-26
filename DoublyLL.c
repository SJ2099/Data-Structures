/*Advantage of doubly linked list- no need of two pointers for operations like singly linked list
Disadvantage of doubly linked list- more memory required by each node (as prev pointer added)*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head;
struct node *GetNewNode(int x)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
void InsertAtHead(int x)
{
	struct node *newnode=GetNewNode(x);
	if(head==NULL)
		head=newnode;
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
	printf("Node Inserted\n");
}
void InsertAtTail(int x)
{
	struct node *newnode=GetNewNode(x);
	if(head==NULL)
		head=newnode;
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->prev=temp;
		temp->next=newnode;
	}
	printf("Node Inserted\n");
}
void DeleteFromHead()
{
	struct node *temp=head;
	if(head==NULL)
		printf("Underflow\n");
	if(head->next==NULL)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		head=temp->next;
		head->prev=NULL;
		free(temp);
		printf("One node deleted\n");
	}
	printf("Node Deleted\n");
}
void DeleteFromTail()
{
	struct node *temp=head;
	if(head==NULL)
		printf("Underflow\n");
	if(head->next==NULL)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
	}
	printf("Node Deleted\n");
}
void InsertBefore(int x)        // error
{
	int loc;
	struct node *newnode=GetNewNode(x);
	struct node *temp=head;
	printf("Enter node before which node is to be inserted:");
	scanf("%d", &loc);
	if(head==NULL)
		head=newnode;
	while(temp->data!=loc)
	{
		temp=temp->next;
	}
	temp->prev=newnode;
	temp->prev->next=newnode;   //temp's initial prev before insertion of newnode
	newnode->prev=temp->prev;
	newnode->next=temp;
	printf("Node Inserted\n");

}
void InsertAfter(int x)
{
	int loc;
	struct node *newnode=GetNewNode(x);
	struct node *temp=head;
	printf("Enter node after which node is to be inserted:");
	scanf("%d", &loc);
	if(head==NULL)
		head=newnode;
	while(temp->data!=loc)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
	temp->next->prev=newnode;    //temp's initial next before insertion of newnode
	printf("Node Inserted\n");
}
void RemoveSpecific(int delvalue)
{
	struct node *temp=head;
	if(head==NULL)
		printf("Underflow\n");
	while(temp->data!=delvalue)
	{       if(temp->next==NULL)
		{
			printf("Node not found\n");
			return;
		}
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	printf("Node Deleted\n");
}
void Display()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\t", temp->data);
		temp=temp->next;
	}
}
void DisplayRev()
{
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d\t", temp->data);
		temp=temp->prev;
	}
}
main()
{
	int choice,x;
	clrscr();
	do
	{
	printf("\n1.Insert at Head\n2.Insert at Tail\n3.Delete from Head\n4.Delete from Tail\n5.Insert Before\n6.Insert After\n7.Remove Specific\n8.Display\n9.Display Reverse\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		printf("Enter element:");
		scanf("%d", &x);
		InsertAtHead(x);
		break;
		case 2:
		printf("Enter element:");
		scanf("%d", &x);
		InsertAtTail(x);
		break;
		case 3:
		DeleteFromHead();
		break;
		case 4:
		DeleteFromTail();
		break;
		case 5:
		printf("Enter element:");
		scanf("%d", &x);
		InsertBefore(x);
		break;
		case 6:
		printf("Enter element:");
		scanf("%d", &x);
		InsertAfter(x);
		break;
		case 7:
		printf("Enter element:");
		scanf("%d", &x);
		RemoveSpecific(x);
		break;
		case 8:
		Display();
		break;
		case 9:
		DisplayRev();
		break;
		default:
		printf("Invalid Choice\n");
		break;
	}
	}while(choice!=10);
}
