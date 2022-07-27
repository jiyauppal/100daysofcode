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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+ max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxi = lh+rh;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        maxi = max(maxi, max(l, r));
        return maxi;
    }
};