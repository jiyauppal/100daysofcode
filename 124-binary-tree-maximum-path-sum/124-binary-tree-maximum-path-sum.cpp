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
    int helper(TreeNode* root, int& maxi){
        if(!root) return 0;
        int l = max(0, helper(root->left, maxi)); 
        int r = max(0, helper(root->right, maxi));
        maxi = max(maxi, root->val+l+r);  //path sum between more than 2 nodes
        return root->val + max(l, r); // path sum between two
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};