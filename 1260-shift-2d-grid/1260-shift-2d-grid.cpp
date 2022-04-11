class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int Total = m*n;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                    int flat1 = i * n + j;
                    int flat2 = (flat1 + k) %Total;
                
                    int nr = flat2 / n;
                    int nc = flat2 % n;
                    ans[nr][nc] = grid[i][j];
                }
        }
        return ans;
    }
};