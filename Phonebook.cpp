#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

fstream phonebook;

struct contacts
{
	string name;
	string number;
	string email;
	contacts*link;
 	contacts()
	{
		link=NULL;
	}
};

class directory
{
	contacts *start,*cur,*temp;
	public:

	directory()
	{
		start=NULL;
	}
	create_file(string n,string num,string em)
	{
 		if(start==NULL)
 		{
			start=new contacts;
 			start->link=NULL;
 			start->name=n;
 			start->number=num;
 			start->email=em;
 			phonebook.open ("directory.txt",ios::out | ios::app);
 			phonebook<<"Name:_"<<start->name<<"__|__email:_"<<start->email<<"__|__PhoneNumber:_"<<start->number<<endl;
 			phonebook.close();
 		}
 		else
 		{
 			cur=start;
 			while(cur->link!=NULL)
 			{
				cur=cur->link;
 			}
 		temp=new contacts;
 		temp->name=n;
 		temp->number=num;
 		temp->email=em;
 		temp->link=NULL;
 		cur->link=temp;
 		phonebook.open ("directory.txt",ios::out | ios::app);
 		phonebook<<"Name:_"<<temp->name<<"__|__email:_"<<temp->email<<"__|__PhoneNumber:_"<<temp->number<<endl;
		phonebook.close();
 		}
 	}
	
	void terminating_file(string n)
 	{
		cur=start;
 		if(start->name==n)
 		{
 			temp=start;
 			start=start->link;
 			delete temp;
 		}
 		else
 		{
 			while(cur->name!=n)
 			{
 				if(cur->link==NULL)
 				{
 					cout<<"Any case of"<<n<<" does not exist"<<endl;
 					return ;
 				}
 				temp=cur;
 				cur=cur->link;
 			}
 			temp->link=cur->link;
 			delete cur;
 		}

	}
	
	void search(string n)
	{
		cur=start;
		while(cur!=NULL)
		{
			if(cur->name==n)
			{
				char mod;
				cout<<"\n\t_________DATA FOUND__________\n\n";
				cout<<"Name : "<<cur->name<<endl;
				cout<<"email : "<<cur->email<<endl;
				cout<<"Phone # : "<<cur->number<<endl;
				cout<<"\nDo You want to modify Phone Number (y/n) : ";
				cin>>mod;
				if(mod=='y' || mod=='Y')
				{
					cout<<"Enter New Phone Number ";
					cin>>cur->number;
					cout<<"\n\t_________Data Updated________"<<endl;
				}
			break;
			}
			cur=cur->link;
		}
		if(cur==NULL)
			cout<<"\n\t_______DATA NOT FOUND_________\n\n";
	}
	void print_now()
	{
		cur=start;
 		int c;
 		cout<<"Person #"<<" ---> Name \tNumber \tEmail"<<endl;
 		for(c=1;cur->link!=NULL;c++)
 		{
			cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->email<<endl;
    		cur=cur->link;
 		}
 		cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->email<<endl;
	}
	
	void print()
	{
		string s;
		phonebook.open("directory.txt",ios::in);
		while(!phonebook.eof())
		{
			phonebook>>s;
			cout<<s<<"\n";
		}
		phonebook.close();
	}
};


int main()
{
	directory l1;
	int nooffiles,i,p,ch;
	string n,nm,em;
	cout<<"\n\t===================================================================\n\n";
	cout<<"\t\t\t WELCOME TO PHONEBOOK\n";
	cout<<"\n\t===================================================================\n\n";
	cout<<"\n\t===================================================================\n\n";
	cout<<"\n\t\t ** SAVE ** DELETE ** SEARCH AND UPDATE ** DISPLAY **\n";
	cout<<"\n\t===================================================================\n\n";
	cout<<"\n\t===================================================================\n\n";
	
	do
	{
		cout<<"\n\nChoose the task you wanna perform"<<endl;
		cout<<"\n1-Save New Contacts\n";
		cout<<"2-Delete Any Contact"<<endl;
		cout<<"3-Search and Modify Contacts"<<endl;
		cout<<"4-Display the entire Phonebook"<<endl;
		cout<<"5-Exit Application\n"<<endl;
		cin>>ch;
		system("CLS");
		switch(ch)
		{
			case 1: 
				cout<<"\n\t============================SAVE NEW PHONE NUMBERS============================\n\n";
				cout<<"\tHow many numbers you want to save?"<<endl;
				cin>>nooffiles;
				for(i=1;i<=nooffiles;i++)
				{
					cout<<"\nEnter the details of new contact\n";
 					cout<<"\n\tEnter Name \t";
 					cin>>n;
 					cout<<"\n\tEnter Phone number \t";
 					cin>>nm;
 					cout<<"\n\tEnter Email \t";
 					cin>>em;
 					l1.create_file(n,nm,em);

 					cout<<"\nPhone Number of "<<n<<" has been Saved in your Phonebook! \n"; 
				}
				break;
			
			case 2:
 				cout<<"\n\t=========================DELETE CONTACT============================\n\n";
 				cout<<"\nEnter Name of person whose phone number you want to delete\n";
 				cin>>n;
 				l1.terminating_file(n);
 				cout<<"\nPhone Number of "<<n<<" has been removed from your Phonebook! \n";
 				break;
 			
			case 3:
 				cout<<"\n\t=====================SEARCH AND UPDATE CONTACTS=====================\n\n";
 				cout<<"Enter Name of the person to be searched from Phonebook\t";
 				cin>>n;
 				l1.search(n);
 				break;
			
			case 4:
				cout<<"\n\t=====================DISPLAY THE ENTIRE PHONEBOOK============================\n\n";
 				l1.print();
 				break;
 
 			case 5:
 				cout<<"\n\t====================List of Contacts added recently:======================\n\n";
 				l1.print_now();
 				break;
 			
			 default:
 				cout<<"\t----------Invalid Choice----------\n";
		}
	}
	while(ch!=5);
	cout<<"\nTHANK YOU!"<<endl;
	getch();
}

