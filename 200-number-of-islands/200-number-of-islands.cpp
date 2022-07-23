class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int offsets[] = {0, 1, 0, -1, 0};
        int m = grid.size();
        int ans = 0;
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int> top = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int r = top.first + offsets[k];
                            int c = top.second + offsets[k+1];
                        if(r >= 0 && r < m && c >=0 && c <n && grid[r][c] == '1'){
                            grid[r][c] = '0';
                            q.push({r, c});
                        }}
                    }
                }
            }
        }
        
       return ans; 
    }
};