class Solution {
public:
    void subsets(vector<vector<int>>& res, vector<int>& ans, vector<int>& nums, int start){
        res.push_back(ans);
        for(int i = start; i != nums.size(); ++i)
            if(i == start || nums[i] != nums[i-1]){
                ans.push_back(nums[i]);
                subsets(res, ans, nums, i+1);
                ans.pop_back();
            } 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        subsets(res, ans, nums, 0);
        return res;
    }
};