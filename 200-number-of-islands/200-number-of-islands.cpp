class Solution {
public:
    void nextIsland(vector<vector<char>>& grid, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        nextIsland(grid, m, n, i+1, j);
        nextIsland(grid, m, n, i-1, j);
        nextIsland(grid, m, n, i, j-1);
        nextIsland(grid, m, n, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    nextIsland(grid, m, n, i, j);
                }
            }
        }
        
        return islands;
    }
};