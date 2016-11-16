string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> prev, latest;
    
    
    int len = A.size();
    int max_len = 0,c=0;
    int i,j,k;
    
    for(i=0;i<len;i++){
        std::string s = std::to_string(A[i]);
        prev.push_back(s);
        // cout << s.length() << endl;
        if(s.length() > max_len) max_len = s.length();
    }
    
    std::sort(prev.begin(), prev.end());
    
    
    // cout << prev[0] << endl;
    char prev_char, digit;
    
    
    vector<char> digits;
    vector<char> prev_digits;
    
    
    // cout << prev[0] << prev [1] << endl;
    while(c<max_len){
        cout << c << endl;
        int start=0, end=0;
        for(i=0;i<len;i++){
            cout << prev[i]) << " ";
            // if(c>prev[i].length()) digits.push_back(prev[i].at(0));
            // else{
            //     cout << "HERE" << endl;
            //     digits.push_back(prev[i].at(c));
            } 
        }
        
        
        while(end<len){
            if(c==0){
                start = 0;
                end = len;
            }
            else{
                start = end;
                
                prev_char = prev_digits[start];
                while(prev_digits[end] == prev_char){
                    end++;
                }
            }
            // Sort function
            // cout << " HERE " << endl;
            for(j=start + 1;j<end;j++){
                char temp = digits[j];
                string tempStr = prev[j];
                
                for(k=j-1;k>=0;k--){
                    if(digits[k] < temp){
                        // swap digits and corresponding vector elements
                        digits[k+1] = digits[k];
                        prev[k+1] = prev[k];
                    }
                    else break;
                }
                digits[k+1] = temp;
                prev[k+1] = tempStr;
                
            }
        }
        prev_digits = digits;
        digits.clear();
        for(i=0;i<len;i++){
            cout << prev_digits[i] << " ";
        }
        cout << endl;
        for(i=0;i<len;i++){
            cout << prev[i] << " ";
        }
        cout << endl;
        c++;
    }
    // cout << prev[0] << endl;
    string str = "";
    for(i=0;i<len;i++){
        str += prev[i];
    }
    return str;
}
