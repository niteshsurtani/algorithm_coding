#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	vector<vector<int> > v1;
	v1.reserve(3);
	for
	

	v.push_back(4);
	v.push_back(3);

	cout << v.size() << endl;
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;

	v1.push_back(v);
	cout << v1.size() << endl;
	/*
	cout << v1.size() << endl;
	cout << v1.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	for (auto i: v)
		cout << i << " ";
	cout << endl;

	for (auto &i: v)
		cout << i << " ";
	cout << endl;

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
*/
//	sort(v.begin(), v.end(), std::greater<int>);
	return 0;
}
