#include <stdio.h>
#include <algorithm> 
#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > vec;
    
    std::sort(nums.begin(), nums.end());
	for(int i=0;i<nums.size()-2;i++){
	    int st = i+1, end = nums.size() - 1;
	    
	    int sum = nums[i] * -1;
	    while(st < end){
	        if(nums[st] + nums[end] > sum) end--;
	        else if(nums[st] + nums[end] < sum) st++;
	        
	        else{
	            vector<int> t;
	            t.push_back(nums[i]);
	            t.push_back(nums[st]);
	            t.push_back(nums[end]);
	            vec.push_back(t);
	            st++;
	            end--;
	        } 
	    }
    }

    return vec;
}

void addNumbers(string num, int l1, int l2, char* c){
    int len = max(l1,l2)+1;
    
    int endIndex = len;
    char d[len-1];
    d[len-1] = '\0';
    c[len] = '\0';
    
    int size = num.size();
    char s[size];
    strcpy(s, num.c_str());
 
    char s1[l1], s2[l2], left[len];
    
    strncpy(s1, s, l1);
    strncpy(s2, s+l1, l2);
    // int l = min(l1,l2);
    
    cout << s1 << " " << s2 << endl;
    int sum;
    int car = 0;
    while(l1>0 && l2>0){
        sum = s1[--l1]-48 + s2[--l2]-48 + car;
        // cout << sum << endl;
        c[--len] = sum%10+48;
        car = sum/10;
    }

	// cout << c << endl;    
    if(l1 > 0)
        strncpy(left, s1, l1+1);
    else if(l2 > 0)
        strncpy(left, s2, l2+1);
    
    int l = strlen(left);
    while(l>0){
        sum = left[--l]-48 + car;
        c[--len] = sum%10+48;
        car = sum/10;
    }
    // cout << c << endl;
    if(len>0) {
        strncpy(d, c+1, endIndex);
        cout << d << endl;
    }
    // return c;
}

char mapping[7][4] = {{'0'}, {'1'}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},
{'m','n','o'}};


void permutation(string A, int len, int index, char *comb){
    if(index == len){
        cout << comb << endl;
        return;
    }
    char num = A[index];
    int n = num-48;
    char *arr = mapping[n];
    int size = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<size; i++){
        comb[index] = arr[i];
        cout << index << endl;
        permutation(A, len, index+1, comb);

    }
    return;
}


int main(){
	string A = "23";
    char comb[A.size()];
    permutation(A, A.size(), 0, comb);
    	// string a = "123456";
	// char d[3];
	// addNumbers(a,2,2,d);
	// cout << d << endl;

	// int *a;
	// a = new int[10];
	// cout << sizeof(a) << endl;
	// cout << sizeof(a[0]);
// char mapping[7][5] = {{'0'}, {'1'}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},
// {'m','n','o'}};

// 	for(int i=0;i<7;i++){
// 		vector<char> v = 
// 	}
//   	std::vector<vector<char> > vec (mapping, mapping+7);

  	// cout << vec[5] << endl;
  	// vec.insert(vec.begin()+2, 2);
  	// cout << vec[5] << endl;
  	// cout << max(1,2,3);
  // 	int i = 0;
  // 	while(i<6){
  // 		cout << vec[i]<<endl;
  // 		vec.erase(vec.begin());
  // 	}
	// char a[10] = "fjdafdaf";
	// cout << a << endl;
	// char b[2];
	// b[2] = '\0';
	// b[1] = '1';
	// // strncpy(b,a+2,2);
	// // b[2] = '\0';
	// // cout << b << endl;
	
	// char c[] = b;
	// puts(c);
 //  	std::vector<int> vec;
 // //  	vec.push_back(-1);
	// // vec.push_back(0);
	// // vec.push_back(1);
	// // vec.push_back(2);
	// // vec.push_back(-1);
	// // vec.push_back(-4);

	// std::sort(vec.begin(),vec.end());

 //    vector<vector<int> > v;
	// v = threeSum(vec);

	// vector<int> ve;
	// if(v.size() == 0) v.push_back(ve);


	// for(int i=0;i<v.size();i++){
	// 	for(int j=0;j<3;j++)
	// 		cout << v[i][j] << " ";
	// 	cout << endl;
	// }


	return 1;
}
