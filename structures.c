#include<stdio.h>
#include<conio.h>
int main()
{
	typedef struct complex                            //syntax: typedef <existing_data_type> <new_data_type>
	{
		int real,imgn;
	}cmplx;
	cmplx c1,c2,sum_c,sub_c;        
	int choice;
	clrscr();
	do
	{
		printf("\n1.Read complex numbers\n2.Display complex numbers\n3.Addition\n4.Subtraction\n5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			printf("Enter real and imaginary parts of 1st complex no.:");
			scanf("%d %d", &c1.real,&c1.imgn);                                   //to access structure member var.-> &struct_var.member_name
			printf("Enter real and imaginary parts of 2nd complex no.:");
			scanf("%d %d", &c2.real,&c2.imgn);
			break;
			case 2:
			printf("1st complex no.= %d+%di", c1.real,c1.imgn);
			printf("\n2nd complex no.= %d+%di", c2.real,c2.imgn);
			break;
			case 3:
			sum_c.real=c1.real+c2.real;
			sum_c.imgn=c1.imgn+c2.imgn;
			printf("\nAddition of %d+%di and %d+%di is %d+%di",c1.real,c1.imgn,c2.real,c2.imgn,sum_c.real,sum_c.imgn);
			break;
			case 4:
			sub_c.real=c1.real-c2.real;
			sub_c.imgn=c1.imgn-c2.imgn;
			printf("Subtraction of %d+%di from %d+%di is %d+%di",c1.real,c1.imgn,c2.real,c2.imgn,sub_c.real,sub_c.imgn);
			break;
			case 5:
			exit(1);
			default:
			printf("Invalid choice\n");
			break;
		}
	}while(choice!=5);
	getch();
	return 0;
}
	
