#include<iostream>
#include<string>
using namespace std;

class Animal{
	public:
	virtual void makeSound()
	{
		cout<<" Sound : "<<endl;
	}
};
class Dog: public Animal{
	void makeSound()
	{
		cout<<"Woof woof"<<endl;
	}
};
class Cat:public Animal{
	void makeSound()
	{
		cout<<"Meow Meow"<<endl;
	}
};
class Cow:public Animal{
	void makeSound()
	{
		cout<<"Moo Moo"<<endl;
	}
};

int main()
{
	int choice;
	
	do{
		cout<<"Animal Sound! \n"<<endl;
		cout<<"1. Dog "<<endl;
		cout<<"2. Cat "<<endl;
		cout<<"3. Cow "<<endl;
		cout<<"4. Exit "<<endl;
		cout<<"Enter choice :  ";
		cin>>choice;
		cout<<endl;
		if(cin.fail())
		{
			cin.clear();
			cout<<"\nInvalid choice! \n"<<endl;
			cin.ignore(100,'\n');
			choice = 0;
			continue;
		}
		cin.ignore();
	switch(choice)
	{
		case 1:
			{
				Animal*ptr;
				Dog d;
				ptr = &d;
				ptr->makeSound();
				cout<<endl;
				break;
			}
		case 2:
			{
				Animal*ptr;
				Cat c;
				ptr = &c;
				ptr->makeSound();
				cout<<endl;
				break;
			}
		case 3:
			{
				Animal*ptr;
				Cow co;
				ptr = &co;
				ptr->makeSound();
				cout<<endl;
				break;
			}
		case 4:
			{
				cout<<"\nThanks for using! \n "<<endl;
				break;
			}
		default:
		{
			cout<<"\nInvalid! \n"<<endl;
		}
	}
	}while(choice !=4);
}
