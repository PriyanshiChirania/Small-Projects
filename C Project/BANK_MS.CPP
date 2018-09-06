#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
void creation(); 
void deposit(); 
void withdraw();
void bal();
int a=0,i = 101;
struct bank
{
	int no;
	char name[20];
	float bal;
	float dep;
}s[20];
	void main()
       {
		  int ch;
		  while(1)
			{
			  clrscr();
			  printf("________________________________________________________________________________");
			  printf("\n                                  YOUR BANK                       ");
			  printf("\n                        ____________________________________                  ");
			  printf("\n                              Jaipur , Rajasthan.                        ");
			  printf("\n--------------------------------------------------------------------------------");
			  printf("\n\n\n\t\t\t    1.Create an Account");
			  printf("\n\t\t\t    2.Deposit Money");
			  printf("\n\t\t\t    3.Withdraw Money");
			printf("\n\t\t\t    4.Balance Enquiry");
			printf("\n\t\t\t    5.Exit");
			printf("\n\n\t\t\t     Enter Your Choice: ");
			      scanf("%d",&ch);
			      switch(ch)
				       {
					      case 1: creation();
							 break;
					      case 2: deposit();
							 break;
					      case 3: withdraw();
							 break;
					      case 4: bal();
							 break;
					      case 5: exit(0);
							 defalut: printf("Enter 1-5 only");
							 getch();
					}
			 }
	}
	     void creation()
	{          clrscr();
		   printf("\n\t\t\t ----------------------");
		   printf("\n\t\t\t ACCOUNT CREATION ");
		   printf("\n\t\t\t ----------------------");
		   printf("\n\n\t\t\t Account Number Allotted is:%d",i);
			      s[a].no = i;
		   printf("\n\t\t\t Enter Name:");
			      scanf("%s",s[a].name);
		   printf("\n\t\t\t Minimum deposit is Rs.500");
			      s[a].dep=500;
			      a++;
			      i++;
			      getch();
	 }
	      void deposit()
	{          clrscr();
		   int no,b=0,m=0;
		   float aa;
		   printf("\n\t\t\t ----------------------");
		   printf("\n\t\t\t DEPOSIT ");
		   printf("\n\t\t\t ----------------------");
		   printf("\n\n\t\t\t Enter the Account Number:");
		   scanf("%d",&no);
		   for(b=0;b<i;b++)
		       {
			   if(s[b].no == no)
			       m = b;
		       }
			   if(s[m].no == no)
			     {
					printf("\n\n\t\t\t Account Number : %d",s[m].no);
					printf("\n\t\t\t Name : %s",s[m].name);
					printf("\n\t\t\t Deposit : %f",s[m].dep);
					printf("\n\t\t\t Amount to be deposited now:");
					scanf("%f",&aa);
					s[m].dep+=aa;
					printf("\n\n\t\t\t Total Amount is :%0.2f",s[m].dep);
					getch();
			     }
			    else
			     {
				       printf("\n\n\t\t\t ACCOUNT NUMBER IS INVALID");
				       getch();
			      }
	 }
	     void withdraw()
	 {          clrscr();
		    int no,b=0,m=0;
		    float aa;
		    printf("\n\t\t\t ----------------------");
		    printf("\n\t\t\t WITHDRAW ");
		    printf("\n\t\t\t ----------------------");
		    printf("\n\n\t\t\t Enter the Account Number:");
		    scanf("%d",&no);
		    for(b=0;b<i;b++)
			{
			       if(s[b].no == no)
				 m = b;
			}
			      if(s[m].no == no)
				 {
					printf("\n\n\t\t\t Account Number : %d",s[m].no);
					printf("\n\t\t\t Name : %s",s[m].name);
					printf("\n\t\t\t Deposit : %f",s[m].dep);
					printf("\n\t\t\t Amount to be Withdraw Now:");
					scanf("%f",&aa);
					if(s[m].dep<aa+500)
					   {
						  printf("\n\n\t\t\t CANNOT WITHDRAW YOUR ACCOUNT HAS MINIMUM BALANCE");
						  getch();
					   }
					  else
					   {
						  s[m].dep-=aa;
						  printf("\n\n\t\t\t The Balance Amount is:%0.2f",s[m].dep);
					    }
				 }
			       else
				{
				      printf("\n\n\t\t\t INVALID");
				      getch();
				}
				      getch();
	  }
		void bal()
	  {       clrscr();
		  int no,b=0,m=0;
		  float aa;

		  printf("\n\t\t\t ----------------------");
		  printf("\n\t\t\t BALANCE ENQUIRY ");
		  printf("\n\t\t\t ----------------------");
		  printf("\n\n\t\t\t Enter the Account Number:");
		  scanf("%d",&no);
		  for(b=0;b<i;b++)
		      {
			   if(s[b].no == no)
			     m = b;
		      }
			   if(s[m].no==no)
			      {
				    printf("\n\n\t\t\t Account Number : %d",s[m].no);
				    printf("\n\t\t\t Name : %s",s[m].name);
				    printf("\n\t\t\t Deposit : %f",s[m].dep);
				    getch();
			      }
			     else
			     {
				    printf("\n\n\t\t\t INVALID");
				    getch();
			      }
	    }