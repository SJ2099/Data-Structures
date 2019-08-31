#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void sum();
void mul();
int a[5][5],b[5][5],s[5][5],m[5][5],i,j,k,r1,c1,r2,c2,rf,cf;
int main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n1.Sum of corresponding elements\n2.Multiplication\n3.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	if(choice==3)
	{
		exit(1);
	}
	printf("Enter no. of rows of 1st matrix:");
	scanf("%d", &r1);
	printf("Enter no. of columns of 1st matrix:");
	scanf("%d", &c1);
	printf("Enter no. of rows of 2nd matrix:");
	scanf("%d", &r2);
	printf("Enter no. of columns of 2nd matrix:");
	scanf("%d", &c2);
	if(choice==1)
	{
		if(r1!=r2 || c1!=c2)
		{
			printf("\nNo. of rows and columns of both matrices should be equal\n");
			getch();
			exit(0);
		}
	}
	if(choice==2)
	{
		if(c1 !=r2)
		{
			printf("No. of columns in 1st matrix should be equal to no. of rows in 2nd matrix\n");
			getch();
			exit(0);
		}
	}
	printf("Enter elements of 1st matrix:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter elements of 2nd matrix:\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	switch(choice)
	{
		case 1:
		sum();
		break;
		case 2:
		mul();
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(choice!=3);
	getch();
	return 0;
}
void sum()
{
	rf=r1;
	cf=c1;
	printf("1st matrix is:\n");
	for(i=0;i<r1;i++)
	{
		printf("\n");
		for(j=0;j<c1;j++)
		{
			printf("%d\t", a[i][j]);
		}
	}
	printf("\n2nd matrix is:\n");
	for(i=0;i<r2;i++)
	{
		printf("\n");
		for(j=0;j<c2;j++)
		{
			printf("%d\t", b[i][j]);
		}
	}
	for(i=0;i<rf;i++)
	{
		for(j=0;j<cf;j++)
		{
			s[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("\nSum of the matrices:\n");
	for(i=0;i<rf;i++)
	{
		printf("\n");
		for(j=0;j<cf;j++)
		{
			printf("%d\t", s[i][j]);
		}
	}
}
void mul()
{
	rf=r1;                           //since c1=r2 !!!
	cf=c2;
	printf("1st matrix is:\n");
	for(i=0;i<r1;i++)
	{
		printf("\n");
		for(j=0;j<c1;j++)
		{
			printf("%d\t", a[i][j]);
		}
	}
	printf("\n2nd matrix is:\n");
	for(i=0;i<r2;i++)
	{
		printf("\n");
		for(j=0;j<c2;j++)
		{
			printf("%d\t", b[i][j]);
		}
	}
	for(i=0;i<rf;i++)
	{
		for(j=0;j<cf;j++)
		{
			m[i][j]=0;
			for(k=0;k<cf;k++)
			{
				m[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("\nMultiplication of matrices:\n");
	for(i=0;i<rf;i++)
	{
		printf("\n");
		for(j=0;j<cf;j++)
		{
			printf("%d\t", m[i][j]);
		}
	}
}
