#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("first.cpp");
	ofstream out("golu.cpp");
	string s;
	while(getline(in,s))
	cout<<s<<"\n";
	//cout <<"file copied successfully";
	return 0;
}
