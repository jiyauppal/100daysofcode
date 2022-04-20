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
    void inorder(TreeNode* root, int k, int* res){
        if(!root) return;
        inorder(root->left, k, res);
        res[0] += 1;
        if(res[0] == k){
            res[1] = root->val;
            return;
        }
        inorder(root->right, k, res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int res[] = { 0, -1};
        inorder(root, k, res);
        return res[1];
    }
};