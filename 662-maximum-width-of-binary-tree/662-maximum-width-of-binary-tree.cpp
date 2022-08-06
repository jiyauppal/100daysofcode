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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int k = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++){
                int curr = q.front().second-k;
                TreeNode* n = q.front().first;
                q.pop();
                if(i == 0) first = curr;
                if(i == size-1) last = curr;
                if(n->left) q.push({n->left, (long long)curr*2+1});
                if(n->right) q.push({n->right, (long long)curr*2+2});
                
            }
            ans = max(ans, last-first+1);
            
        }
        return ans;
    }
};