class Solution {
public:
    int solve(string& word1, string& word2, vector<vector<int>>& dp, int i, int j){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, dp, i-1, j-1);
        else{
            return dp[i][j] = 1 + min(solve(word1, word2, dp, i-1, j-1), min(solve(word1, word2, dp, i-1, j), solve(word1, word2, dp, i, j-1)));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp (m, vector<int>(n, -1));
        return solve(word1, word2, dp,m-1, n-1);
    }
};