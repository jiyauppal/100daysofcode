class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int m, int n, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if(grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool d1 = dfs(grid, m, n, i-1, j);
        bool d2 = dfs(grid, m, n, i+1, j);
        bool d3 = dfs(grid, m, n, i, j-1);
        bool d4 = dfs(grid, m, n, i, j+1);
        return d1 && d2 && d3 && d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    ans += dfs(grid, m, n, i, j) ? 1 : 0;
            }
        }
        return ans;
    }
};