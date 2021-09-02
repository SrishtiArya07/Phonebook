#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

fstream phonebook;

struct contactsnode
{
	string name;
	string number;
	string email;
	contactsnode* nextptr;
 	contactsnode()
	{
		nextptr = NULL;
	}
};

class directory
{
	contactsnode *headptr,*cur,*temp;
	public:
    directory()
	{
		headptr=NULL;
	}
	void create_file(string n,string num,string em)
	{
 		if(headptr==NULL)
 		{
            headptr=new contactsnode;
 			headptr->nextptr=NULL;
 			headptr->name=n;
 			headptr->number=num;
 			headptr->email=em;
 			phonebook.open ("contacts.txt",ios::out | ios::app);
 			phonebook<<"__NAME__"<<headptr->name<<"__|__EMAIL__"<<headptr->email<<"__|__NUMBER__"<<headptr->number<<"\n";
 			phonebook.close();
 		}
 		else
 		{
            cur=headptr;
 			while(cur->nextptr!=NULL)
 			{
				cur=cur->nextptr;
 			}
 		temp=new contactsnode;
 		temp->name=n;
 		temp->number=num;
 		temp->email=em;
 		temp->nextptr=NULL;
 		cur->nextptr=temp;
 		phonebook.open ("contacts.txt",ios::out | ios::app);
 		phonebook<<"\n__NAME__"<<temp->name<<"__|__EMAIL__"<<temp->email<<"__|__NUMBER__"<<temp->number<<"\n";
		phonebook.close();
 		}
 	}
    void terminating_file(string n)
 	{
		cur=headptr;
 		if(headptr->name==n)
 		{
 			temp=headptr;
 			headptr=headptr->nextptr;
 			delete temp;
 		}
 		else
 		{
 			while(cur->name!=n)
 			{
 				if(cur->nextptr==NULL)
 				{
 					cout<<"Any case of "<<n<<" does not exist"<<endl;
 					return ;
 				}
 				temp=cur;
 				cur=cur->nextptr;
 			}
 			temp->nextptr=cur->nextptr;
 			delete cur;
 		}
        fstream fout;
        phonebook.open("contacts.txt",ios::in);
        fout.open("temporary.txt",ios::out | ios::app);
        string s;
        while(!phonebook.eof()){
        	phonebook>>s;
        	if(s.find(n)==std::string::npos){
        		fout<<s;
        		fout<<"\n";
			}
			s="";
		}
        
        fout.close();
        phonebook.close();

        remove("contacts.txt");
        rename("temporary.txt", "contacts.txt");

	}
    void search(string n)
	{
		cur=headptr;
		while(cur!=NULL)
		{
			if(cur->name==n)
			{
				char mod;
				string oldno;
				cout<<"\n\t_________DATA FOUND__________\n\n";
				cout<<"Name : "<<cur->name<<endl;
				cout<<"email : "<<cur->email<<endl;
				cout<<"Phone number # : "<<cur->number<<endl;
				oldno=cur->number;
				cout<<"\nDo You want to modify Phone Number (y/n) : ";
				cin>>mod;
				if(mod=='y' || mod=='Y')
				{
					cout<<"Enter New Phone Number ";
					cin>>cur->number;
					
			        fstream fout;
        			phonebook.open("contacts.txt",ios::in);
        			fout.open("temporary.txt",ios::out | ios::app);
        	        string s;
        			while(!phonebook.eof()){
        				phonebook>>s;
        				if(s.find(oldno)==std::string::npos){
        					fout<<s;
        					fout<<"\n";
        				}
						else{
							fout<<"__NAME__"<<cur->name<<"__|__EMAIL__"<<cur->email<<"__|__NUMBER__"<<cur->number<<"\n";
						}
						s="";
					}
        			fout.close();
        			phonebook.close();

        			remove("contacts.txt");
        			rename("temporary.txt", "contacts.txt");
					
					cout<<"\n\t_________Data Updated________"<<endl;
				}
			break;
			}
			cur=cur->nextptr;
		}
		if(cur==NULL)
			cout<<"\n\t_______DATA NOT FOUND_________\n\n";
	}
	void print_now()
	{
		cur=headptr;
 		int c;
 		cout<<"Person #"<<" ---> Name \tNumber \tEmail"<<endl;
 		for(c=1;cur->nextptr!=NULL;c++)
 		{
			cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->email<<endl;
    		cur=cur->nextptr;
 		}
 		cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->email<<endl;
	}
	
	void print()
	{
		string s;
		phonebook.open("contacts.txt",ios::in);
		while(!phonebook.eof())
		{
			phonebook>>s;
			cout<<s<<"\n";
			s="";
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
	cout<<"\t\t\t WELCOME TO CONTACTS!!!\n";
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
	
