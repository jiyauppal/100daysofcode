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
    int max_sum(TreeNode* root, int& sum){
        if(!root) return 0;
        int lh = max(0, max_sum(root->left, sum));
        int rh = max(0, max_sum(root->right, sum));
        int val = root->val;
        sum = max(sum, rh+lh+val);

        return max(lh, rh)+val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        max_sum(root, sum);
        return sum;
    }
};