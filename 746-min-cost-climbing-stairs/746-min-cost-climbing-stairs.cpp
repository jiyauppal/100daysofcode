class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(3);
        for(int i = 2; i <=n; i++)
        {
            int onestep = dp[(i-1)%3] + cost[(i-1)];
            int twostep = dp[(i-2)%3] + cost[(i-2)];
            dp[i%3] = min(onestep, twostep);
        }
        return dp[n%3];
    }
};