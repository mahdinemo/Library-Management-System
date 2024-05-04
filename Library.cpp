#include <iostream>
#include "mahdi.hpp"

using namespace std;

class library
{
	public:
		string book_name;
		string writer_name;
		string title;
		int cost;
		long int id;
		
		//===========================
		
		void add_book();
		void search_by_id();
		void search_by_name();
		void search_by_title();
		void edit_by_id();
		void list();
		void count_books();
}



int main()
{
		
	int Menu_Choice;
	cout<<"\n\t\t\t\t***************** Library Management System *****************"<<endl;
	cout<<"\n\t\t\t\t\t\t\t1 : Add book";
	cout<<"\n\t\t\t\t\t\t\t2 : Search";
	cout<<"\n\t\t\t\t\t\t\t3 : Edit";
	cout<<"\n\t\t\t\t\t\t\t4 : List of whole books";
	cout<<"\n\t\t\t\t\t\t\t5 : Counter for book categories";
	cout<<"\n\t\t\t\t\t\t\t6 : Exit"<<endl;
	
	//I want to hasndle the digits error in just one line of code .
	
	digit_error(1 , 6);
	Menu_Choice = digit_error(1 , 6);
	
	switch(Menu_Choice)
	{
		case 1:
			{
				system("CLS");
				cout<<"\n\t\t\t\t\t\t\tAdd Book";
				break;
			}
			
		case 2:
			{
				system("CLS");
				cout<<"\n\t\t\t\t\t\t\tSearch";
				break;
			}
			
		case 3:
			{
				system("CLS");
				cout<<"\n\t\t\t\t\t\t\tEDIT";
				break;
			}
			
		case 4:
			{
				system("CLS");
				cout<<"\n\t\t\t\t\t\t\tList Of Whole Books";
				break;
			}
		
		case 5:
			{
				system("CLS");
				cout<<"\n\t\t\t\t\t\t\tCounter For Books";
				break;
			}
			
		case 6:
			{
				exit(0);
			}
			
	}



cin.ignore();
cin.get();
return 0;
}
