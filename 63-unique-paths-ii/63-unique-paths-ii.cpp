class Solution {
public:
    int pathWithoutObstacles(vector<vector<int>>& G, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(G[i][j]) return dp[i][j] = 0; 
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = pathWithoutObstacles(G, i+1, j, m, n, dp) + pathWithoutObstacles(G,i, j+1, m, n, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        int m = G.size();
        int n = G[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return pathWithoutObstacles(G, 0, 0, m, n, dp);
    }
};