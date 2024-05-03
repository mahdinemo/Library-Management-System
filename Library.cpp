#include <iostream>
#include "mahdi.hpp"

using namespace std;
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



cin.ignore();
cin.get();
return 0;
}
