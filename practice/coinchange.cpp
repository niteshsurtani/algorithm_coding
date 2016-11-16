#include <iostream>
#include <vector>

using namespace std;

int getVariation(vector<int> &A, int **arr,int i,int j){
    if(i-A[j-1] < 0) return 0;
    return arr[i-A[j-1]][j];
}

int coinchange2(vector<int> &A, int m) {
    int n = A.size();
    cout << n << endl;
    int **arr;
    arr = new int* [m+1];
    for(int i=0;i<=m;i++){
      arr[i] = new int [n+1];  
    }
    
    for(int i=0;i<=m;i++) arr[i][0] = 0;
    for(int i=0;i<=n;i++) arr[0][i] = 1;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            long long int sum = (arr[i][j-1] + getVariation(A, arr,i,j))%1000007;
            arr[i][j] = (int) sum;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr[m][n];
}

int main()
{
    int numbers[] = {18, 24, 23, 10, 16, 19, 2, 9, 5, 12, 17, 3, 28, 29, 4, 13, 15, 8};
    std::vector<int> v (numbers, numbers + sizeof(numbers) / sizeof(int));

    cout << coinchange2(v,458) << endl;

    return 1;
}