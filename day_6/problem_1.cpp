#include<iostream>
using namespace std;

class Vehicle{
	public:
		
		virtual void startEngine() = 0;
};

class Car:public Vehicle{
	public:
		void startEngine()
		{
			cout<<"Car Engine Started! "<<endl;
		}
		
};

class Motorcycle:public Vehicle{
	public:
		void startEngine()
		{
			cout<<"Motorcycle Engine Started! "<<endl;
		}
};

class Truck:public Vehicle{
	public:
		void startEngine()
		{
			cout<<"Truck Engine Started! "<<endl;
		}
};

int main()
{
	Vehicle *v;
	Car c;
	Motorcycle m;
	Truck t;
	//CAR
	
	v = &c;
	v->startEngine();
	
	//MOTORCYCLE
	
	v = &m;
	v->startEngine();
	
	//TRUCK
	
	v = &t;
	v->startEngine();
}
