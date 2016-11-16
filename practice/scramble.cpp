#include <iostream>
#include <vector>
#include <string>

using namespace std;

int scramble(string s1, string str, int len, int start, int end, int index, string s2){
	if(index == len){

	}
	for(int i = start; i < end; i++){
		string left = s1.substr(start,i-start+1);
		scramble(s1, start, i, s2);
		string right = s1.substr(i+1,end-i);
		scramble(s1, i+1, end, s2);

	}
}

int main()
{
	string s1 = "great", s2 = "rgtae";
	cout << scramble(s1,s2) << endl; 
    return 1;
}	


tree* balancedBst(vector<int> &v, int start, int end){
	if(end<start) return NULL;
	int mid = (start+end)/2;

	tree *node = new tree(v[mid]);
	node->left = balancedBst(node, v, start, mid-1);
	node->right = balancedBst(node, v, mid+1, end);
	return node;
}

void inorderIterative(tree *t){
	stack<tree *> s;
	s.push(t);
	
	while(!s.empty()){
		tree *node = s.top();
		s.pop();

		tree *left = node->left;
		tree *right = node->right;
		node->left = node->right = NULL;
		
		if(right) s.push(right);
		if(left == NULL){
			print(node);
		}
		else{
			s.push(node);
			s.push(left);
		}

		
	}
