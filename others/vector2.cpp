#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> v;
	int i;
	for(int i=0;i<10;i++)
	v.push_back(i);
	for(int i=0;i<v.size();i++)
	v[i]=v[i]*10;
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<endl;
	return 0;
}
