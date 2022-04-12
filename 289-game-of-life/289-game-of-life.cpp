class Solution {
public:
    int m, n;
    bool isLive(int status){
        return status == 1;
    }
    int checkCount(int i, int j, vector<vector<int>>& board){  // utility function to keep the count of live neighours
        int count = 0;
        
        count += i-1 >=0 && board[i-1][j] ? 1 : 0;
        count += i+1 < m && board[i+1][j] ? 1 : 0;
        count += j-1 >=0 && board[i][j-1] ? 1 : 0;
        count += j+1 < n && board[i][j+1] ? 1 : 0;
        count += i-1 >=0 && j-1 >= 0 && board[i-1][j-1] ? 1 : 0;
        count += i-1 >=0 && j+1 < n && board[i-1][j+1] ? 1 : 0;
        count += i+1 < m && j-1 >= 0 && board[i+1][j-1] ? 1 : 0;
        count += i+1 < m && j+1 < n && board[i+1][j+1] ? 1 : 0;
        
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        int count;
        vector<vector<int>> tempboard = board;  // keeping a temporary so that no final changes are made during each testcase.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count = checkCount(i, j, tempboard);
                if(isLive(board[i][j])){
                    if(count < 2 || count > 3)  // applying condition for live neighours
                        board[i][j] = 0;
                }
                else{
                    board[i][j] = count == 3 ? 1 : 0; // applying condition for dead neighours
                }
            }
        }
    }
};