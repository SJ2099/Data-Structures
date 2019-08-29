#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[20],i,j,n,small,large,second_large,flag=0,pos=0;
void display();
void smallest();
void second_largest();
void duplicate();
void number();
void mean();
int main()
{
	int choice;
	clrscr();
	printf("Enter size of array:");
	scanf("%d", &n);
	printf("Enter elements of array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	do
	{
	printf("\n1.Display\n2.Find position of smallest element\n3.Find position of second largest element\n4.Find duplicate\n5.Form a number from array elements\n6.Find mean\n7.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		display();
		break;
		case 2:
		smallest();
		break;
		case 3:
		second_largest();
		break;
		case 4:
		duplicate();
		break;
		case 5:
		number();
		break;
		case 6:
		mean();
		break;
		default:
		printf("Invalid Choice\n");
		break;
	}
	}while(choice!=7);
	return 0;
}
void display()
{
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
void smallest()
{       small=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<small)
		{
			small=a[i];
			pos=i;
		}
	}
	printf("\nSmallest element in the array: %d", small);
	printf("\nPosition of smallest element: %d", pos);
}
void second_largest()
{       large=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>large)
		{
			large=a[i];
		}
	}
	//second_largest=a[1];
	for(i=0;i<n;i++)
	{
		if(a[i]!=large)
		{
			if(a[i]>second_large)
			second_large=a[i];
			pos=i;
		}
	}
	printf("\nSecond largest element in the array: %d", second_large);
	printf("\nPosition of second largest element: %d", pos);
}
void duplicate()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j] && i!=j)
			{
				flag=1;
				printf("\nDuplicate elements found at positions %d & %d",i,j);
			}
		}
	}
	if(flag==0)
	printf("\nDuplicate elements not found\n");
}
void number()
{
	int k=0,num=0;
	while(k<n)
	{
		num=num+a[k]*pow(10,k);
		k++;
	}
	printf("\nThe number is: %d", num);
}
void mean()
{
	int sum=0;
	float mean;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	mean=(float)sum/n;
	printf("\nSum of array elements: %d", sum);
	printf("\nMean of array elements: %.2f", mean);
}
	
