#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &curr)
{
	for (auto i: curr)
		cout << i << " ";
	cout << endl;
}

void print_permutations(vector<int> &curr, const vector<int> &v)
{
	if (curr.size() == v.size()) {
		print_vector(curr);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (find(curr.begin(),curr.end(),v[i]) == curr.end()) {
			curr.push_back(v[i]);
			print_permutations(curr,v);
			curr.pop_back();
		}
	}
}

int main(int argc, char **argv)
{
	int n = stoi(argv[1]);

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i+1;

	vector<int> curr{};
	print_permutations(curr,v);

	return 0;
}
