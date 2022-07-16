class Solution {
public:
    long long mod = 1e9 + 7;
    int dp[55][55][55];
    int helper(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return  1; //base case
        if(maxMove <= 0) return 0;
        
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        int up = helper(m, n, maxMove-1, startRow+1, startColumn);
        int down = helper(m, n, maxMove-1, startRow-1, startColumn);
        int right = helper(m, n, maxMove-1, startRow, startColumn+1);
        int left = helper(m, n, maxMove-1, startRow, startColumn-1);
        return dp[startRow][startColumn][maxMove] = (up%mod + down%mod + left%mod + right%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};