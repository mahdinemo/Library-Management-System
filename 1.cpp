#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>


using namespace std;
//in the Add_book function I should add isdigit function to limit the user
/*

while(!isalpha(name2[0]))
	{
		system("CLS");
		cout<<"Name should contain only alphabets. Try again : ";
		getline(cin>>ws,name2);
	}
*/



/*
if you wanna force the user to input only digits , do as follows below : 
int num ;
bool validInput = false;
while(!validInpit)
{
string mystring;
cout<<"Enter : ";
getline(cin>>ws,mystring);
if(!isdigit)
{
cout<<"\nInvalid input";
continue;
}

num = stoi(mystring);
if(num<1)
{
cout<<"\nnum should valid bigger than 0";
continue;
}

}
*/

struct book
{
	string name;
	string writer_name;
	string title;
	int cost;
	long int id;
};

void Add_book();
void search_by_id();
void edit_by_id();
void list();
void search_by_name();
void search_by_title();
void count_books();


int main()
{
char option;//we learned that when we are ganna use isdigit() function we shouldn't use the variables in kind of integer because unexpected results will occur
int choice;//so instead we use char and the convert it into the integer 
bool validInput = false;
cout<<"\t\t***************** Main Menu *****************\n\n";
cout<<"Item 1 : Add book";
cout<<"\nItem 2 : Search";
cout<<"\nItem 3 : Edit";
cout<<"\nItem 4 : List of whole books";
cout<<"\nItem 5 : Counter for book categories";
cout<<"\nItem 6 : Exit\n";

 while (!validInput) {
        cout << "\nEnter your choice (1-6): ";
        cin >> option;

        if (!isdigit(option)) {
            cout << "Error: Invalid input. Please enter a valid digit." << endl;
            continue;
        }

        choice = option - '0'; // Convert char to int

        if (choice < 1 || choice > 6) {//check if the input integer is true
            cout << "Error: Invalid input. Please enter a value between 1 and 5." << endl;
            continue;
        }

        validInput = true;
    }



switch(choice)
{
	case 1:
		{
			system("CLS");
			Add_book();
			cout<<"\n";
			main();
		}
		
	case 2:
		{
			system("CLS");
			int num;
			bool validsearch = false;
			cout<<"\t\t\t************** SEARCH ***************";
			cout<<"\\n\n\n1 : Search_by_name";
			cout<<"\n\n2 : Search_by_Id\n";
			cout<<"\n3 : Search_by_title\n\n";
			
			while(!validsearch)
			{
				string mystring;
				cout<<"Your choice :  ";
				getline(cin>>ws,mystring);
				
				if(!isdigit(mystring[0]))
				{
					cout<<"\nError.Enter a valid digit \n";
					continue;
				}
				num = stoi(mystring);
				validsearch = true;
			}
		
			switch(num)
			{
				case 1:
					{
						system("CLS");
						search_by_name();
						cout<<"\n";
						main();
					}
				case 2:
					{
						system("CLS");
						search_by_id();
						cout<<"\n";
						main();
					}
				
				case 3:
					{
						system("CLS");
						search_by_title();
						cout<<"\n";
					}
				default:
					{
							system("CLS");
							cout<<"Wrong input\n";
							main();
					}
			}
		}	
	case 3:
		{
			system("CLS");
			edit_by_id();
			cout<<"\n";
			main();
		}
		
	case 4:
		{
			system("CLS");
			list();
			cout<<"\n";
			main();
		}
		
	case 5 :
		{
			system("CLS");
			count_books();
			cout<<"\n";
			main();
		}		
		
	case 6:
		{
			exit(0);
		}
	default :
		{
			system("CLS");
			cout<<"Wrong input\n";
			main();
		}
}




cin.ignore();
cin.get();
return 0;
}



