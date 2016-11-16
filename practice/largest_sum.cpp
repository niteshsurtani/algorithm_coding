#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void sorting(std::vector<string> &vec, int k, int len, int start, int end){
    char character[end-start+1];

    // cout << "K = " << k << endl;
    // for(int i = start; i <= end; i++)
    //     cout << vec[i] << " ";
    // cout << endl;

    // cout << start << " " << end << endl;
    for(int i = start; i <= end; i++){
        if((k+1)<vec[i].length())
            character[i-start] = vec[i][k+1];
        else
            character[i-start] = vec[i][k];
    }

    // for(int i = start; i <= end; i++)
    //     cout << character[i-start] << " ";
    // cout << endl;
    
    for(int i=start;i<end;i++){
        int min = i;
        for(int j=i+1; j<=end;j++){
            if(character[j-start] < character[min-start]) min = j;
        }
        std::swap(character[i-start], character[min-start]);
        std::swap(vec[i], vec[min]);
    }
    
    // for(int i = start; i <= end; i++)
    //     cout << character[i-start] << " ";
    // cout << endl;

    // for(int i = start; i <= end; i++)
    //     cout << vec[i] << " ";
    // cout << endl;
}

string largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> vec;
    
    int len = A.size();
    

    int max_len = 0,c=0;
    int i,j,k;
    
    for(i=0;i<len;i++){
        std::string s = std::to_string(A[i]);
        vec.push_back(s);
        // cout << s.length() << endl;
        if(s.length() > max_len) max_len = s.length();
    }
    
    std::sort(vec.begin(), vec.end());
    // for(i=0;i<len;i++)
    //     cout << vec[i] << " ";
    // cout << endl;


    k = 0;
    while(k < max_len - 1){
        j = 1;
        int st_index = 0, en_index = 0;
        while(j < len){
            while(j < len && k < vec[j].length() && k < vec[j-1].length() && vec[j][k] == vec[j-1][k]){
                j++;
            }
            en_index = j-1;

            sorting(vec, k, len, st_index, en_index);
            st_index = j, en_index = j;
            j++;
        }
        k++;
    }

    for(i=len-1;i>=0;i--){
        cout << vec[i] << endl;
    }
    string str = "";

    for(i=len-1;i>=0;i--){
        str += vec[i];
    }

    return str;
}

int main(){
    int numbers[] = {9, 99, 999, 9999, 9998};
    std::vector<int> v (numbers, numbers + sizeof(numbers) / sizeof(int));

    int len = v.size();
    cout << len << endl;
    cout << largestNumber(v) << endl;    

    return 1;
}


