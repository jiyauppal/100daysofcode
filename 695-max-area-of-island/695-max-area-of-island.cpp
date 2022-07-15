class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >=m || grid[i][j] == 0) return 0; //checking boundaries
        grid[i][j] = 0; //marking visited
        int area = 1; //1 because it can't be less than that
        area += dfs(i+1, j, grid, n, m);
        area += dfs(i-1, j, grid, n, m);
        area += dfs(i, j+1, grid, n, m);
        area += dfs(i, j-1, grid, n, m);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(i, j, grid, n, m)); // max out of every area
                }
            }
        }
        return ans;
    }
};