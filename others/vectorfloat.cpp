#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	vector<float> v;
	for(int i=0;i<25;i++)
	v.push_back(float(i));
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<endl;
	return 0;
}
