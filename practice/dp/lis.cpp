#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };

	std::vector<int> v (a, a + sizeof(a) / sizeof(int));

	int len = v.size();
	int lis[len];

	lis[0] = 1;

	for	(int i=1;i<len;i++){
		int max = 0;
		for(int j=i-1;j>=0;j--){
			if(a[i] >= a[j]){
				if(lis[j] > max) max = lis[j];
			}
		}
		lis[i] = max + 1;
	}

	int maximum = 0;
	for	(int i=0;i<len;i++) maximum = max(maximum, lis[i]);

	cout << maximum << endl;

	return 1;
}