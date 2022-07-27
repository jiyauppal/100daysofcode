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
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right); //max height of binary tree code snipet
        return 1+ max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh) > 1) return false;   
        
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!l || !r) return false;
        return true;
    }
};