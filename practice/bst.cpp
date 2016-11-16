#include <iostream>

using namespace std;


struct bst{
	int num;
	bst *left;
	bst *right;
	bst(int n): num{n}, left{nullptr}, right{nullptr} {}
};

bst* insert(bst *t, int num){
	if(t == nullptr){
		bst *l = new bst(num);
		return l;
	}
	if(t->num > num){
		t->left = insert(t->left, num);
	}	
	else{
		t->right = insert(t->right, num);
	}
	return t;
}

void print(bst *t){
	if(t == nullptr) return;
	print(t->left);
	cout << t->num << ", ";
	print(t->right);
}


int main()
{
	bst *t;
	t = nullptr;

	t = insert(t, 4);
	t = insert(t, 2);
	t = insert(t, 6);
	t = insert(t, 1);
	t = insert(t, 3);
	t = insert(t, 5);
	t = insert(t, 7);

	print(t);

	
}