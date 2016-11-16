#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void perm(vector<int> v, int index, int len){
	if(index == len){
		for(int j=0;j<len;j++) cout << " " << v[j];
		cout << endl;
		return;
	}

	for(int i=index; i < len; i++){
		swap(&v[i],&v[index]);
		perm(v,index+1,len);
		swap(&v[i],&v[index]);
	}
	return;
}

int main(){
	int weights[] = {1,2,3};

	std::vector<int> v (weights, weights + sizeof(weights) / sizeof(int));

	int len = v.size();

	perm(v, 0, len);
	return 1;
}