class Solution {
public:
    void helper(int i, int j, vector<vector<int>>& dp, vector<vector<char>>& grid, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return ;
        grid[i][j] = '0';
        helper(i+1, j, dp, grid, m, n);
        helper(i-1, j, dp, grid, m, n);
        helper(i, j+1, dp, grid, m, n);
        helper(i, j-1, dp, grid, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    helper(i, j, dp, grid, m, n);
                }
            }
        }
        return ans;
    }
};