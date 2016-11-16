#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 
int binary_search(vector<int> &inorder, int start, int end, int val){
    cout <<"val = " << val << endl;
    int mid = (start+end)/2;
    
    if(inorder[mid] == val) return mid;
    else if(inorder[mid] > val)
        binary_search(inorder, start, mid-1, val);
    else
        binary_search(inorder, mid+1, end, val);
}

TreeNode* constructTree(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2) {
    if(s1>e1) return NULL;
    
    TreeNode* node = new TreeNode(postorder[e2]);
    
    cout << "Here" << endl;
    int index = binary_search(inorder, s1, e1, postorder[e2]);
    
    cout<<"Index = " << index << endl;

    node->left = constructTree(inorder, s1, index-1, postorder, s2, index-1);
    node->right = constructTree(inorder, index+1, e1, postorder, index, e2-1);
    return node;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int len = inorder.size();
    return constructTree(inorder, 0, len-1, postorder, 0, len-1);
}

void print(TreeNode *t){
    if(t == nullptr) return;
    cout << t->val << ", ";
    print(t->left);
    print(t->right);
}


int main()
{
    int numbers1[] = {7, 5, 6, 2, 3, 1, 4};
    std::vector<int> v1 (numbers1, numbers1 + sizeof(numbers1) / sizeof(int));

    int numbers2[] = {5, 6, 3, 1, 4, 2, 7};
    std::vector<int> v2 (numbers2, numbers2 + sizeof(numbers2) / sizeof(int));

    print(buildTree(v1, v2));
    return 1;
}