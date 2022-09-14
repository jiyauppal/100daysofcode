class Solution {
public:
    // bool isSafe(int row, int col, vector<string>& ds, int n){
    //     // if row / col have any Q 
    //     int dupi = col;
    //     int dupj = row;
    //     while(col >= 0 && row >= 0){
    //         if(ds[row][col] == 'Q')
    //             return false;
    //         col--;
    //         row--;
    //     }
    //     col = dupi;
    //     row = dupj;
    //     while(col >= 0){
    //         if(ds[row][col] == 'Q')
    //             return false;
    //         col--;
    //     }
    //     col = dupi;
    //     row = dupj;
    //     while(row < n && col >= 0){
    //         if(ds[row][col] == 'Q')
    //             return false;
    //         col--;
    //         row++;
    //     }
    //     return true;
    // }
    void NQueens(vector<vector<string>>& results, int n, int col, vector<string>& ds, vector<int>& left, vector<int>& lower, vector<int>& upper){
        if(col == n){
            results.push_back(ds);
            return;
        }
        for(int row = 0; row < n; row++){
            if(left[row] == 0 && lower[row+col] == 0 && upper[n-1+col-row] == 0){
                ds[row][col] = 'Q';
                left[row] = 1;
                lower[row+col] = 1;
                upper[n-1+col-row] = 1;
                NQueens(results, n, col+1, ds, left, lower, upper);
                ds[row][col] = '.';
                left[row] = 0;
                lower[row+col] = 0;
                upper[n-1+col-row] = 0;
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
        vector<int> left(n, 0);
        vector<int> lower(2*n-1, 0);
        vector<int> upper(2*n-1, 0);
        NQueens(results, n, 0, ds, left, lower, upper);
        return results;
    }
};