void Add_book()
{
	string name1,name2,name3;//name1 : name of the book / name2 : name of the writer / name3 : title of the book
	vector<book>librar;
	bool validInput = false;
	int num;
	
	while(!validInput)
	{
		
		string num_book;
		cout<<"\t\t************** ADD BOOK *****************\n\n\n";
		cout<<"Enter the number of books you wanna add : ";
		getline(cin>>ws,num_book);
	
		if(!isdigit(num_book[0]))
		{
			cout<<"\nError : Invalid input. please enter a valid digit : "<<endl;
			continue;
		}
		num = stoi(num_book);
		
		if(num < 1)
		{
			cout<<"\nError : Invalid input. Please enter a valid bigger than 0"<<endl;
			continue;
		}
		validInput = true;
	}
	
	for(int i=0 ; i<num ; i++)
	{
		book new_book;
		system ("CLS");
		
		
		cout<<"\t\t************** ADD BOOK *****************";
		cout<<"\n\nBook number "<<i+1<<" : ";
		
		
		// 1 : name of the book
		cout<<"\nName (without space) : ";
		getline(cin >> ws , name1);
		
		while(!isalpha(name1[0]))
		{
			system("CLS");
			cout<<"Name should contain only alphabets. Try again : ";
			getline(cin>>ws,name1);
		}
		
		while(name1.find(" ") != string::npos)
		{
			system("CLS");
		    cout<<"Name should not contain spaces . enter again : ";
		    getline( cin >> ws , name1);
		}
		new_book.name=name1;
		
		// 2 : name of the writer
		cout<<"\nEnter the writer's name (without space) : ";
		getline( cin>> ws , name2);
		
		while(!isalpha(name2[0]))
		{
			system("CLS");
			cout<<"Name of the writer should contain only alphabets. Try again : ";
			getline(cin>>ws,name2);
		}
		
		while(name2.find(" ") != string::npos)
		{
			system("CLS");
		    cout<<"name of the writer should not contain spaces . enter again : ";
		    getline( cin >> ws , name2);
		}
		new_book.writer_name=name2;
		
		
		/*3 : title of the book
		There is an update here : to make search_by_title function we should have a limitation of titles which force the user to choose one of them
		we have (5) titles  1 : Mystrey  , 2 : Scary , 3 : Science fiction , 4 : Story , Psychologist  
		*/
		int title;
		bool validTitle = false;
		system("CLS");
		cout<<"\t\t\t\tTITLE";
		cout<<"\n1: Mystery";
		cout<<"\n2: Scary";
		cout<<"\n3: Science fiction";
		cout<<"\n4: Story";
		cout<<"\n5: Psychology";
		cout<<"\n\nEnter your choice : ";
		
		while(!validTitle)
		{
			string mytitle;
			getline(cin>>ws,mytitle);
			if(!isdigit(mytitle[0]))
			{
				cout<<"\nError: Title of the book should contain only valid digits. ";
				continue;
			}
			title = stoi(mytitle);
			if(title>5||title<1)
			{
				cout<<"\nYour choice must be between 1 to 5";
				continue;
			}
			validTitle=true;
		}
		
		if(title==1)
		new_book.title="Mystery";
		
		else if(title==2)
		new_book.title="Scary";
		
		else if(title==3)
		new_book.title="ScienceFiction";
		
		else if(title==4)
		new_book.title="Story";
		
		else if(title==5)
		new_book.title="Psychology";	
	
		// 4 : cost (I'm ganna make a process for getting the cost and after I'm done with that I will store it as new_book.cost
		
		int payment;
		bool validCost = false;
		
		while(!validCost)
		{	
			string myCost;
			cout<<"\nEnter the cost of the book : ";
			getline(cin>>ws,myCost);
			
			if(!isdigit(myCost[0]))
			{
				cout<<"\nError: cost of the book should contain only valid digits. ";
				continue;
			}
			payment = stoi(myCost);
			
			if(payment<1)
			{
					cout<<"\nError : Invalid input. Please enter a valid bigger than 0"<<endl;
					continue;
			}
		
			validCost=true;
			new_book.cost=payment;	
		}
		
		
		// 5 : id (exact process of cost)
		int identity;
		bool validId = false;
		
		while(!validId)
		{
			string myid;
			cout<<"\nEnter id of the book : ";
			getline(cin>>ws,myid);
			
			if(!isdigit(myid[0]))
			{
				cout<<"\nError: ID of the book only contains valid digits. ";
				continue;
			}
			
			identity = stoi(myid);
		
			if(identity<1)
			{
				cout<<"\nError : ID should be greater than 1 ";
				continue;
			}
		validId=true;
		new_book.id=identity;
		}
			
		librar.push_back(new_book);
	}
	
	//now we are ganna store them into a file
	
	ofstream myfile;
	myfile.open("library.txt",ios::app);
	
	if(myfile.is_open())
	{
		for(int j=0 ; j<num ; j++)
		{
			myfile<<librar[j].name <<"  "<<librar[j].writer_name<<"  "<<librar[j].title<<"  "<<librar[j].cost<<"  "<<librar[j].id<<endl;
		}
		myfile.close();
		system("CLS");
		cout<<"Successfully stored";
	}
	else
	{
		cout<<"\nUnable to open the file";
	}
}




