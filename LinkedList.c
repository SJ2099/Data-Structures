#include<conio.h>
#include<stdio.h>
#include<malloc.h>
void insert_at_beginning();
void insert_at_end();
void remove_from_beginning();
void remove_from_end();
void insert_between();
void remove_specific();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;       // *head= value at address, head= address
main()
{
	int choice;
	clrscr();
	do
	{
		printf("\n1.Insert at beginning\n");
		printf("2.Insert at end\n");
		printf("3.Remove from beginning\n");
		printf("4.Remove from end\n");
		printf("5.Insert between\n");
		printf("6.Remove specific\n");
		printf("7.Display\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			insert_at_beginning();
			break;
			case 2:
			insert_at_end();
			break;
			case 3:
			remove_from_beginning();
			break;
			case 4:
			remove_from_end();
			break;
			case 5:
			insert_between();
			break;
			case 6:
			remove_specific();
			break;
			case 7:
			display();
			break;
			default:
			printf("Invaid choice\n");
			break;
		}
	}while(choice!=8);
}
void insert_at_beginning()
{
	int x;
	struct node *temp=(struct node *)malloc(sizeof(struct node));      //malloc= for dynamic allocation of memory
	printf("Enter data:"); 
	scanf("%d", &x);
	temp->data=x;
	temp->next=head;
	head=temp;
}
void insert_at_end()
{
	int x;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &x);
	newnode->data=x;
	newnode->next=NULL;
	if(head==NULL)                 //if linked list is empty
		head=newnode;
	else
	{
		struct node *temp=head;      //temporary pointer to head to start treaversing (to reach end to insert newnode)
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void remove_from_beginning()
{
	if(head==NULL)
		printf("Linked List is empty\n");
	else
	{
		struct node *temp=head;
		if(head->next==NULL)             //if only one node in list make it null to delete it
		{
			head=NULL;      
			free(temp);
		}
		else                           //if more than one node in list make next addr as head node 
		{
			head=temp->next;
			free(temp);
			printf("One node deleted\n");
		}
	}
}
void remove_from_end()
{
	if(head==NULL)
		printf("Linked List is empty\n");
	else
	{
		struct node *temp1=head, *temp2;
		while(temp1->next!=NULL)          //temp1 next will be followed by temp2 
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=NULL;                //making temp2 last node 
		free(temp1);                     //deleting last node
		printf("One node deleted\n");
	}
}
void insert_between()
{
	int x,loc;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d", &x);
	printf("Enter node before which node is to be inserted:");
	scanf("%d", &loc);
	newnode->data=x;
	if(head==NULL)
		head=newnode;
	else
	{
		struct node *temp1=head, *temp2;
		while(temp1->data!=loc)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=newnode;            
		newnode->next=temp1;                 //node inserted between temp2 & temp1
		printf("Node inserted\n");
	}
}
void remove_specific()
{
	int delvalue;
	struct node *temp1=head, *temp2;
	printf("Enter node to be deleted:");
	scanf("%d", &delvalue);
	while(temp1->data!=delvalue)
	{
		if(temp1->next==NULL)               //if the entire linked list is traveresed
		{
			printf("Node not found\n");
			return;
		}
		temp2=temp1;
		temp1=temp1->next;            // making temp1= delvalue
	}
	temp2->next=temp1->next;           //making temp2 point to node initially pointed by temp1
	free(temp1);                       //deleting temp1 (delvalue)      
	printf("Node deleted\n");
}
void display()
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
	
		
