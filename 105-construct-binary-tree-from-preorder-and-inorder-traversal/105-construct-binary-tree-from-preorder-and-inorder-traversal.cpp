/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right){
        if(left > right) return NULL;
        int pivot = left;
        while(inorder[pivot] != preorder[idx]) pivot++;
        
        idx++;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root->left = helper(preorder, inorder, idx, left, pivot-1); 
        root->right = helper(preorder, inorder, idx, pivot+1, right); 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = inorder.size();
        return helper(preorder, inorder, idx, 0, n-1);
    }
};