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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        int lvl = q.size();
            vector<int> curr_lvl;
        for(int i = 0; i < lvl; i++){
            auto top = q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            curr_lvl.push_back(top->val);
        }
        ans.push_back(curr_lvl);
        }
    return ans;
    }
};