#include <iostream>
#include <stack>
using namespace std;

struct node{
	int num;
	int index;
	node(int n, int i): num{n}, index{i} {}
};

int main(){
	stack<node*> s;

	int i,n, a[100];
	cin >> n;

	i=0;
	while(i<n){
		cin >> a[i];
		i++;
	}

	i=0;
	while(i<n){
		while(!s.empty() && a[i] > s.top()->num){
			node *t;
			t = s.top();
			int k = t->index;
			a[k] = a[i];
			s.pop();
		}
		node *n = new node(a[i],i);
		s.push(n);

		i++;
	}
	while(!s.empty()){
		s.pop();
	}

	i=0;
	while(i<n){
		cout << a[i++];
	}

	return 1;
}
