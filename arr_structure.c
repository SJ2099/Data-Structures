#include<stdio.h>
#include<conio.h>
int main()
{
	typedef struct 
	{
		char first[20];
		char middle[20];
		char last[20];
	}NAME;
	typedef struct 
	{
		int dd;
		int mm;
		int yy;
	}DATE;
	struct student
	{
		int roll_no;
		NAME name;
		DATE dob;
		char year[10];
		char dept[50];
	};
	struct student std[50];
	int n,i,num;
	clrscr();
	printf("Enter number of students:");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
	printf("\nEnter roll no.:");
	scanf("%d", &std[i].roll_no);
	printf("\nEnter name:");
	scanf("%s %s %s", std[i].name.first,std[i].name.middle,std[i].name.last);
	printf("\nEnter DOB(dd mm yyyy):);
	scanf("%d %d %d", &std[i].dob.dd,&std[i].dob.mm,&std[i].dob.yy);
	printf("\nEnter year:");
	scanf("%s", std[i].year);
	printf("\nEnter department:");
	scanf("%s", std[i].dept);
	}
	for(i=0;i<n;i++)
	{
	printf("**********\nDetails of student %d**********",i+1);
	printf("\nRoll no.: %d", std[i].roll_no);
	printf("\nName:%s %s %s", std[i].name.first,std[i].name.middle,std[i].name.last);
	printf("\nDate of Birth: %d-%d-%d", std[i].dob.dd,std[i].dob.mm,std[i].dob.yy);
	printf("\nYear: %s", std[i].year);
	printf("\nDepartment: %s", std[i].dept);
	}
	printf("\nEnter student number whose record is to be edited:");
	scanf("%d", &num);
	num=num-1;
	printf("\nEnter new roll no.:");
	scanf("%d", &std[num].roll_no);
	printf("\nEnter new name:");
	scanf("%s %s %s", std[num].name.first,std[num].name.middle,std[num].name.last);
	printf("\nEnter new DOB(dd mm yyyy):");
	scanf("%d %d %d", &std[num].dob.dd,&std[num].dob.mm,&std[num].dob.yy);
	printf("\nEnter new year:\n");
	scanf("%s", std[num].year);
	printf("\nEnter new department:");
	scanf("%s", std[num].dept);
	for(i=0;i<n;i++)
	{
	printf("**********\nDetails of student %d**********",i+1);
	printf("\nRoll no.: %d", std[i].roll_no);
	printf("\nName:%s %s %s", std[i].name.first,std[i].name.middle,std[i].name.last);
	printf("\nDate of Birth: %d-%d-%d", std[i].dob.dd,std[i].dob.mm,std[i].dob.yy);
	printf("\nYear: %s", std[i].year);
	printf("\nDepartment: %s", std[i].dept);
	}
	
	getch();
	return 0;
}
