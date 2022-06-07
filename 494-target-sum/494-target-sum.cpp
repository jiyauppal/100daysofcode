class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
         if (n == 1) 
            return abs(nums[0]) == abs(target);
        
        int s = 0;
        for(auto i: nums)
            s += i;
        
        int sum = (target + s)/2;
        
        if ((s + target) % 2 == 1 || abs(s) < abs(target))
            return 0;
        
        int dp[n+1][sum+1];

        for(int i = 0; i < n+1; i++)
            dp[i][0] = 1;
            for(int j = 1; j < sum+1; j++)
                dp[0][j] = 0;
            
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};