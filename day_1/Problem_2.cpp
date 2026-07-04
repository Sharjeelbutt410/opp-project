#include<iostream>
using namespace std;
float calculatearea(float r)
{
	float pi=3.14;
	float circle=2*pi*r*r;
	return circle;
}
float calculatearea(float b,float h)
{
	float triangle= 0.5*b*h;
	return triangle;
}
float calculatearea(float l,float w,int)
{
	float rectangle= l*w;
	return rectangle;
}

int main()
{
	float r,l,w,b,h;
	char choice;
	char area;
do
{
	cout<<"What you want to calculate\n Area of \n.circle(C)\n.triangle(T)\n.rectangle(R) \n";
	cin>>area;
	switch(area)
	{
		case 'C':
		case 'c':
		{
			cout<<"Enter radius : ";
			cin>>r;
			cout<<"Area of circle : "<<calculatearea(r)<<endl;
			break;
		}	
		case 'T':
		case 't':
		{
			cout<<"Enter base and height : ";
			cin>>b>>h;
			cout<<"Area of triangle "<<calculatearea(b,h)<<endl;
			break;
		}
		case 'R':
		case 'r':
			{
				cout<<"Enter length and width : ";
				cin>>l>>w;
				cout<<"Area of ractangle "<<calculatearea(l,w)<<endl;
				break;
			}
		default:
			{
				cout<<"Invalid"<<endl;
			}
	}
	cout<<"Do you want to perform another calculation (Y or N) : ";
	cin>>choice;
}while(choice=='Y'|| choice=='y');
return 0;	
}
