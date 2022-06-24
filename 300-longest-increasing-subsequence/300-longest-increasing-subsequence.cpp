class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 0; i < n ; i++){
                if(nums[i]>dp.back()){
                    dp.push_back(nums[i]);
                }
            else{
                int j = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[j] = nums[i];
            }
        }
        return dp.size();
    }
};