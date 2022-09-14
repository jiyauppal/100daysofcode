class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board, char k){
        for(int l = 0; l < 9; l++){
            if(board[l][j] == k)
                return false;
            if(board[i][l] == k)
                return false;
            if(board[3*(i/3) + l/3][3*(j/3) + l%3] == k)
                return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
         for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k++){
                    if(isValid(i, j, board, k)){
                        board[i][j] = k;
                        
                        if(solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                    return false;
            }
        }
     }
        return true;
    }
};