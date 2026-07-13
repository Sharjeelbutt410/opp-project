#include<iostream>
using namespace std;

class Vector2D{
	private:
		int x;
		int y;
	public:
		Vector2D(int x = 0 ,int y = 0)
		{
			this->x = x;
			this->y = y;
		}
		Vector2D operator+(Vector2D v)
		{
			Vector2D temp;
			temp.x = x + v.x;
			temp.y = y + v.y;
			return temp;
		}
		Vector2D operator-(Vector2D v)
		{
			Vector2D temp;
			temp.x = x - v.x;
			temp.y = y - v.y;
			return temp;
		}
		bool operator==(Vector2D v)
		{
			
			return (x == v.x && y == v.y);
		}
		
		void display()
		{
			cout<<x<<" ,"<<y<<endl;
		}
};

int main()
{
	int x1,y1,x2,y2;
	cout<<"Enter first Vector ( , ) : ";
	cin>>x1>>y1;
	cout<<"Enter Second Vector ( , ) : ";
	cin>>x2>>y2;
	
	Vector2D v1(x1,y1); 
	Vector2D v2(x2,y2);
	
	Vector2D sum = v1 + v2;
	sum.display();
	cout<<endl;
	Vector2D diff = v1 - v2;
	diff.display();
	cout<<endl;
	if(v1 == v2)
	{
		cout<<"Vectors are Equal "<<endl;
	}
	else
	{
		cout<<"Vectors are not Equal "<<endl;
	}
}
