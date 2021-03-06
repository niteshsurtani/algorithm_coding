vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	
	int rowstart, rowend;
	int colstart, colend;
	
	rowstart = 0, rowend = A.size()-1;
	colstart = 0, colend = A[0].size()-1;
	
	while (rowstart <= rowend && colstart <= colend) {
	    for (int i = colstart; i <= colend; i++)
	        result.push_back(A[rowstart][i]);

	        
	    for (int i = rowstart+1; i <= rowend; i++)
	        result.push_back(A[i][colend]);
	        
	    for (int i = colend-1; i >= colstart && rowstart != rowend; i--) {
	        result.push_back(A[rowend][i]);
	    }
	
      	    for (int i = rowend-1; i > rowstart && colstart != colend; i--) {
                result.push_back(A[i][colstart]);
	    }
        
        
      	   rowstart++, rowend--;
     	   colstart++, colend--;
	}
	
	
	// DO STUFF HERE AND POPULATE result
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

