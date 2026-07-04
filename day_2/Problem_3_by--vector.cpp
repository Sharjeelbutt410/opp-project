#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Book
{
public:
	string title,author;
	int price;
	Book(string nam,string aut,int pri)
	{
		title  = nam;
		author = aut;
		price = pri;
	}
	void display()
    	{
    		cout<<"Title : "<<title<<endl;
    		cout<<"Author : "<<author<<endl;
			cout<<"Price : "<<price<<endl;
		}
		
};

int main()
{
	vector<Book> library;
	int choice;
	
	do{
	
	cout<<" 1. Add new book \n"<<endl;
	cout<<" 2. Search book by title \n"<<endl;
	cout<<" 3. Display all books \n"<<endl;
	cout<<" 4. Delete a book \n"<<endl;
	cout<<" 5. Exit \n"<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	
	if(cin.fail())
		{
			cout<<"Invalid input! Please enter a number:  \n"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
			choice=0;
			continue;
		}
	cout<<endl;
	cin.ignore();
	switch(choice)
	{
		
		case 1:
			{
				string tit,aut;
				int pri;
				cout<<"Title : ";
				getline(cin,tit);
				cout<<"Author :  ";
				getline(cin,aut);
				cout<<"Price : ";
				cin>>pri;
				library.push_back(Book(tit,aut,pri));
				cout<<"Book added successfully!\n"<<endl;
				break;
			}
		case 2:
			{
				string tit;
				bool found = false;
				cout<<"Enter title : ";
				getline(cin,tit);
				for(int i=0; i<library.size(); i++)
				{
				if(library[i].title == tit)
				{
					found = true;
					cout<<" \n Book found! \n"<<endl;
					library[i].display();
					cout<<endl;
				}
				}
				if(!found)
				{
					cout<<"Book not found! \n"<<endl;
				}
				break;
				
			}
			case 3:
				{
					if(library.empty())
					{
						cout<<"No book available! \n"<<endl;
					}
					else
					{
						cout<<"Available books are! \n"<<endl;
						for(int i=0; i<library.size(); i++)
						{
							library[i].display();
							cout<<endl;
						}
					}
					break;
				}
			case 4:
				{
					string remove;
					bool found;
					cout<<"Enter title : ";
					getline(cin,remove);
					for(int i=0; i<library.size(); i++)
					{
						if(library[i].title==remove)
						{
							found = true;
							library.erase(library.begin() + i);
							cout<<"\n Book deleted Successfully! \n"<<endl;
							break;
						}
						
					}
						if(!found)
						{
							cout<<"\n Book not found \n"<<endl;
							break;
						}
				}
			case 5:
				{
					cout<<"\n Thanks for using! \n"<<endl;
					break;
				}
			default:
				{
					cout<<"\n Invalid choice! \n"<<endl;
					break;
				}
	}
	}while(choice != 5);
	cout<<"\n Press enter to exit!\n";
	cin.get();
	
}
