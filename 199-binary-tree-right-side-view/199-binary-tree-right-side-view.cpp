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
    vector<int> solve(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return ans; 
        if(ans.size() == level) ans.push_back(root->val);
          ans = solve(root->right, level+1, ans);
        ans = solve(root->left , level + 1, ans);       
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans = solve(root, 0, ans);
        return ans;
    }
};