#include<iostream>
using namespace std;
class Book 
{
	public:
		string title;
		string author;
		int price;
	Book(string t,string a,int p)
	{
		title = t;
		author = a;
		price = p;
		cout<<"Title : "<<title<<endl;
		cout<<"Author : "<<author<<endl;
		cout<<"Price : "<<price<<endl;
	}

};
int main()
{
	string tit,aut;
	int pri;
	
	//Book1
	
	cout<<"Title : "<<endl;
	getline(cin,tit);
	cout<<"Author : "<<endl;
	getline(cin,aut);
	cout<<"Price : "<<endl;
	cin>>pri;
	cin.ignore();
	cout<<endl;
	Book O1(tit,aut,pri);
	cout<<endl;	
	
	//Book2
	
	string tit2,aut2;
	int pri2;
	cout<<"Title : "<<endl;
	getline(cin,tit2);
	cout<<"Author : "<<endl;
	getline(cin,aut2);
	cout<<"Price : "<<endl;
	cin>>pri2;
	cin.ignore();
	cout<<endl;
	Book O2(tit2,aut2,pri2);
	cout<<endl;
	
	//Book3
	
	string tit3,aut3;
	int pri3;
	cout<<"Title : "<<endl;
	getline(cin,tit3);
	cout<<"Author : "<<endl;
	getline(cin,aut3);
	cout<<"Price : "<<endl;
	cin>>pri3;
	cin.ignore();
	cout<<endl;
	Book O3(tit3,aut3,pri3);
	cout<<endl;
	cout<<"\n Press enter to exit!\n";
	cin.get();
	return 0;
}
