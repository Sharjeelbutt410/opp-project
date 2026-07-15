#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Product{
	private:
		int id;
		string name;
		int quantity;
		double price;
	public:
		Product() {}
		
		Product(int i,string n,int q,float p)
		{
			id = i;
			name = n;
			quantity = q;
			price = p;
		}		
};

int main()
{
	vector<Product> product;
	int id;
	string name;
	int quantity;
	double price;
	int choice;
	do
	{
	cout<<"1. Add a product "<<endl;
	cout<<"2. Display all product "<<endl;
	cout<<"3. Exit "<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	cin.ignore();
	switch(choice)
	
	{
		case 1:
			{
				cout<<"\nProduct details :\n"<<endl;
				cout<<"ID : ";
				cin>>id;
				cin.ignore();
				cout<<"Name : ";
				getline(cin,name);
				cout<<"Quantity : "; 
				cin>>quantity;
				cout<<"Price : ";
				cin>>price;
				ofstream file("product.txt",ios::app);
				{
					file<<"Id : "<<id<<endl;
					file<<"Name : "<<name<<endl;
					file<<"Quantity : "<<quantity<<endl;
					file<<"Price : "<<price<<endl;
				}
				file.close();
				cout<<"\nProduct added Successfully! \n"<<endl;
				break;
			}
			
			case 2:
				{
					string data;
					ifstream readfile("product.txt");
					while(!readfile.eof())
					{
						getline(readfile,data);
						cout<< data<<endl;
					}
					break;
				}
				
			case 3:
				{
					cout<<"Thanks for using!\n"<<endl;
					break;
				}
				
			default:
				{
					cout<<"\nInvalid!\n"<<endl;
					break;
				}
	}
	}while(choice != 3);
}
