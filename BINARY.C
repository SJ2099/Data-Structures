#include<stdio.h>
#include<conio.h>
int smallest(int data[],int k,int n);
void selection_sort(int data[],int n);
void binary_search(int data[],int lb, int ub,int item);
int main(){
	int data[50],i,n,lb,ub,num;
	clrscr();
	printf("Enter no. of elements:");
	scanf("%d", &n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	selection_sort(data,n);
	printf("Sorted array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",data[i]);
	}
	printf("\nEnter element to be searched:");
	scanf("%d", &num);
	lb=0;
	ub=n-1;
	binary_search(data,lb,ub,num);

	getch();
	return 0;
}
int smallest(int data[],int k,int n)
{
	int pos=k,small=data[k],i;
	for(i=k+1;i<n;i++)
	{
		if(data[i]<small)
		{
			small=data[i];
			pos=i;
		}
	}
	return pos;
}
void selection_sort(int data[],int n)
{
	int k,pos,temp;
	for(k=0;k<n;k++)
	{
		pos=smallest(data,k,n);
		temp=data[k];
		data[k]=data[pos];
		data[pos]=temp;
	}
}
void binary_search(int data[],int lb,int ub,int item)
{
	int beg=lb,end=ub,mid=((beg+end)/2);
	while(beg<=end && data[mid]!=item)
	{
		if(item<data[mid])
			end=mid-1;
		if(item>data[mid])
			beg=mid+1;
		mid=(beg+end)/2;
	}
	if(data[mid]==item)
		printf("Element found at position:%d",mid+1);
	else
		printf("Element not found");
}
