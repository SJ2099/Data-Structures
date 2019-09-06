#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL, *small, *large, *t=NULL;

void insert_element(int);
void inorder_traversal(struct node *);
void preorder_traversal(struct node *);
void postorder_traversal(struct node *);
struct node* findmin(struct node *);
struct node* delete_element(struct node *,int);
struct node* find_smallest(struct node *);
struct node* find_largest(struct node *);
int count_total(struct node *);
int count_leaf(struct node *);
int count_internal(struct node *);
int tree_height(struct node *);
struct node* search(struct node *,int);
int main()
{
	int choice, x;
	clrscr();
	do
	{
	printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Delete\n6.Find smallest element\n7.Find largest element\n8.Count total nodes\n9.Count external(leaf) nodes\n10.Count internal nodes\n11.Height of tree\n12.Search\n13.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		insert_element(x);
		break;
		case 2:
		printf("Inorder Traversal:\n");
		inorder_traversal(root);
		break;
		case 3:
		printf("Preorder Traversal:\n");
		preorder_traversal(root);
		break;
		case 4:
		printf("Postorder Traversal:\n");
		postorder_traversal(root);
		break;
		case 5:
		printf("Enter node to delete:");
		scanf("%d", &x);
		t=delete_element(root,x);
		if(t!=NULL)
		printf("node deleted\n");
		break;
		case 6:
		small=find_smallest(root);
		printf("Smallest element is %d\n", small->data);
		break;
		case 7:
		large=find_largest(root);
		printf("Largest element is %d\n", large->data);
		break;
		case 8:
		printf("Total no. of nodes is %d\n",count_total(root));
		break;
		case 9:
		printf("Total no. of external nodes is %d\n",count_leaf(root));
		break;
		case 10:
		printf("Total no. of internal nodes is %d\n",count_internal(root));
		break;
		case 11:
		printf("Height of tree is %d\n",tree_height(root));
		break;
		case 12:
		printf("Enter element to search:");
		scanf("%d", &x);
		if(search(root,x)!=NULL)
			printf("Node found\n");
		else
			printf("Node not found\n");
		break;
		case 13:
		exit(1);
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=14);
	getch();
	return 0;
}

void insert_element(int x)                           //without recursion
{       struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter element to insert:");
	scanf("%d", &x);
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
		struct node *temp1=root,*temp2=NULL;
		while(temp1!=NULL)
		{
			temp2=temp1;
			if(x<temp1->data)
				temp1=temp1->left;
			else
				temp1=temp1->right;
		}
		if(x<temp2->data)
		temp2->left=newnode;
		else
		temp2->right=newnode;
	}
	printf("%d inserted",x);
}
void inorder_traversal(struct node *root)          //can be done using push,pop functions
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		printf("%d\t",root->data);
		inorder_traversal(root->right);
	}
}
void preorder_traversal(struct node *root)          //can be done using push,pop functions
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		inorder_traversal(root->left);
		inorder_traversal(root->right);
	}
}
void postorder_traversal(struct node *root)          //can be done using push, pop functions
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		inorder_traversal(root->right);
		printf("%d\t",root->data);
	}
}
struct node* findmin(struct node *root)        //to find min value node in right subtree
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
struct node* delete_element(struct node *root,int x)               //type of fn is struct node* as it returns root (after recursion root changes for each subtree)
{
	if(root==NULL)
		printf("Tree is empty\n");
	else if(x<root->data)
		root->left=delete_element(root->left,x);               //returns left child of current root ->true for every recursive call
	else if(x>root->data)
		root->right=delete_element(root->right,x);              //returns right child of current root ->true for every recursive call
	else
	{                //when x==root->data
	if(root->left==NULL && root->right==NULL)     //case 1:leaf node
	{
		free(root);                      //delete root; ->for c++
		root=NULL;                    //value in root ptr was deleted but it still had its addr so we set it to null
	}
	else if(root->left==NULL)       //case 2 :one child
	{
		struct node *temp=root;              //root of current subtree !
		root=root->right ;                   //setting right child of current subtree as current subtree root
		free(temp);
	}
	else if(root->right==NULL)
	{
		struct node *temp=root;
		root=root->left;
		free(temp);
	}
	else                     //case 3 :two children
	{
		struct node *temp=findmin(root->right);
		root->data=temp->data;
		root->right=delete_element(root->right,temp->data);       //will return NULL after all/any recursions
	}
	}
	return root;
}
struct node* find_smallest(struct node *root)
{
	if(root==NULL || root->left==NULL)
	{
		return root;
	}
	return find_smallest(root->left);
}
struct node* find_largest(struct node *root)
{
	if(root==NULL || root->right==NULL)
		return root;

	return find_largest(root->right);
}
int count_total(struct node *root)          //integer i.e, count is returned to the fn
{
	if(root==NULL)
		return 0;
	else
		return (count_total(root->left)+count_total(root->right)+1);
}
int count_leaf(struct node *root)           //external nodes
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)          //including counting only leaf nodes
		return 1;
	else
		return (count_leaf(root->left)+count_leaf(root->right));  //both subtree leaf nodes except root node
}
int count_internal(struct node *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))          //excluding counting leaf nodes
		return 0;
	else
		return (count_internal(root->left)+count_internal(root->right)+1);          //both subtree internal nodes including root node
}
int tree_height(struct node *root)
{
	int lheight,rheight;
	if(root==NULL)
		return -1;
	else
	{
	lheight=tree_height(root->left);
	rheight=tree_height(root->right);
	if(lheight>rheight)
		return(lheight+1);
	else
		return(rheight+1);
	}
}
struct node* search(struct node *root,int x)
{
	if(root==NULL)
		return root;
	else if(root->data==x)
		return root;
	else
	{
		if(x<=root->data)
			return search(root->left,x);
		else
			return search(root->right,x);
	}
}
