class Solution {
public:
    bool isSafe(int i, int j, vector<string>& ds, int n){
        // if row / col have any Q 
        int dupi = i;
        int dupj = j;
        while(i >= 0 && j >= 0){
            if(ds[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = dupi;
        j = dupj;
        while(i >= 0){
            if(ds[i][j] == 'Q')
                return false;
            i--;
        }
        i = dupi;
        j = dupj;
        while(j < n && i >= 0){
            if(ds[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void NQueens(vector<vector<string>>& results, int n, int col, vector<string>& ds){
        if(col == n){
            results.push_back(ds);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(col, row, ds, n)){
            ds[col][row] = 'Q';
            NQueens(results, n, col+1, ds);
            ds[col][row] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> ds(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            ds[i] = s;
        }
        NQueens(results, n, 0, ds);
        return results;
    }
};