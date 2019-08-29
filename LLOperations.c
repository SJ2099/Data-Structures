#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head1=NULL, *head2=NULL;
void insert(int ele)
{
	int c;
	struct node *temp;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	printf("Choose a list to insert node:\n 1.Linked List 1\n 2.Linked List 2\n");
	scanf("%d",&c);
	if(c==1)
	{
		if(head1==NULL)
			head1=newnode;
		else
		{
			temp=head1;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
	else if(c==2)
	{
		if(head2==NULL)
			head2=newnode;
		else
		{
			temp=head2;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
	else
		printf("Invalid choice\n");
}

void display(struct node *head)
{
	struct node *temp=head;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
	}
}

void count()
{
	int count1=0,count2=0;
	struct node *temp1=head1, *temp2=head2;
	while(temp1!=NULL)
	{
		count1++;
		temp1=temp1->next;
	}
	printf("\nNumber of nodes in Linked List 1: %d", count1);
	while(temp2!=NULL)
	{
		count2++;
		temp2=temp2->next;
	}
	printf("\nNumber of nodes in Linked List 2: %d", count2);
}

void concate()
{
	struct node *temp1=head1, *temp2;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp1->next=head2;
	temp2=head1;
	printf("Concatenated List:\n");
	while(temp2!=NULL)
	{
		printf("%d\t", temp2->data);
		temp2=temp2->next;
	}
}

void reverse(struct node *head)
{
	struct node *current, *prev, *next, *temp;
	prev=NULL;                            //prev points NULL which is before the first node of linked list
	current=head;
	while(current!=NULL)
	{
		next=current->next;          //next will point to one node ahead of current node
		current->next=prev;          //current node will point to one node behind itself
		prev=current;                //prev at same node as current (shifted ahead)
		current=next;                //current at same node as next (shifted ahead)
	}
	head=prev;                          //last node becomes head node
	temp=head;
	while(temp!=NULL)
	{
	       printf("%d\t", temp->data);
	       temp=temp->next;
	}
}

int search(struct node *head, int ele)
{
	struct node *temp=head;

	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

int main()
{
	int choice,ele,x,sele,b;
	clrscr();
	do
	{
		printf("\n1.Insert\n2.Display\n3.Count\n4.Concatenate\n5.Reverse\n6.Search\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			printf("Enter element to be inserted:");
			scanf("%d", &ele);
			insert(ele);
			break;
			case 2:
			printf("Choose a list:\n1.Linked List 1\n2.Linked List 2\n");
			scanf("%d", &x);
			if(x==1)
			display(head1);
			else
			display(head2);
			break;
			case 3:
			count();
			break;
			case 4:
			concate();
			break;
			case 5:
			printf("Choose a list:\n1.Linked List 1\n2.Linked List 2\n");
			scanf("%d", &x);
			if(x==1)
			reverse(head1);
			else
			reverse(head2);
			break;
			case 6:
			printf("Enter element to be searched:");
			scanf("%d", &sele);
			printf("Choose a list:\n1.Linked List 1\n2.Linked List 2\n");
			scanf("%d", &x);
			if(x==1)
			b=search(head1,sele);
			else
			b=search(head2,sele);
			if(b==1)
			printf("Element found\n");
			else
			printf("Element not found");
			break;
			default:
			printf("Invalid choice\n");
			break;
		}
	}while(choice!=8);
	return 0;
}
