#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> v;
	string line;
	ifstream in("first.cpp");
	while(getline(in,line))
	v.push_back(line);
	for(int i=0; i<v.size();i++)
	cout<<i<<":"<<v[i]<<endl;
	return 0;
}
