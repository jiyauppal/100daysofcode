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
    bool isValid(TreeNode* root, long mn, long mx){
        if(!root) return true;
        
        if(root->val >= mx || root->val <= mn ){
            return false;
        }
           bool l = isValid(root->left, mn, root->val);
           bool r = isValid(root->right, root->val, mx);
        
        return l&&r;
    }
    bool isValidBST(TreeNode* root) {
         bool ans = isValid(root, LONG_MIN, LONG_MAX);
        return ans;
    }
};