#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void permutation(vector<int> &A, int i, int len){
    if(i == len){
        for(int i=0; i<len;i++){
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }
        
    for(int j=i;j<len;j++){
        if(i == j || A[i] != A[j])
            std::swap(A[i], A[j]);
        else continue;
        // i++;
        permutation(A, i+1, len);
        std::swap(A[i], A[j]);
    }
    return;
}


int main(){
    int weights[] = {1,1,2,2};

    std::vector<int> v (weights, weights + sizeof(weights) / sizeof(int));

    int len = v.size();

    permutation(v, 0, len);
    return 1;
}