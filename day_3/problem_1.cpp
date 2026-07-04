#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BankAccount{
	private:
		double balance;
	public:
		int money;
		BankAccount()
		{
			balance = 100000;
		}
		void depmoney(double depmony)
		{
			balance += depmony;
			cout<<"\n Money Deposit Successfully! \n"<<endl;
		}
		void widrmoney(double widmony)
		{
			if(widmony>balance)
			{
				cout<<"\n Insufficient balance !\n"<<endl;
			}
			else
			{
				
			balance-= widmony;
			cout<<"\n Money Withdraw Successfully \n"<<endl;
			}
		}
		void curtbalance()
		{
			cout<< "Current Balance is : "<<balance<<endl;
		}
};


int main()
{
	int choice;
	BankAccount bankaccount;
do{	
	
	cout<<"\n 1. Deposit money \n"<<endl;
	cout<<"\n 2. Withdraw money \n"<<endl;
	cout<<"\n 3. Display current balance \n"<<endl;
	cout<<"\n 4. Exit \n"<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	if(cin.fail())
	{
		cout<<"\n Invalid choice! Enter a number. \n"<<endl;
		cin.clear();
		cin.ignore(100,'\n');
		choice=0;
		continue;
	}
	cout<<endl;

	switch(choice)
	{

		case 1:
			{
				double deposit;
				cout<<" How many rupee you want to deposit : ";
				cin>>deposit;
				bankaccount.depmoney(deposit);
				break;
			}
			case 2:
			{
				double withdraw;
				cout<<" How many rupee you want to withdraw : ";
				cin>>withdraw;
				cin.ignore();
				bankaccount.widrmoney(withdraw);
				break;
			}
			case 3:
			{
				bankaccount.curtbalance();
				break;
			}
			case 4:
			{
				cout<<"\n Thanks for using! \n "<<endl;
				break;
			}
	}
}while(choice != 4);
	cout<<"\n Press enter to exit! \n"<<endl;
	cin.get();
}
