#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
class hotel
{    int room_no,charge,food,oc,t,total,day;
    char name[30];
    char address[50];
    char phone[10];
    public:
    void main_menu();    //to dispay the main menu
    void add();        //to book a room
    void display();    //to display the customer record
    void rooms();    //to display alloted rooms
    void edit();    //to edit the customer record
    int check(int);    //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);    //to delete the record
    void pass();             //for entering password
    int bill();             //to calculate the total bill
    void display_bill();     //to display the total bill
};
hotel h;
void hotel::main_menu()
{    while(1)
     {
      int choice;
      clrscr();
       cout<<"________________________________________________________________________________";
       cout<<"\n                              The Raddison Hotel                       ";
       cout<<"\n                        ____________________________________                  ";
       cout<<"\n                            Mumbai , Maharashtra.                        ";
       cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\n\n\n\t\t\t1.Book A Room";
	cout<<"\n\t\t\t2.Customer Record";
	cout<<"\n\t\t\t3.Rooms Allotted";
	cout<<"\n\t\t\t4.Edit Record";
	cout<<"\n\t\t\t5.Calculate Bill";
	cout<<"\n\t\t\t6.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;

	switch(choice)
	{
	    case 1: add();
		    break;
	    case 2: display();
		    break;
	    case 3: rooms();
		    break;
	    case 4: edit();
		    break;
	    case 5: display_bill();
		    break;
	    case 6: exit(0);
	    default:
		    {
			cout<<"\n\n\t\t\tWrong choice!!!";
			cout<<"\n\n\t\t\tPress any key to continue!!";
			break;
		    }
	}
     }
getch();
}

void hotel::add()
{
    clrscr();
    int r,flag;
    ofstream fout("Record.dat",ios::app);
    cout<<"\n\t\t\t ----------------------";
    cout<<"\n\t\t\t Enter Customer Detalis";
    cout<<"\n\t\t\t ----------------------";
    cout<<"\n\n\t\t\t Room no: ";
    cin>>r;
    flag=check(r);

    if(flag)
	cout<<"\n\n\t\t Sorry..!!!Room is already booked";
    else
    {
	room_no=r;
	cout<<"\n\t\t\t Name: ";
	gets(name);
	cout<<"\n\t\t\t Address: ";
	gets(address);
	cout<<"\n\t\t\t Phone No: ";
	gets(phone);
	fout.write((char*)this,sizeof(hotel));
	cout<<"\n\n\t\t\t Room is booked!!!";
    }

    cout<<"\n\n\t\t\t Press any key to continue!!";
    getch();
    fout.close();
}

void hotel::display()
{
    clrscr();
    ifstream fin("Record.dat",ios::in);
    int r,flag;
    cout<<"\n\t\t Enter room no: ";
    cin>>r;

    while(!fin.eof())
    {
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
	    clrscr();
	    cout<<"\n\t\t\t ------------------";
	    cout<<"\n\t\t\t |Customer Details|";
	    cout<<"\n\t\t\t ------------------";
	    cout<<"\n\n\t\t\t Room no: "<<room_no;
	    cout<<"\n\t\t\t Name: "<<name;
	    cout<<"\n\t\t\t Address: "<<address;
	    cout<<"\n\t\t\t Phone no: "<<phone;
	    flag=1;
	    break;
	}
    }
    if(flag==0)
	cout<<"\n\n\t\t Sorry Room no. not found or vacant!!";
    cout<<"\n\n\t\t Press any key to continue!!";
    getch();
    fin.close();
}

void hotel::rooms()
{
    clrscr();
    ifstream fin("Record.dat",ios::in);
    cout<<"\n\t\t\t----------------------";
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t----------------------";
    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";
  while(fin.read((char*)this,sizeof(hotel)))
    {	cout<<"\n\n "<<room_no<<"\t\t"<<name;
	cout<<"\t\t"<<address<<"\t\t"<<phone;
    }
     cout<<"\n\n\n\t\t\tPress any key to continue!!";
     fin.close();
     getch();
}

void hotel::edit()
{
    clrscr();
    int choice,r;
    cout<<"\n\t -----------";
    cout<<"\n\t |EDIT MENU|";
    cout<<"\n\t -----------";
    cout<<"\n\n\t 1.Modify Customer Record";
    cout<<"\n\t 2.Delete Customer Record";
    cout<<"\n\n\t\t\t Enter your choice: ";
    cin>>choice;
    clrscr();
    cout<<"\n\t\t\t Enter room no: ";
    cin>>r;
    switch(choice)
    {  	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n\n\t\t\t\t Wrong Choice!!";
    }
    cout<<"\n\n\t\t\t Press any key to continue!!!";
    getch();
}

int hotel::check(int r)
{   int flag=0;
    ifstream fin("Record.dat",ios::in);
    while(!fin.eof())
    {
	fin.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{
	    flag=1;
		break;
	}
    }

    fin.close();
    return(flag);
}

