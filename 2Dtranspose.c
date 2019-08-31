#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,a[3][3],t[3][3];
	clrscr();
	printf("Enter elements of 3x3 matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Elements of matrix are:\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d  ",a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[i][j]=a[j][i];
		}
	}
	printf("\nTranspose of matrix:\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d  ",t[i][j]);
		}
	}
	getch();
	return 0;
}
