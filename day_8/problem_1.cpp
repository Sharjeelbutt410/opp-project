#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	vector<string> students;
	string name;
	
	while(true)
	{
		cout<<"Name : ";
		getline(cin,name);
		if(name == "stop")
		{
			break;
		}
		students.push_back(name);
	}
	ofstream writefile("student.bin");
	
	for(int i = 0; i < students.size(); i++)
	{
		writefile << students[i] <<endl;
	}
	writefile.close();
	
	ifstream readfile("student.bin");
	
	cout<<"\nSaved Students names : "<<endl;
	
	while(getline(readfile,name))
	{
		cout<< name <<endl;
	}
	readfile.close();
	
	return 0;
	
}
