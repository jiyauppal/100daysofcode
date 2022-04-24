class Solution {
public:
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >=n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int area = 1;
        area += dfs(grid, m, n, i-1, j);
        area += dfs(grid, m, n, i + 1, j);
        area += dfs(grid, m, n, i, j-1);
        area += dfs(grid, m, n, i, j+1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                ans = max(ans, dfs(grid, m, n, i, j));
                }
            }
        }
        return ans;
    }
};