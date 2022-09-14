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
    void NQueens(vector<vector<string>>& results, int n, int i, vector<string>& ds){
        if(i == n){
            results.push_back(ds);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(i, j, ds, n)){
            ds[i][j] = 'Q';
            NQueens(results, n, i+1, ds);
            ds[i][j] = '.';
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