void search_by_name()
{
	int exist = 0;
	string sname,swriter,stitle;
	int scost,sid;
	string mysearch;
	
	cout<<"Search name : ";
	getline(cin>>ws,mysearch);
	
	while (!isalpha(mysearch[0]))
        {
            system("CLS");
            cout << "Name should contain only alphabets. Try again: ";
            getline(cin >> ws, mysearch);
        }

    while (mysearch.find(" ") != string::npos)
        {
            system("CLS");
            cout << "Name should notcontain spaces. Enter again: ";
            getline(cin >> ws, mysearch);
        }
	
	ifstream search_by_name("library.txt",ios::app);
	while(search_by_name >> sname >> swriter >> stitle >> scost >> sid)
	{
		if(sname == mysearch)
		{
			exist=1;
			break;
		}
	}
	search_by_name.close();
	if(exist==1)
	{
		cout<<"\nFound  : ";
		cout<<"\nName : "<<sname;
		cout<<"\nWriter : "<<swriter;
		cout<<"\nTitle : "<<stitle;
		cout<<"\nCost : "<<scost;
		cout<<"\nID : "<<sid;
		cout<<"\n-------------------------------------------\n\n";
	}
	else
	{
		cout<<"\nNot found";
	}
}


void search_by_id()
{
	int num;
	bool validid = false;
	int exist=0;
	string sname,swriter,stitle;
	int scost,sid,searchId;	
				
	while(!validid)
	{
		string mystring;
		cout<<"Search the id : ";
		getline(cin>>ws,mystring);
		
		if(!isdigit(mystring[0]))
		{
			cout<<"\nError : Enter valid digit  ";
			continue;
		}
		
		num = stoi(mystring);
		
		if(num<1)
		{
			cout<<"\nError : ID must valid bigger than 0";
			continue;
		}
		
		validid=true;
		searchId=num;
	}			
	
	ifstream search("library.txt",ios::app);
	while(search >> sname >> swriter >> stitle >> scost >> sid)
	{
		if(sid == searchId)
		{
			exist=1;
			break;
		}
	}
	search.close();
	
	if(exist==1)
	{
		cout<<"\nFound ";
		cout<<"\nnew_book name : "<<sname;
		cout<<"\nWriter name: "<<swriter;
		cout<<"\nTitle : "<<stitle;
		cout<<"\nCost : "<<scost;
		cout<<"\n\n-----------------------------------------\n\n";
	}
	
	else
	cout<<"\nNot found";
}


void search_by_title()
{
	system("CLS");
	string sname,swriter,stitle,mytitle;
	int scost,sid;
	int exist = 0;
	int counter=0;

	 	int title;
		bool validTitle = false;
		system("CLS");
		cout<<"\t\t\t\tTITLE";
		cout<<"\n1: Mystery";
		cout<<"\n2: Scary";
		cout<<"\n3: Science fiction";
		cout<<"\n4: Story";
		cout<<"\n5: Psychology";
		cout<<"\n\nEnter your choice : ";
		
		while(!validTitle)
		{
			string mySearchTitle;
			getline(cin>>ws,mySearchTitle);
			if(!isdigit(mySearchTitle[0]))
			{
				cout<<"\nError: Title of the new_book should contain only valid digits. ";
				continue;
			}
			title = stoi(mySearchTitle);
			if(title>5||title<1)
			{
				cout<<"\nYour choice must be between 1 to 5";
				continue;
			}
			validTitle=true;
		}
		
		if(title==1)
		mytitle="Mystery";
		
		else if(title==2)
		mytitle="Scary";
		
		else if(title==3)
		mytitle="ScienceFiction";
		
		else if(title==4)
		mytitle="Story";
		
		else if(title==5)
		mytitle="Psychology";	
		ifstream search_title("library.txt");
	system("CLS");
		while(search_title >> sname >> swriter >> stitle >> scost >> sid)
		{
			if(stitle==mytitle)
			{
				cout<<"\nName : "<<sname<<"  "<<"Writer : "<<swriter<<"  "<<"Title : "<<stitle<<"  "<<"Cost : "<<scost;
				cout<<"\n\n----------------------------------------------------------------------\n\n";
				counter++;
			}
		}
		cout<<"\n\n\n"<<counter <<" "<<mytitle<<" new_books found\n\n";

		search_title.close();
	
main();
}



