#include<iostream>
#include<string>
using namespace std;

class payment{
	public:
		
	virtual void pay()
	{
		cout<<"Pay "<<endl;
	}
	virtual void display()
	{
		cout<<"Pay "<<endl;
	}
};
class cashpayment:public payment{ 
	void pay()
	{
		cout<<"\nOk! Thanks for purchasing \n"<<endl;
	}
};
class creditcard:public payment{
	private:
		string cardno;
		int expiry;
		int cvv;
	public:  
	void pay()
	{
		cout<<"card no : ";
		cin>>cardno;
		cout<<"Expiry date (MM/YY) : ";
		cin>>expiry;
		cout<<"Cvv : ";
		cin>>cvv;
		
	}
	void display()
	{
		cout<<"Card no : "<<cardno<<endl;
		cout<<"Expiry date : "<<expiry<<endl;
		cout<<"Cvv : "<<cvv<<endl;
	}
};
class online:public payment{
	private:
		string provider;
		string phoneno;
	public:
	void pay()
	{
		cout<<"Service provider : ";
		cin>>provider;
		cout<<"Phone no : ";
		cin>>phoneno;
		
	}
	void display()
	{
		cout<<"Service provider : "<<provider<<endl;
		cout<<"Phone no : "<<phoneno<<endl;
	}
};

int main()
{
	int choice;
	
		cout<<"------Payment method------\n"<<endl;
		cout<<"1. Cash on delivery"<<endl;
		cout<<"2. Credit Card  "<<endl;
		cout<<"3. Online \n"<<endl;
		cout<<"Enter choice : ";
		cin>>choice;
		cout<<endl;
		cin.ignore();

		switch(choice)
		{
			case 1:
				{
					payment *ptr;
					cashpayment cash;
					ptr = &cash;
					ptr->pay();
					break; 
				}
			case 2:
				{
					payment *ptr;
					creditcard credit;
					ptr = &credit;
					ptr->pay();
					cout<<"\n==Display==\n"<<endl;
					ptr->display();
					cout<<endl;
					break;
				}
			case 3:
				{
					payment *ptr;
					online on;
					ptr = &on;
					ptr->pay();  
					cout<<"\n==Display==\n"<<endl;
					ptr->display();
					cout<<endl;
					break;
				}
			default:
				{
					cout<<"\nInvalid choice!\n"<<endl;
				}
		}
}
