#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
 
int find_idx(vector<int> &A, int left, int right, int key)
{
    for (int i = left; i <= right; i++)
        if (A[i] == key)
            return i;
}

TreeNode *build_tree (vector<int> &inorder, vector<int> &postorder, int left, int right, int &post_idx)
{
    if (left > right)
        return nullptr;
    
    TreeNode *curr = new TreeNode(postorder[post_idx--]);
    int mid = find_idx(inorder, left, right, curr->val);
    curr->right = build_tree(inorder, postorder, mid+1, right, post_idx);
    curr->left = build_tree(inorder, postorder, left, mid-1, post_idx);
    return curr;
}
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int post_idx = postorder.size()-1;
    return build_tree(inorder, postorder, 0, inorder.size()-1, post_idx);
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