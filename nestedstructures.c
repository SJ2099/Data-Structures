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
	struct student std;
	clrscr();
	printf("\nEnter roll no.:");
	scanf("%d", &std.roll_no);
	printf("\nEnter name:");
	scanf("%s %s %s", std.name.first,std.name.middle,std.name.last);
	printf("\nEnter DOB(dd mm yyyy):");
	scanf("%d %d %d", &std.dob.dd,&std.dob.mm,&std.dob.yy);
	printf("\nEnter year:");
	scanf("%s", std.year);
	printf("\nEnter department:");
	scanf("%s", std.dept);
	printf("\nSTUDENT DETAILS\n");
	printf("***************************");
	printf("\nRoll no.: %d", std.roll_no);
	printf("\nName:%s %s %s", std.name.first,std.name.middle,std.name.last);
	printf("\nDate of Birth: %d-%d-%d", std.dob.dd,std.dob.mm,std.dob.yy);
	printf("\nYear: %s", std.year);
	printf("\nDepartment: %s", std.dept);
	getch();
	return 0;
}
	
