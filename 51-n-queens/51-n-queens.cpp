class Solution {
public:
    void dfs(int col, int n, vector<int>& l, vector<int>& u, vector<int>& ld, vector<vector<string>> &ans, vector<string>& board){
        if(col == n) {
        ans.push_back(board);
        return;}
        for(int i = 0; i < n; i++){
            if(l[i] == 0 && ld[i+col] == 0 && u[n-1+col-i] ==0){
                board[i][col] = 'Q';
                l[i] = 1;
                ld[i+col] = 1;
                u[n-1+col-i] = 1;
                dfs(col+1, n, l, u, ld, ans, board);
                board[i][col] = '.';
                l[i] = 0;
                ld[i+col] = 0;
                u[n-1+col-i] = 0;
            }
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;  //Resultant Matrix of string
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
            board[i] = s;
       vector<int> l(n, 0), u(2*n-1, 0), ld(2*n-1, 0);
        dfs(0, n, l, u, ld, ans, board);
        return ans;
    }
};