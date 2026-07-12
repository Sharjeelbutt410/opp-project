#include<iostream>
using namespace std;

class Question{
	public:
		virtual void display() = 0;
};
class Mcqs:public Question{
	private:
		char choice;
	public:
		void display()
		{
			cout<<"MCQs\n"<<endl;
			cout<<"Chose the correct option. \n"<<endl;
			cout<<"1. What is day today? \n"<<endl;
			cout<<"(a) Monday\t";
			cout<<"(b) Tuesday\t";
			cout<<"(c) Wednesday\t";
			cout<<"(d) None "<<endl;
			cout<<"Ans: ";
			cin>>choice;
		}
};
class tfQuestion:public Question{
	private:
		bool choice;
	public:
		void display()
		{
			cout<<"Trus/False\n"<<endl;
			cout<<"Write the correct answer. \n"<<endl;
			cout<<"1. Today is Sunday. "<<endl;
			cout<<"true or false : ";
			cin>>choice;
		}
};
class shortQuestion:public Question{
	public:
		void display()
		{
			cout<<"Short Questions\n"<<endl;
			cout<<"Attempt any 3 questions from the following \n"<<endl;
			cout<<"1. What is c++? "<<endl;
			cout<<"2. What is oop? "<<endl;
			cout<<"3. What is virtual function? "<<endl;
			cout<<"4. What is override? "<<endl;
		}
};

int main()
{
	Question *q;
	Mcqs m;
	tfQuestion tf;
	shortQuestion s;
	//MCQS
	q = &m;
	q->display();
	cout<<"\n"<<endl;
	//TRUE/FALSE Questions
	q = &tf;
	q->display();
	cout<<"\n"<<endl;
	//SHORT Questions
	q = &s;
	q->display();
	cout<<"\n"<<endl;
}