void edit_by_id()
{
    int exist = 0;
    string sname, swriter, stitle;
    int scost, sid, searchId;
	
	int num;
	bool validid=false;
	while(!validid)
	{
		string id;
		cout<<"\t\t******************* EDIT *******************\n\n\n";
    	cout << "EnterID of the new_book you want to edit: ";
		getline(cin>>ws,id);
		
		if(!isdigit(id[0]))
		{
			cout<<"\nInvalid input.\n";
			continue;
		}
		num=stoi(id);
		if(num<1)
		{
			cout<<"\nThe id should valid bigger than 0";
			continue;
		}
		
		validid = true;
		searchId=num;
	}
		

    ifstream search("library.txt");//do not write ios::app becuase if you do the previuse data will not be removed
    if (!search.is_open()) {
        cout << "Error: unable to open input file" << endl;
        return;
    }

    ofstream temp("temp.txt");//do not write ios::app becuase if you do the previuse data will not be removed
    if (!temp.is_open()) {
        cout << "Error: unable to open temporary file" << endl;
        temp.close();
        return;
    }

    while (search >> sname >> swriter >> stitle >> scost >> sid)
    {
        if (sid == searchId)
        {
            exist = 1;
            cout << "\nName: " << sname;
            cout << "\nWriter: " << swriter;
            cout << "\nTitle: " << stitle;
            cout << "\nCost: " << scost;
            cout << "\nID: " << sid;
            cout << "\n---------------------------------------\n\n";

            cout << "Enter the updated information: ";
            //new_book's name
            cout << "\nName: ";
            getline(cin >> ws, sname);

            while (!isalpha(sname[0]))
            {
            	
                system("CLS");
                cout << "Name should contain only alphabets. Try again: ";
                getline(cin >> ws, sname);
            }

            while (sname.find(" ") != string::npos)
            {
                system("CLS");
                cout << "Name should notcontain spaces. Enter again: ";
                getline(cin >> ws, sname);
            }

            //writer's name
            cout << "\n\nWriter's name: ";
            getline(cin >> ws, swriter);

            while (!isalpha(swriter[0]))
            {
                system("CLS");
                cout << "Name should contain only alphabets. Try again: ";
                getline(cin >> ws, swriter);
            }

            while (swriter.find(" ") != string::npos)
            {
                system("CLS");
                cout << "Name should not contain spaces. Enter again: ";
                getline(cin >> ws, swriter);
            }

        //Title    
        int title;
		bool validTitle = false;
		system("CLS");
		cout<<"\t\t\t\tTITLE";
		cout<<"\n1: Mystery";
		cout<<"\n2: Scary";
		cout<<"\n3: Science fiction";
		cout<<"\n4: Story";
		cout<<"\n5: Psychology";
		cout<<"\n\nEnter your choice : ";
		
		while(!validTitle)
		{
			string mytitle;
			getline(cin>>ws,mytitle);
			if(!isdigit(mytitle[0]))
			{
				cout<<"\nError: Title of the new_book should contain only valid digits. ";
				continue;
			}
			title = stoi(mytitle);
			if(title>5||title<1)
			{
				cout<<"\nYour choice must be between 1 to 5";
				continue;
			}
			validTitle=true;
		}
		
		if(title=1)
		stitle="Mystery";
		
		else if(title=2)
		stitle="Scary";
		
		else if(title=3)
		stitle="Science fiction";
		
		else if(title=4)
		stitle="Story";
		
		else if(title=5)
		stitle="Psychology";
            
            //cost
            system("CLS");
            cout << "\n\nCost: ";
            cin >> scost;
            while (cin.fail() || cin.get() != '\n')
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input! Enter costagain: ";
                cin >> scost;
            }

            //id
            system("CLS");
            cout << "\n\nID: ";
            cin >> sid;
            while (cin.fail() || cin.get() != '\n')
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input! Enter ID again: ";
                cin >> sid;
            }

            // Write the updated record to the temporary file
            temp << sname << " " << swriter << " " << stitle << " " << scost << " " << sid << endl;

            continue;
        }

        // Write the original record to the temporary file
        temp << sname << " " << swriter << " " << stitle << " " << scost << " " << sid << endl;
    }

    search.close();
    temp.close();

    if (exist == 1)
    {
        // Replace the original file with the temporary file
        if (remove("library.txt") != 0)
            cout << "Error: unable to delete input file" << endl;
        if (rename("temp.txt", "library.txt") != 0)
            cout << "Error: unable to rename temporary file" << endl;
		system("CLS");
        cout << "\n\nSuccessfully edited!\n";
    }
    else
        cout << "new_book not found" << endl;
}

void list()
{
	string sname,swriter,stitle;
	int scost,sid;
	cout<<"\t\t**************** LIST ******************\n\n\n";
	ifstream list("library.txt",ios::app);
	while(list >> sname >> swriter >> stitle >> scost >> sid)
	{
		cout<<"Name : "<<sname<<"\t\tTitle: "<<stitle<<"\t\tID : "<<sid<<endl<<endl;
		cout<<"--------------------------------------------------------------------------\n\n";	
	}
	list.close();
}

void count_books()
{
	//creat a map to cout the number of new_books in each category
	map<string,int> categoryCount;
	cout<<"\t\t\t********** new_book Category **********\n\n\n";
	//read from the file and count the number of each category
	ifstream count("library.txt");
	if(count.is_open())
	{
		string line;
		while(getline(count,line))
		{
			istringstream iss(line);
			string name , writer_name , title;
			int cost , id;
			iss >> name >> writer_name >> title >> cost >> id;
			
			//incresment the count for the category
			categoryCount[title]++;
		}
		count.close();
		
		for(auto& category : categoryCount)
			{
				cout<<"Number of "<<category.first<<" new_books: "<<category.second <<endl<<endl;
			}
	}
	else
    {
        cout << "Unable to open the library file." << endl;
    }
}