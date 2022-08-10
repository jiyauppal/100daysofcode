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
    TreeNode* helper(vector<int>& num, int low, int high){
    if(low <= high){
            int mid = low + (high-low)/2;
            TreeNode* ans = new TreeNode(num[mid]);
            ans->left = helper(num, low, mid-1);
            ans->right = helper(num, mid+1, high);
            return ans;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& num) {
        return helper(num, 0, num.size()-1);
    }
};