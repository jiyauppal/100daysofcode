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
    private:
    int curr_sum = 0;
public:
    void addingrightsubtree(TreeNode* root){
            if(!root)
                return;
            if(root->right)
            addingrightsubtree(root->right);
            root->val = (curr_sum += root->val);
            if(root->left)
            addingrightsubtree(root->left);
        }
    
    TreeNode* convertBST(TreeNode* root) {
            addingrightsubtree(root);
        return root;
    }
};