#include<iostream>
#include<string>
using namespace std;

class ATM
{
	private:
		int pin;
		double balance;
	public:
		ATM()
		{
			pin = 1234;
			balance = 100000;
		}
		bool verifypin()
		{
			for(int i=1; i<=3; i++)
			{
			int enterdpin;
			cout<<"Enter Pin : ";
			cin>>enterdpin;
			if(enterdpin == pin)
			{
				cout<<"Pin Verified Successfully! \n";
				return true;
			}
			else
			{
				cout<<"Incorrect Pin! ";
				
				if(i<3)
				{
					cout<<"Try again \n"<<endl;
				}
			}

			}
			cout<<"\n Too many incorrect attempts. Account locked!\n"<<endl;
			return false;
		}
		void showbalance()
		{
			cout<<"Your current balance is : "<<balance<<endl;
		}
		void deposit(double amount)
		{
			if(amount>0)
			{
				balance += amount;
				cout<<"\n Money deposit successfully! \n"<<endl;
			}
			else
			{
				cout<<"\n Invalid amount! \n"<<endl;
			}
		}
		void withdraw(double amount)
		{
			if(amount<= 0)
			{
				cout<<"\n Invalid amount! \n"<<endl;
			}
			else if(amount > balance)
			{
				cout<<"Insufficient amount! \n"<<endl;
			}
			else
			{
				balance -= amount;
				cout<<"\n Money withdraw successfully! \n"<<endl;
			}
		}
		
};

int main()
{
	ATM atm;
	int choice;

	if(!atm.verifypin())
	{
		return 0;
	}
	do{
		cout<< "\n====ATM Menu====\n"<<endl;
		cout<<"1. Show current balance  \n";
		cout<<"2. Deposit money \n";
		cout<<"3. Withdraw money \n";
		cout<<"4. Exit \n";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					atm.showbalance();
					break;
				}
			case 2:
				{
					double amount;
					cout<<"Enter amount : "<<endl;
					cin>>amount;
					atm.deposit(amount);
					break;
				}
			case 3:
				{
					double amount;
					cout<<"Enter amount : "<<endl;
					cin>>amount;
					atm.withdraw(amount);
					break;
				}
			case 4:
				{
					cout<<"\n Thnaks for using! \n "<<endl;
					break;
				}
			default:
				{
					cout<<"\n Invalid choice! \n"<<endl;
					break;
				}
		}
	}while(choice != 4);
	
}
