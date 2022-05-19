class Solution {
public:
    bool checkLimits(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j <n);
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(!checkLimits(i, j, m, n))
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
        if(checkLimits(i+1, j, m, n) && matrix[i+1][j] > matrix[i][j])
            c0 = dfs(matrix, i+1, j, m, n, dp);
        if(checkLimits(i-1, j, m, n) && matrix[i-1][j] > matrix[i][j])
            c1 = dfs(matrix, i-1, j, m, n, dp);
        if(checkLimits(i, j+1, m, n) && matrix[i][j+1] > matrix[i][j])
            c2 = dfs(matrix, i, j+1, m, n, dp);
        if(checkLimits(i, j-1, m, n) && matrix[i][j-1] > matrix[i][j])
            c3 = dfs(matrix, i, j-1, m, n, dp);
        dp[i][j] = 1 + max(c0, max(c1, max(c2, c3)));
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] = -1){
                ans = max(ans, dfs(matrix, i, j, m, n, dp));
                }
            }
        }
        
        return ans;
    }
};