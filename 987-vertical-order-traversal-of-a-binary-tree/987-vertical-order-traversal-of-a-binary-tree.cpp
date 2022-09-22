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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q; 
        q.push({root, {0, 0}}); // root, l, v
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            TreeNode* n = temp.first;
            int l = temp.second.first;
            int v = temp.second.second;
            
            mp[l][v].insert(n->val);
            
            if(n->left) 
                q.push({n->left, {l-1, v+1}});
            if(n->right) 
                q.push({n->right, {l+1, v+1}});
        }
        for(auto i : mp){
            vector<int> t;
            for(auto j : i.second){
                t.insert(t.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(t);
        }
        return ans;
    }
};