#include<stdio.h>
#include<conio.h>
void insert();
void insert_sorted();
void del();
void delete_sorted();
void merge_unsorted();
void merge_sorted();
int i,j,a[10],a1[10],a2[10],amerge[20],n,n1,n2,m,num,p=0,index=0,index_first=0,index_second=0;

int main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n1.Insert at location\n2.Insert in sorted array(asc)\n3.Delete at location\n4.Delete from sorted array(asc)\n5.Merging unsorted arrays\n6.Merging sorted arrays(asc)\n7.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	if(choice!=6 && choice !=7){
	printf("Enter size of array:");
	scanf("%d", &n);
	printf("Enter elements of array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	}
	switch(choice)
	{
		case 1:
		insert();
		break;
		case 2:
		insert_sorted();
		break;
		case 3:
		del();
		break;
		case 4:
		delete_sorted();
		break;
		case 5:
		merge_unsorted();
		break;
		case 6:
		merge_sorted();
		break;
		default:
		printf("Invalid Choice\n");
		break;
	}
	}while(choice!=7);

	return 0;
}
void insert()
{
	printf("Enter number to be inserted:");
	scanf("%d", &num);
	printf("Enter position at which number is to be inserted:");
	scanf("%d", &p);
	for(i=n-1;i>=p;i--)                           //shifting array elements with index > p to make empty space at p for insertion
	{
		a[i+1]=a[i];
	}
	a[p]=num;
	n=n+1;                             	//incrementing array size after insertion
	printf("Array after insertion of number:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
void insert_sorted()
{
	printf("Enter number to be inserted:");
	scanf("%d", &num);
	for(i=0;i<n;i++)
	{
		if(a[i]>num)
		{
			for(j=n-1;j>=i;j--)   //shifting array elements greater than no. to be inserted to make empty space for insertion
			{
				a[j+1]=a[j];
			}
			a[i]=num;
			break;
		}
	}
	n=n+1;
	printf("Array after insertion of number:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
void del()
{
	printf("Enter position from which number is to be deleted:");
	scanf("%d", &p);
	for(i=p;i<n-1;i++)                                            //shifting array elements to delete element at entered pition
	{
		a[i]=a[i+1];
	}
	n=n-1;                                             //decrementing size of array by 1 after deletion
	printf("Array after deletion:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
void delete_sorted()
{
	printf("Enter number to be deleted:");
	scanf("%d", &num);
	for(i=0;i<n;i++)
	{
		if(a[i]==num)
		{
			for(j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
		}
	}
	n=n-1;
	printf("Array after deletion:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
void merge_unsorted()
{
	printf("Enter size of 2nd array:");
	scanf("%d", &n2);
	printf("Enter elements of 2nd array:\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d", &a2[i]);
	}
	m=n+n2;
	for(i=0;i<n;i++)
	{
		amerge[index]=a[i];
		index++;
	}
	for(i=0;i<n2;i++)
	{
		amerge[index]=a2[i];
		index++;
	}
	printf("Merged array is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t", amerge[i]);
	}
}
void merge_sorted()
{
	printf("Enter size of 1st (sorted) array:");
	scanf("%d", &n1);
	printf("Enter elements of 1st (sorted) array:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d", &a1[i]);
	}
	printf("Enter size of 2nd (sorted) array:");
	scanf("%d", &n2);
	printf("Enter elements of 2nd (sorted) array:\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d", &a2[i]);
	}
	m=n1+n2;
	while(index_first<n1 && index_second<n2)
	{
			if(a1[index_first]<a2[index_second])
			{
				amerge[index]=a1[index_first];
				index_first++;
				index++;
			}
			else
			{
				amerge[index]=a2[index_second];
				index_second++;
				index++;
			}
	}
	if(index_first==n)			                //if elements of first array are over and second array are remaining
	{
		while(index_second<n2)
		{
			amerge[index]=a2[index_second];
			index_second++;
			index++;
			}
	}
	if(index_second==n2)                               //if elements of second array are over and first array are remaining
	{
		while(index_first<n1)
		{
			amerge[index]=a1[index_first];
			index_first++;
			index++;
			}
	}
	printf("Merged array is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t", amerge[i]);
	}
}
