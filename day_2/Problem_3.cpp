#include<iostream>
#include<string>
using namespace std;

class Book
{
	public:
	string title,author;
	int price;
	Book()
	{
		title = "";
		author = "";
		price = 0;
	}
	Book(string tit,string aut,int pri)
	{
		title = tit;
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
    Book library[100];
    int num = 0 ;
	int choice;
	do{
		cout<<" 1. Add new books \n"<<endl;
		cout<<" 2. Search book by title \n"<<endl;
		cout<<" 3. Display all books \n"<<endl;
		cout<<" 4. Remove a book \n"<<endl;
		cout<<" 5. Exit \n"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		
		if(cin.fail())
		{
			cout<<"Invalid input! Please enter a number \n"<<endl;
			cin.clear();
			cin.ignore(1000,'\n');
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
			cout<<"Title : "<<endl;
			getline(cin,tit);
			cout<<"Author : "<<endl;
			getline(cin,aut);
			cout<<"Price : "<<endl;
			cin>>pri;
			cin.ignore();
			library[num] = Book(tit,aut,pri);
			num++;
			cout<<"Book added Successfully!\n"<<endl;
			break;
			}
		case 2:
			{
			string search;
			bool found = false;
			cout<<"Enter title: ";
			getline(cin,search);
			cout<<endl;
			for(int i=0 ; i<num ; i++)
			{
				if(library[i].title == search)
				{
					cout<<"Found! \n"<<endl;
					library[i].display();
					cout<<endl;
					found = true;
				}

			}
				if(!found)
				{
					cout<<"Book not found! \n"<<endl;
					break;
				}
				break;
			}
			case 3:
				{
					if(num == 0)
					{
						cout<<"No book available!\n "<<endl;
					}
					else
					{
						cout<<"Available books are! \n"<<endl;
						for(int i=0; i<num; i++)
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
						bool found = false;
						cout<<"Enter title : "<<endl;
						getline(cin,remove);
						for(int i=0; i<num; i++)
						{
							if(library[i].title == remove)
							{
								found = true;
								for(int j=i; j<num-1; j++)
								{
								library[j] = library[j + 1]; 
		
							}
								num--;
								cout<<"Book deleted successfully!\n"<<endl;
								break;
								}
							if(!found)
							{
								cout<<"Book not found!\n"<<endl;
								break;
							}

							
						}
					break;
					}
				case 5:
					{
						cout<<"Thanks for using!\n"<<endl;
						break;
					}
			default :
				cout<<"Invalid choice! \n"<<endl;
	 }

	}while(choice !=5);
	cout<<"\n Press enter to exit!\n";
	cin.get();
	return 0;
}
