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
    vector<TreeNode*> recFun(int start, int end){
        if(start > end) return { nullptr };
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i){
            for(TreeNode * left : recFun(start, i-1)){
                for(TreeNode* right : recFun(i+1, end)){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return recFun(1, n);
    }
};