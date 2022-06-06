class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        bool dp[n+1][sum+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]]||dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i = 0; i <nums.size(); i++)
            s += nums[i];
        if(s % 2 != 0)
            return false;
        else
            return subsetSum(nums, s/2);
    }
};