#include<iostream>
using namespace std;
class Shape{
	public:
	virtual void area()
	{
		cout<<"Area of shape : "<<endl;
	}
};
class Circle:public Shape {
	private:
		float radius;
	public:
		Circle(float r)
		{
			radius = r;
		}
		void area()
		{
			cout<<"Area of Circle : "<<3.14 * radius *radius <<endl;	
		}
};
class Rectangle:public Shape{
	private:
		float length;
		float width;
	public:
		Rectangle(float l,float w)
		{
			length = l;
			width = w;
		}
		void area()
		{
			cout<<"Area of Rectangle : "<<length * width<<endl;
		}
};
class Triangle:public Shape{
	private:
		float base;
		float height;
	public:
		Triangle(float b,float h)
		{
			base = b;
			height = h;
		}
		void area()
		{
			cout<<"Area of Triangle : "<<0.5 * base * height<<endl;
		}
};

int main()
{
	float radius;
	float length,width;
	float base,height;
	Shape *s;
	
	//Circle
	cout<<"Circle\n"<<endl;
	cout<<"Enter radius : ";
	cin>>radius;
	Circle c(radius);
	
	//Rectangle
	cout<<"\nRectangle\n"<<endl;
	cout<<"Enter length : ";
	cin>>length;
	cout<<"Enter width : ";
	cin>>width;
	Rectangle r(length,width);
	
	
	//Triangle
	cout<<"\nTriangle\n"<<endl;
	cout<<"Enter Base : ";
	cin>>base;
	cout<<"Enter height : ";
	cin>>height;
	Triangle t(base,height);
	cout<<endl;
	
	s = &c;
	s->area();
	
	s = &r;
	s->area();
	
	s = &t;
	s->area();
}
