#include <iostream>
using namespace std;

void binary(int i, int len, char *a){
	if(i == len){
		for(int j=0;j<len;j++)
			cout << a[j];
		cout << endl;
		return;
	}

	a[i] = '0';
	binary(i+1, len, a);

	a[i] = '1';
	binary(i+1, len, a);
	return;
}

int main(){
	char a[3];
	binary(0, 3, a);
	return 1;
}