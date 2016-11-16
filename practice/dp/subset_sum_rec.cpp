#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void perm(vector<int> v, int *subset, int index, int c, int len, int k, int total){
	if(index == k){
		int sum = 0;
		
		for(int j=0;j<k;j++) sum+=subset[j];
		
		if(sum == total){
			for(int j=0;j<k;j++) cout << " " << subset[j];
			cout << endl;
		}
		return;
	}

	for(int i=c; i < len; i++){
		subset[index] = v[i];
		c = i;
		// cout << index << " -> " << v[i] << endl;
		perm(v,subset,index+1,c+1,len,k,total);
	}
	return;
}

int main(){
	int weights[] = {10, 7, 5, 18, 12, 20, 15};

	std::vector<int> v (weights, weights + sizeof(weights) / sizeof(int));
	std::sort(v.begin(), v.end());

	int len = v.size();
	int total = 35;

	for(int i=1; i<=len; i++){
		int subset[i];
		perm(v, subset, 0, 0, len, i, total);
	}
	return 1;
}