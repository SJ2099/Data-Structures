#include<stdio.h>
#include<conio.h>
#include<stdlib.h>                 //for exit()
void pas();
void zdiagonal();
int main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n1.Pascal's Triangle\n2.Square matrix with zero on diagonals\n3.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		pas();
		break;
		case 2:
		zdiagonal();
		break;
		case 3:
		exit(1);
		default:
		printf("Invalid Choice\n");
		break;
	}
	}while(choice!=4);
	getch();
	return 0;
}
void pas()
{
	int a[7][7]={0};
	int i,j,col,row;
	a[0][0]=a[1][0]=a[1][1]=1;  //2 rows are fully done
	for(row=2;row<=7;row++)
	{
		a[row][0]=1; 			//first column is entirely 1...
		for(col=1;col<=row;col++)
		{
			a[row][col]=a[row-1][col-1]+a[row-1][col];
		}
	}
	for(i=0;i<7;i++)
	{
		printf("\n");
		for(j=0;j<=i;j++)
		{
			printf("%d\t", a[i][j]);
		}
	}
}
void zdiagonal()
{
	int a[5][5],dim,i,j;
	printf("Enter number of rows and columns of sqaure matrix:");
	scanf("%d", &dim);
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim;j++)
		{
			if(i==j)                       //diagonal
			a[i][j]=0;
			else if(i>j)                  //lower right triangle
			a[i][j]=-1;
			else                          //upper right triangle
			a[i][j]=1;
		}
	}
	printf("The required matrix is:");
	for(i=0;i<dim;i++)
	{	
		printf("\n");
		for(j=0;j<dim;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
}
