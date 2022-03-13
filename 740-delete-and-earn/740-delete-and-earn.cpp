class Solution {
public:
int dp[10005] = { -1};

    int solve(int i, vector<int> &arr, int &N) {
        if (i >= N) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = max(solve(i + 1, arr, N), i * arr[i] + solve(i + 2, arr, N));

        return dp[i] = ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        int MAX = 0; int n = nums.size();
        for (int i = 0; i  < nums.size(); i++) MAX = max(MAX, nums[i]);

        vector<int> arr(MAX + 1, 0);
        int N = arr.size();
        for (int i = 0; i  < n; i++) arr[nums[i]]++;


        memset(dp, -1, sizeof(dp));
        return solve(0, arr, N);

    }
};