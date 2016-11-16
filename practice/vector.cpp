#include <iostream>
#include <vector>

using namespace std;


vector<int> merge(vector<int> left, vector<int> right, int &count){

    int len1 = left.size(), len2 = right.size();
    int len = len1;

    int ptr1 = 0, ptr2 = 0;
    vector<int> c;

    while(ptr1 < len1 && ptr2 < len2){
        if(right[ptr2] < left[ptr1]){
            count += len;
            c.push_back(right[ptr2++]);
        }
        else{
            c.push_back(left[ptr1++]);
            len--;
        }
    }
 
    if(ptr1 == len1){
    	while(ptr2 < len2){
			c.push_back(right[ptr2++]);
    	}
    }
    else{
    	while(ptr1 < len1){
			c.push_back(left[ptr1++]);
    	}
    }

    return c;
}

void print(vector<int> c){
	for(int i=0;i<c.size();i++) cout << c[i] << " ";
	cout << endl;
}

vector<int> mergeSort(vector<int> &A, int left, int right, int &count){
    if(left == right){
    	vector<int> t;
    	t.push_back(A[left]);
    	return t;	
    } 
    int mid = (left + right)/2;
    
    vector<int> l = mergeSort(A, left, mid, count);
    vector<int> r = mergeSort(A, mid+1, right, count);
    
    vector<int> c = merge(l, r, count);
    return c;
}

int main()
{
    int numbers[] = {1,2,3,4,5};
    std::vector<int> v (numbers, numbers + sizeof(numbers) / sizeof(int));

    for(int i=0;i<v.size();i++){
        v.erase(v.begin());
    }

    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    
    
    // int count = 0;
    // mergeSort(v, 0, v.size() - 1, count);
    // cout << count << endl;

    return 1;
}