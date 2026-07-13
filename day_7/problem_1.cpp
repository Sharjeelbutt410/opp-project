#include<iostream>
using namespace std;

class ComplexNumber{
	private:
		float real;
		float imaginary;
	public:
		ComplexNumber(float r = 0,float i = 0)
		{
			real = r;
			imaginary = i;
		}
		ComplexNumber operator+(ComplexNumber other)
		{
			ComplexNumber temp;
			temp.real = real+other.real;
			temp.imaginary = imaginary+other.imaginary;
			return temp;
			
		}
		void display()
		{
			cout<<real<<"+"<<imaginary<<"i"<<endl;
		}
};

int main()
{
	float r1,i1,r2,i2;
	cout<<"Enter first complex number (real imaginary): ";
	cin>>r1>>i1;
	cout<<"Enter second complex number (real imaginary): ";
	cin>>r2>>i2;
	ComplexNumber c1(r1,i1);
	ComplexNumber c2(r2,i2);
	
	ComplexNumber c3 = c1 + c2;
	c3.display();
}

