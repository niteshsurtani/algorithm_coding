#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void sort012(int *a, int n){
	int ptr0=0,ptr1=0,ptr2=n-1;

	while(ptr1 <= ptr2){
		while(ptr1 <= ptr2 && a[ptr1] != 2){
			if(a[ptr1] == 0){
				swap(&a[ptr0],&a[ptr1]);
				ptr0++;
			}
			ptr1++;
		}
		while(ptr1 <= ptr2 && a[ptr2] == 2){
			ptr2--;
		}
		if(ptr1 <= ptr2){			
			swap(&a[ptr1],&a[ptr2]);
			if(a[ptr1] == 1) ptr1++;
			ptr2--;
		}
	}
}

void printArray(int *a,int n){
	int i=0;
	while(i<n) cout << a[i++];
	cout << endl;
}

int main(){
	int i=0,n;
	cin >> n;
	int a[n];
	while(i<n) cin >> a[i++];
	// cout << a[n-1];

	int x=1,y=2;
	swap(&x,&y);
	// cout << x << " " << y << endl;

	cout << "Before Sorting\n";
	printArray(a,n);
	sort012(a,n);
	cout << "After Sorting\n";
	printArray(a,n);
	
	return 1;
}