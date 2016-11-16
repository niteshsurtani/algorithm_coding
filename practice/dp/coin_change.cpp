#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void change(vector<int> v, int len, int c, int sum, int *count){
	if(sum < 0) return;
	else if(sum == 0) {
		// cout << " HERE " << endl;
		*count += 1;
		return;
	}

	for(int i=c; i<len; i++){
		// cout << sum << endl;
		change(v, len, c, sum-v[i], count);
		c = i + 1;
	}
	return;
}

int main(){
	int coin[] = {2, 5, 3, 6};

	std::vector<int> v (coin, coin + sizeof(coin) / sizeof(int));

	int len = v.size();
	int sum = 10;
	int count = 0;

	change(v, len, 0, sum, &count);
	cout << count << endl;
	return 1;
}