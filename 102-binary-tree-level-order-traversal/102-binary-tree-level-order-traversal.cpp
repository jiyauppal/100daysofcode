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
    vector<vector<int>> solve(vector<TreeNode*> &k, TreeNode* root, vector<vector<int>> &res){
        if(k.size() == 0) return res;
        
        vector<TreeNode* > newK;
        vector<int> ans;
        for(int i = 0; i < k.size(); i++){
            ans.push_back(k[i]->val);
            if(k[i]->left) newK.push_back(k[i]->left);
            if(k[i]->right) newK.push_back(k[i]->right);
        }
        res.push_back(ans);
        return solve(newK, root, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode* > k;
        k.push_back(root);
        return solve(k, root, res);
    }
};