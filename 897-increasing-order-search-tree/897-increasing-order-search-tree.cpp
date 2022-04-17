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
    void removingLeftChild(TreeNode* root, TreeNode*& ans){
        if(!root) return;
        removingLeftChild(root->left, ans);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        
        removingLeftChild(root->right, ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        TreeNode* temp;
        temp = ans;
        removingLeftChild(root, ans);
        return temp->right;
    }
};