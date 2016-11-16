#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void perm(std::vector<int> v, int *b, int index, int c, int k, int len, int *max){
	if(index == k){
		for	(int j=1;j<k;j++){
			if(b[j] < b[j-1]) return;
		}
		*max = k;
		for	(int j=0;j<k;j++) cout << b[j] << " ";
		cout << endl;
		return;
	}

	for	(int i=c;i<len;i++){
		b[index] = v[i];
		c = i;
		perm(v,b,index+1,c+1,k,len,max);
	}
	return;
}

int main(){
	int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };

	std::vector<int> v (a, a + sizeof(a) / sizeof(int));

	int len = v.size();

	int max = 0;
	for	(int i=1;i<len;i++){
		int b[i];
		perm(v, b, 0, 0, i, len, &max);
	}

	cout << max << endl;

	return 1;
}