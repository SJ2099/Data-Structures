#include<stdio.h>
#include<conio.h>
int main()
{
	int sales[5][3],i,j,total_sales=0;
	clrscr();
	printf("Enter Data\n*************\n");
	for(i=0;i<5;i++)
	{
		printf("Enter the sales of 3 products by salesman %d:", i+1);
		for(j=0;j<3;j++)
		{
			scanf("%d", &sales[i][j]);
		}
	}
	for(i=0;i<5;i++)                                     //total sales by each salesman
	{       total_sales=0;
		for(j=0;j<3;j++)
		{
			total_sales=total_sales+sales[i][j];
		}
		printf("Total sales by salesman %d: %d\n", i+1,total_sales);
	}
	for(i=0;i<3;i++)                                     //total sales of each item
	{       total_sales=0;
		for(j=0;j<5;j++)
		{
			total_sales=total_sales+sales[j][i];
		}
		printf("Total sales of item %d: %d\n", i+1,total_sales);
	}
	getch();
	return 0;
}
