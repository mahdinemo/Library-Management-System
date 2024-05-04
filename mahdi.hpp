#ifndef MAHDI_HPP
#define MAHDI_HPP

#include <iostream>
#include <fstream>

using namespace std;

//first of all I need two functions for my error handlings. one for digits and the other one is for chars. 
bool valid_input = false;
string Menu_Choice;
int choice;

int digit_error(int begin , int end) //they show us the starting and finishing points of the interval 
{
	while(!valid_input)
	{
		cout<<"\n\t\t\t\t\t\t\tEnter Your Choice : ";
		cin>>Menu_Choice;
		if (!isdigit(Menu_Choice[0])) {
            cout << "\n\t\t\t\t\t\t\tError: Invalid input. Please Enter a Valid Digit From "<<begin<<" 'till "<<end<< endl;
            continue;
        }
        choice = stoi(Menu_Choice); // converting the character into an integer.
        
        if(choice < 1 || choice > 6)
        {
        	cout << "\n\t\t\t\t\t\t\tError: Invalid Input. Please Enter a Value Between "<<begin <<" And "<<end << endl;
            continue;
		}
		valid_input = true;	
	} 
	
	return choice;
}

#endif