void hotel::modify(int r)
{
    long pos,flag=0;
    fstream file("Record.dat",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {
	pos=file.tellg();
	file.read((char*)this,sizeof(hotel));
	if(room_no==r)
	{   cout<<"\n\t\t\t -------------------";
	    cout<<"\n\t\t\t |Enter New Details|";
	    cout<<"\n\t\t\t -------------------";
	    cout<<"\n\n\t\t\t Name: ";
	    gets(name);
	    cout<<"\n\t\t\t Address: ";
	    gets(address);
	    cout<<"\n\t\t\t Phone no: ";
	    gets(phone);

	    file.seekg(pos);
	    file.write((char*)this,sizeof(hotel));
	    cout<<"\n\n\t\t\t Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n\n\t\t Sorry Room no. not found or vacant!!";

    file.close();
}

void hotel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record.dat",ios::in);
    ofstream fout("temp.dat",ios::out);

    while(fin.read((char*)this,sizeof(hotel)))
    {

	if(room_no==r)
	{
	    cout<<"\n\t\t\t Name: "<<name;
	    cout<<"\n\t\t\t Address: "<<address;
	    cout<<"\n\t\t\t Pone No: "<<phone;
	    cout<<"\n\n\t\t Do you want to delete this record(y/n): ";
	    cin>>ch;

	    if(ch=='n')
	    fout.write((char*)this,sizeof(hotel));

	    flag=1;
	}
	else
	    fout.write((char*)this,sizeof(hotel));
    }

    fin.close();
    fout.close();

    if(flag==0)
	cout<<"\n\n\t\t Sorry room no. not found or vacant!!";
    else
    {
	remove("Record.dat");
	rename("temp.dat","Record.dat");
    }
}

void hotel::pass()
     {	  char passw[20];  int i=0;
	  cout<<"\n\n\t\t\t ENTER PASSWORD :";
	  while(i<5)
	  {
	  passw[i++]=getch();
	  cout<<"*";
	  }
	  passw[i]='\0';          getch();
	  if (strcmp(passw,"12345")==0)
	       h.main_menu();
	  else
	     {  cout<<"\n\t\t\t Incorrect Password";
		delay(100);
	       cout<<"\n\n\t\t\t Exit";
		 delay(100);
	       exit(0);
	    }
      }
int hotel::bill()
{  	 int b;
	  cout<<"\n 1.Super Luxary(Rs4000 per day)";
	  cout<<"\n 2.Luxary(Rs 3000 per day)";
	  cout<<"\n 3.Delux(Rs 2000 per day)";
	  cout<<"\n Enter Room type:";
	  cin>>b;
	  if(b==1)
	    charge=4000;
	  else  if(b==2)
		  charge=3000;
		  else  if(b==3)
			  charge=2000;
			  else{
			      cout<<"\n Wrong choice!!";
			      cout<<"\n Bill cannot be created ";
			}
	   cout<<"\n Enter the bill amount of restaurant:";
	   cin>>food;
	   cout<<"\n Enter other charges:";
	   cin>>oc;
	  cout<<"\n Enter number of days:";
	   cin>>day;
		t=charge * day;
	   total=(int)t + food + oc;
	   return(total);
	  getch();
	  }

void hotel::display_bill()
 { clrscr();
   int x;
   cout<<"\n________________________________________________________________________________";
   cout<<"\n                              The Raddison Hotel                       ";
   cout<<"\n                        ____________________________________                  ";
   cout<<"\n                            Mumbai , Maharashtra.                        ";
   cout<<"\n--------------------------------------------------------------------------------";
   x=bill();
       cout<<"\nBill Amount :: Rs "<<total;
   cout<<"\n\t\t\tTHANK YOU !!!!!";
   cout<<"\n\t\t\tVisit Again !";
   getch();
  }

void main()
{
    textbackground(WHITE);
    textcolor(BLUE);

    clrscr();
    cout<<"\n\t\t\t----------------------------";
    cout<<"\n\t\t\t| HOTEL MANAGEMENT PROJECT |";
    cout<<"\n\t\t\t----------------------------";
    delay(100);
    cout<<"\n\n\n\t\t------------------------------------------------";
    delay(100);
    cout<<"\n\n\t\t\tMade By:Member's of Group7";
    delay(100);
    cout<<"\n\t\t\t\t-Priyanshi Chirania";
    delay(100);
    cout<<"\n\t\t\t\t-Rajni Mehra";
    delay(100);
    cout<<"\n\t\t\t\t-Rashmi Ray";
    delay(100);
    cout<<"\n\t\t\t\t-Ria Vats";
    delay(100);
    cout<<"\n\t\t\t\t-Riddhi Gupta";
    delay(100);
    cout<<"\n\n\t\t------------------------------------------------";
    delay(100);
    cout<<"\n\n\t\t\tPress any key to continue!!";
    getch();
    h.pass();
}